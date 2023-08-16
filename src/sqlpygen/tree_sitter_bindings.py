"""Python bindings for the tree-sitter-parser."""

import os
from pathlib import Path
from tree_sitter import Language, Parser

PROJECT_ROOT = Path(__file__).parents[2]
TREE_SITTER_DIR = PROJECT_ROOT / "tree-sitter-sqlpygen"


def get_sqlpygen_state_dir() -> Path:
    if "XDG_STATE_HOME" in os.environ:
        state_home = os.environ["XDG_STATE_HOME"]
    else:
        state_home = os.environ["HOME"] + "/.local/state"

    state_dir = Path(state_home) / "sqlpygen"
    state_dir.mkdir(parents=True, exist_ok=True)
    return state_dir


def get_parser() -> Parser:
    state_dir = get_sqlpygen_state_dir()
    library_file = state_dir / "languages.so"

    Language.build_library(str(library_file), [str(TREE_SITTER_DIR)])
    language = Language(str(library_file), "sqlpygen")

    parser = Parser()
    parser.set_language(language)

    return parser
