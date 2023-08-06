"""Command line interface."""

import click

from .parse_tree import check_for_errors, print_parse_tree
from .ast import print_ast
from .language_server import language_server


@click.group()
def cli():
    """SqlPyGen: Generate Python functions from annotated SQL."""


cli.add_command(check_for_errors)
cli.add_command(print_parse_tree)
cli.add_command(print_ast)
cli.add_command(language_server)
