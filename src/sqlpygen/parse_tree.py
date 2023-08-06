"""Parse using tree sitter."""

from pathlib import Path

import click
from tree_sitter import Node

import rich
from rich.tree import Tree

from .tree_sitter_bindings import get_parser
from .errors import ErrorType, Error


def collect_errors(node: Node, errors: list[Error] | None = None) -> list[Error]:
    if errors is None:
        errors = []

    if node.type == "ERROR":
        errors.append(
            Error(type=ErrorType.ParseError, explanation=node.sexp(), node=node)
        )
    elif node.is_missing:
        errors.append(
            Error(type=ErrorType.MissingToken, explanation=node.type, node=node)
        )
    elif node.has_error:
        for child in node.children:
            collect_errors(child, errors)

    return errors


def node_rich_text(node: Node) -> str:
    if node.is_missing:
        node_type = f"{node.type}[yellow]![yellow]"
    else:
        node_type = node.type

    if node.type == "ERROR":
        return f"[red]{node_type}[/red]{node.sexp()}"
    elif node.type in ["identifier", "comment", "schema_sql", "query_sql"]:
        return f"[cyan]{node_type}[/cyan]({node.text.decode()})"
    else:
        return f"[green]{node_type}[/green]"


def make_rich_tree(node: Node, named_only: bool, tree: Tree | None = None) -> Tree:
    if tree is None:
        tree = Tree(node_rich_text(node))
    else:
        tree = tree.add(node_rich_text(node))

    for child in node.children:
        if named_only:
            if child.is_named:
                make_rich_tree(child, named_only, tree)
        else:
            make_rich_tree(child, named_only, tree)

    return tree


@click.command()
@click.argument(
    "filename",
    type=click.Path(exists=True, file_okay=True, dir_okay=False, path_type=Path),
)
def print_parse_tree(filename: Path):
    """Print the parse tree."""

    file_bytes = filename.read_bytes()

    parser = get_parser()
    parse_tree = parser.parse(file_bytes)
    rich_tree = make_rich_tree(parse_tree.root_node, named_only=True)
    rich.print(rich_tree)
