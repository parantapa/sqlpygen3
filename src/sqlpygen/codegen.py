"""Code generation."""

import sys
from pathlib import Path
import importlib.util

import click
import jinja2
import rich

from .errors import ErrorType, capture_errors, append_error, print_errors
from .parse_tree import check_parse_errors, get_parser
from .ast import (
    ParsedSQL,
    make_ast,
    make_concrete_source,
    ConcreteSource,
)


def sqlite3_parameterized_query(sql: ParsedSQL) -> str:
    params = {v: f":{v}" for v in sql.vars}
    return sql.sql_template.format(**params)


def get_sqlite3_env() -> jinja2.Environment:
    loader = jinja2.PackageLoader("sqlpygen")
    env = jinja2.Environment(
        loader=loader,
        undefined=jinja2.StrictUndefined,
        trim_blocks=True,
        lstrip_blocks=True,
    )
    env.filters["parameterized_query"] = sqlite3_parameterized_query
    return env


def sql_test_sqlite3(source: ConcreteSource, verbose: bool) -> bool:
    env = get_sqlite3_env()
    template = env.get_template("sql_test_sqlite3.py.jinja2")
    gen_source = template.render(
        module=source.module,
        schemas=source.schemas,
        queries=source.queries,
        tables=source.tables,
    )

    module_name = f"_sql_test_sqlite3_{source.module}"
    spec = importlib.util.spec_from_loader(module_name, loader=None)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    try:
        exec(gen_source, module.__dict__)
    except Exception:
        print("Failed to generate test module.")
        if verbose:
           print(gen_source)
        raise
    sys.modules[module_name] = module

    errors: list[tuple[str, str, str]]
    errors = module.sql_test(verbose)
    for sql_type, name, error_str in errors:
        match sql_type:
            case "schema":
                schema = source.schemas_dict[name]
                append_error(ErrorType.BadSQLSchema, error_str, schema.sql.node)
            case "query":
                query = source.queries_dict[name]
                append_error(ErrorType.BadSQLQuery, error_str, query.sql.node)
            case _:
                raise ValueError(f"Unexpected SQL type: {sql_type}")

    return bool(errors)


def sql_test(source: ConcreteSource, verbose: bool) -> bool:
    if source.dialect.text == "sqlite3":
        return sql_test_sqlite3(source, verbose)

    raise ValueError(f"Unknown dialect: {source.dialect}")


@click.command()
@click.option(
    "-o",
    "--output",
    "ofname",
    type=click.Path(exists=False, file_okay=True, dir_okay=False, path_type=Path),
    default=None,
    help=(
        "Output file name. "
        "Default value is '{module}'.py "
        "Where module is taken from the input file."
    ),
)
@click.argument(
    "filename",
    type=click.Path(exists=True, file_okay=True, dir_okay=False, path_type=Path),
)
def compile(ofname: Path | None, filename: Path):
    """Compile a .sqlpygen file to .py file."""
    env = get_sqlite3_env()
    template = env.get_template("sqlite3.py.jinja2")

    file_bytes = filename.read_bytes()

    parser = get_parser()
    with capture_errors() as errors:
        parse_tree = parser.parse(file_bytes)
        check_parse_errors(parse_tree.root_node)
        if errors:
            rich.print("[red]Failed to parse input[/red]")
            print_errors(errors, file_bytes, filename)
            sys.exit(1)

    with capture_errors() as errors:
        source = make_ast(parse_tree.root_node)
        if errors:
            rich.print("[red]Input contains errors[/red]")
            print_errors(errors, file_bytes, filename)
            sys.exit(1)

    source = make_concrete_source(source)

    with capture_errors() as errors:
        sql_test_sqlite3(source, verbose=True)
        if errors:
            rich.print(f"[red]SQL test failed[/red]")
            print_errors(errors, file_bytes, filename)
            sys.exit(1)

    if ofname is None:
        ofname = Path(f"{source.module}.py")
    rich.print(f"[cyan]Writing output to[/cyan]: {str(ofname)}")

    ofname.write_text(
        template.render(
            module=source.module,
            dialect=source.dialect,
            schemas=source.schemas,
            queries=source.queries,
            tables=source.tables,
            source_file=filename,
        )
    )

    rich.print(f"[green]Module {source.module} generated successfully.[/green]")
