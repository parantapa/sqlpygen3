"""Python bindings for the tree-sitter-parser."""

import os
from pathlib import Path
from tree_sitter import Language, Parser

from platformdirs import user_cache_dir


def get_tree_stter_dir() -> Path:
    try:
        tree_sitter_dir = os.environ["SQLPYGEN_TREE_SITTER_DIR"]
    except Exception as e:
        raise RuntimeError(
            "Environment variable SQLPYGEN_TREE_SITTER_DIR not set."
        ) from e

    tree_sitter_dir = Path(tree_sitter_dir)
    return tree_sitter_dir


def get_parser() -> Parser:
    state_dir = user_cache_dir(appname="sqlpygen")
    state_dir = Path(state_dir)
    state_dir.mkdir(parents=True, exist_ok=True)

    tree_sitter_dir = get_tree_stter_dir()
    library_file = state_dir / "languages.so"

    Language.build_library(str(library_file), [str(tree_sitter_dir)])
    language = Language(str(library_file), "sqlpygen")

    parser = Parser()
    parser.set_language(language)

    return parser
