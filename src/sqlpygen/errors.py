"""Error types."""

from enum import Enum
from pathlib import Path

import rich
import attrs
from tree_sitter import Node


class ErrorType(Enum):
    ParseError = "Failed to parse"
    MissingToken = "Missing token"

    DuplicateSchema = "Duplicate schema"
    DuplicateQuery = "Duplicate query"
    DuplicateTable = "Duplicate table"


@attrs.define
class Error:
    type: ErrorType
    explanation: str
    node: Node


def print_errors(errors: list[Error], file_bytes: bytes, file_path: Path):
    fpath = str(file_path)
    for error in errors:
        etype = error.type.value
        line = error.node.start_point[0] + 1
        col = error.node.start_point[1] + 1
        expl = error.explanation

        rich.print(f"[yellow]{etype}[/yellow]: {fpath}:{line}:{col}: {expl}")
        match error.type:
            case ErrorType.ParseError:
                error_part = file_bytes[
                    error.node.start_byte : error.node.end_byte
                ].decode()
                print(error_part)
                print("")
