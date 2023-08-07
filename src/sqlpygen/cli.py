"""Command line interface."""

from pathlib import Path

import rich
import click

from .parse_tree import print_parse_tree
from .ast import print_initial_ast, print_final_ast
from .language_server import language_server
from .codegen import make_sqlite3_module

from .tree_sitter_bindings import get_parser
from .parse_tree import check_parse_errors
from .ast import make_ast
from .errors import print_errors, capture_errors


@click.group()
def cli():
    """SqlPyGen: Generate Python functions from annotated SQL."""


cli.add_command(print_parse_tree)
cli.add_command(print_initial_ast)
cli.add_command(print_final_ast)
cli.add_command(language_server)
cli.add_command(make_sqlite3_module)


@cli.command()
@click.argument(
    "filename",
    type=click.Path(exists=True, file_okay=True, dir_okay=False, path_type=Path),
)
def check_for_errors(filename: Path):
    """Check for errors."""

    file_bytes = filename.read_bytes()

    parser = get_parser()
    parse_tree = parser.parse(file_bytes)
    if parse_tree.root_node.has_error:
        with capture_errors() as errors:
            check_parse_errors(parse_tree.root_node)

            rich.print("[red]Error parsing file.[/red]")
            print_errors(errors, file_bytes, filename)
            return

    with capture_errors() as errors:
        make_ast(parse_tree.root_node)

        if errors:
            rich.print("[red]Error parsing file.[/red]")
            print_errors(errors, file_bytes, filename)
            return
