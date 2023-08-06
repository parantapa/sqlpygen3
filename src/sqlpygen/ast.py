"""Create AST from parse_tree."""

from typing import Any
from pathlib import Path
from collections import Counter

import rich
import attrs
import click
from tree_sitter import Node

from .parse_tree import get_parser, make_rich_tree
from .errors import ErrorType, Error


@attrs.define
class CodeStr:
    s: str
    node: Node

    def __str__(self):
        return self.s

    def __hash__(self):
        return hash(self.s)

    def __eq__(self, other):
        if isinstance(other, CodeStr):
            return self.s == other.s
        elif isinstance(other, str):
            return self.s == other
        else:
            raise TypeError("Invalid type for other")


@attrs.define
class Type:
    name: CodeStr
    nullable: bool
    node: Node


@attrs.define
class Field:
    name: CodeStr
    type: Type
    node: Node


@attrs.define
class Table:
    name: CodeStr
    fields: list[Field]
    node: Node


@attrs.define
class AnonTable:
    fields: list[Field]
    node: Node


@attrs.define
class SchemaFn:
    name: CodeStr
    sql: CodeStr
    node: Node


@attrs.define
class QueryFn:
    name: CodeStr
    params: list[Field]
    return_: CodeStr | AnonTable | None
    sql: CodeStr
    node: Node


@attrs.define
class Source:
    module: CodeStr
    schemas: list[SchemaFn]
    queries: list[QueryFn]
    tables: list[Table]
    node: Node


class UnexpectedChildCount(ValueError):
    def __str__(self):
        return "unexpected child count"


class ASTConstructionError(ValueError):
    def __init__(self, node: Node, children: list[Any]):
        self.node = node
        self.children = children

    def __str__(self):
        return "Failed to construct AST"


def make_ast(node: Node) -> Any:
    children = [make_ast(child) for child in node.named_children]
    children = [c for c in children if c is not None]

    try:
        match node.type:
            case "source_file":
                module, *rest = children
                schemas = [c for c in rest if isinstance(c, SchemaFn)]
                queries = [c for c in rest if isinstance(c, QueryFn)]
                tables = [c for c in rest if isinstance(c, Table)]
                return Source(module, schemas, queries, tables, node)
            case "module_stmt":
                (name,) = children
                return name
            case "schema_fn":
                name, sql = children
                return SchemaFn(name, sql, node)
            case "query_fn":
                match children:
                    case [name, params, return_, sql]:
                        return QueryFn(name, params, return_, sql, node)
                    case [name, params, sql]:
                        return QueryFn(name, params, None, sql, node)
                    case _:
                        raise UnexpectedChildCount()
            case "table":
                name, fields = children
                return Table(name, fields, node)
            case "fields":
                return children
            case "field":
                name, type = children
                return Field(name, type, node)
            case "nullable_type":
                (name,) = children
                return Type(name, True, node)
            case "non_nullable_type":
                (name,) = children
                return Type(name, False, node)
            case "anon_table":
                (fields,) = children
                return AnonTable(fields, node)
            case "named_table":
                (name,) = children
                return name
            case "return_":
                (ret,) = children
                return ret
            case "identifier" | "schema_sql" | "query_sql":
                return CodeStr(node.text.decode(), node)
            case _:
                return None
    except Exception:
        raise ASTConstructionError(node, children)


def collect_errors(source: Source) -> list[Error]:
    """Check AST for errors."""
    errors = []

    # Check for duplicate schema names
    schema_names = Counter(s.name for s in source.schemas)
    for name, count in schema_names.items():
        if count > 1:
            for s in source.schemas:
                if s.name == name:
                    errors.append(
                        Error(
                            type=ErrorType.DuplicateSchema,
                            explanation=f"Schema {name} is multiply defined",
                            node=s.node,
                        )
                    )

    # Check for duplicate query names
    query_names = Counter(s.name for s in source.queries)
    for name, count in query_names.items():
        if count > 1:
            for s in source.queries:
                if s.name == name:
                    errors.append(
                        Error(
                            type=ErrorType.DuplicateQuery,
                            explanation=f"Query {name} is multiply defined",
                            node=s.node,
                        )
                    )

    # Check for duplicate table names
    table_names = Counter(s.name for s in source.tables)
    for name, count in table_names.items():
        if count > 1:
            for s in source.tables:
                if s.name == name:
                    errors.append(
                        Error(
                            type=ErrorType.DuplicateTable,
                            explanation=f"Table {name} is multiply defined",
                            node=s.node,
                        )
                    )

    return errors


@click.command()
@click.argument(
    "filename",
    type=click.Path(exists=True, file_okay=True, dir_okay=False, path_type=Path),
)
def print_ast(filename: Path):
    """Print the abstract syntax tree."""

    file_bytes = filename.read_bytes()

    parser = get_parser()
    parse_tree = parser.parse(file_bytes)
    try:
        ast = make_ast(parse_tree.root_node)
    except ASTConstructionError as e:
        print(e)
        rich_parse_tree = make_rich_tree(e.node, named_only=False)
        rich.print(rich_parse_tree)
        return
    rich.print(ast)
