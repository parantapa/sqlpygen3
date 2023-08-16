"""Command line interface."""

import click

from .parse_tree import print_parse_tree
from .ast import print_initial_ast, print_final_ast
from .language_server import language_server
from .codegen import compile


@click.group()
def cli():
    """SqlPyGen: Generate Python functions from annotated SQL."""


cli.add_command(print_parse_tree)
cli.add_command(print_initial_ast)
cli.add_command(print_final_ast)
cli.add_command(language_server)
cli.add_command(compile)
