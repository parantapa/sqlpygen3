"""Start a language server."""

import logging
from pathlib import Path

import click
from lsprotocol.types import (
    DidOpenTextDocumentParams,
    DidSaveTextDocumentParams,
    TEXT_DOCUMENT_DID_OPEN,
    TEXT_DOCUMENT_DID_SAVE,
    Diagnostic,
    DiagnosticSeverity,
    Range,
    Position,
)
from pygls.server import LanguageServer

from sqlpygen.errors import Error

from .tree_sitter_bindings import get_parser, Parser
from .parse_tree import check_parse_errors
from .ast import make_ast
from .errors import Error, capture_errors

server = LanguageServer("sqlpygen-server", "v0.1")
parser: Parser | None = None


def error_to_diagnostic(error: Error) -> Diagnostic:
    return Diagnostic(
        range=Range(
            start=Position(error.node.start_point[0], error.node.start_point[1]),
            end=Position(error.node.end_point[0], error.node.end_point[1]),
        ),
        severity=DiagnosticSeverity.Error,
        message=f"{error.type.value}: {error.explanation}",
        source="sqlpygen-server",
    )


@server.feature(TEXT_DOCUMENT_DID_OPEN)
@server.feature(TEXT_DOCUMENT_DID_SAVE)
async def did_open(
    ls: LanguageServer, params: DidOpenTextDocumentParams | DidSaveTextDocumentParams
):
    assert parser is not None
    ls.show_message_log("checking document")

    # Parse the file
    text_doc = ls.workspace.get_document(params.text_document.uri)
    file_bytes = text_doc.source.encode()
    parse_tree = parser.parse(file_bytes)

    # In case of errors publish diagnostics
    if parse_tree.root_node.has_error:
        with capture_errors() as errors:
            check_parse_errors(parse_tree.root_node)
            diagnostics = [error_to_diagnostic(e) for e in errors]
            ls.publish_diagnostics(params.text_document.uri, diagnostics)
            return

    with capture_errors() as errors:
        make_ast(parse_tree.root_node)
        diagnostics = [error_to_diagnostic(e) for e in errors]
        ls.publish_diagnostics(params.text_document.uri, diagnostics)
        return


@click.command()
@click.option(
    "-l",
    "--log-file",
    type=click.Path(file_okay=True, dir_okay=False, path_type=Path),
    default=Path("~/sqlpygen-server.log").expanduser(),
    show_default=True,
    help="Log file",
)
def language_server(log_file: Path):
    """Start the language server."""
    global parser

    logging.basicConfig(filename=str(log_file), filemode="a", level=logging.INFO)

    parser = get_parser()
    server.start_io()
