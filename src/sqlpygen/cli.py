"""Command line interface."""

from pathlib import Path
from typing import cast

import rich
import click

from .parse_tree import print_parse_tree
from .ast import print_ast
from .language_server import language_server

from .tree_sitter_bindings import get_parser
from .parse_tree import collect_errors as collect_parse_errors
from .ast import Source, make_ast, collect_errors as collect_ast_errors
from .errors import print_errors


@click.group()
def cli():
    """SqlPyGen: Generate Python functions from annotated SQL."""


cli.add_command(print_parse_tree)
cli.add_command(print_ast)
cli.add_command(language_server)


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
        rich.print("[red]Error parsing file.[/red]")
        errors = collect_parse_errors(parse_tree.root_node)
        print_errors(errors, file_bytes, filename)
        return

    source = make_ast(parse_tree.root_node)
    source = cast(Source, source)
    errors = collect_ast_errors(source)
    if errors:
        print_errors(errors, file_bytes, filename)
        return
