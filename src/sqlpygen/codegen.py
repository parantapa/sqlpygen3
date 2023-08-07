"""Code generation."""

import sys
import importlib.util
from pathlib import Path

import click
import jinja2
import rich

from .parse_tree import get_parser
from .ast import ParsedSQL, make_ast, make_concrete_source, ASTConstructionError


def sqlite3_parameterized_query(sql: ParsedSQL) -> str:
    params = {v: f":{v}" for v in sql.vars}
    return sql.sql_template.format(**params)


def run_explain_queries(fname: Path):
    spec = importlib.util.spec_from_file_location("_generated_module", fname)
    assert spec is not None
    module = importlib.util.module_from_spec(spec)
    sys.modules["_generated_module"] = module
    assert spec.loader is not None
    spec.loader.exec_module(module)
    module.explain_queries()


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
def make_sqlite3_module(ofname: Path | None, filename: Path):
    loader = jinja2.PackageLoader("sqlpygen")
    env = jinja2.Environment(
        loader=loader,
        undefined=jinja2.StrictUndefined,
        trim_blocks=True,
        lstrip_blocks=True,
    )
    env.filters["parameterized_query"] = sqlite3_parameterized_query
    template = env.get_template("sqlite3.jinja2")

    file_bytes = filename.read_bytes()

    rich.print(f"[cyan]Parsing input file[/cyan]: {str(filename)}")

    parser = get_parser()
    parse_tree = parser.parse(file_bytes)
    if parse_tree.root_node.has_error:
        rich.print("[red]Failed to parse input[/red]")
        sys.exit(1)

    try:
        source = make_ast(parse_tree.root_node)
    except ASTConstructionError as e:
        rich.print(f"[red]{e}[/red]")
        sys.exit(1)

    source = make_concrete_source(source)

    if ofname is None:
        ofname = Path(f"{source.module}.py")
    rich.print(f"[cyan]Writing output to[/cyan]: {str(ofname)}")

    ofname.write_text(
        template.render(
            module=source.module,
            schemas=source.schemas,
            queries=source.queries,
            tables=source.tables,
            source_file=filename,
        )
    )

    rich.print("[cyan]Executing explain queries[/cyan]")
    run_explain_queries(ofname)

    rich.print(f"[green]Module {source.module} generated successfully.[/green]")
