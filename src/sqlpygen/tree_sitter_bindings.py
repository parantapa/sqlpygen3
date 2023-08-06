"""Python bindings for the tree-sitter-parser."""

from pathlib import Path
from tree_sitter import Language, Parser

PROJECT_ROOT = Path(__file__).parents[2]
TREE_SITTER_DIR = PROJECT_ROOT / "tree-sitter-sqlpygen"
BUILD_DIR = PROJECT_ROOT / "build/py_lib"
SRC_FILE = TREE_SITTER_DIR / "src/parser.c"
LIBRARY_FILE = BUILD_DIR / "languages.so"


def is_library_up_to_date() -> bool:
    return LIBRARY_FILE.exists() and (
        LIBRARY_FILE.stat().st_mtime >= SRC_FILE.stat().st_mtime
    )


def build_library():
    BUILD_DIR.mkdir(parents=True, exist_ok=True)

    print("Building tree-sitter library file:", str(LIBRARY_FILE))
    Language.build_library(str(LIBRARY_FILE), [str(TREE_SITTER_DIR)])


def get_parser() -> Parser:
    if not is_library_up_to_date():
        build_library()

    language = Language(str(LIBRARY_FILE), "sqlpygen")

    parser = Parser()
    parser.set_language(language)

    return parser
