"""Code generation."""

from pathlib import Path

import click
import jinja2

from .parse_tree import get_parser
from .ast import ParsedSQL, make_ast, make_concrete_source, ASTConstructionError


def sqlite3_param(sql: ParsedSQL) -> str:
    params = {v: f":{v}" for v in sql.vars}
    return sql.sql_template.format(**params)


@click.command()
@click.argument(
    "filename",
    type=click.Path(exists=True, file_okay=True, dir_okay=False, path_type=Path),
)
def make_sqlite3_module(filename: Path):
    loader = jinja2.PackageLoader("sqlpygen")
    env = jinja2.Environment(
        loader=loader,
        undefined=jinja2.StrictUndefined,
        trim_blocks=True,
        lstrip_blocks=True,
    )
    env.filters.update(dict(sqlite3_param=sqlite3_param))
    template = env.get_template("sqlite3.jinja2")

    file_bytes = filename.read_bytes()

    parser = get_parser()
    parse_tree = parser.parse(file_bytes)
    if parse_tree.root_node.has_error:
        print("Failed to parse input")
        return 1

    try:
        source = make_ast(parse_tree.root_node)
    except ASTConstructionError as e:
        print(e)
        return

    source = make_concrete_source(source)
    print(
        template.render(
            module=source.module,
            schemas=source.schemas,
            queries=source.queries,
            tables=source.tables,
            source_file=filename,
        )
    )
