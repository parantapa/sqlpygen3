"""example1

This module has been generated with SqlPyGen from example1.sqlpygen.
"""

import sqlite3
ConnectionType = sqlite3.Connection
CursorType = sqlite3.Cursor


from typing import cast, Generator
from contextlib import closing
from dataclasses import dataclass

SCHEMA = {}
SCHEMA["table_stocks"] = """
CREATE TABLE stocks (
    date text,
    trans text,
    symbol text,
    qty real,
    price real
) ;
"""


QUERY = {}
QUERY["insert_into_stocks"] = """
INSERT INTO stocks VALUES (:date, :trans, :symbol, :qty, :price) ;
"""

QUERY["select_from_stocks"] = """
SELECT * FROM stocks ;
"""

QUERY["count_stocks"] = """
SELECT COUNT(*) FROM stocks ;
"""



@dataclass(frozen=True, slots=True)
class StockRow:
    date: str | None
    trans: str | None
    symbol: str | None
    qty: float | None
    price: float | None

class Stock:
    def __init__(self, cursor: CursorType):
        self.cursor = cursor

    def __iter__(self) -> Generator[StockRow, None, None]:
        with closing(self.cursor):
            for row in self.cursor:
                yield StockRow(*row)

    def item(self) -> str | None:
        with closing(self.cursor):
            row = self.cursor.fetchone()
            assert row is not None, "Received zero rows"
            ret = cast(str | None, row[0])
            return ret


@dataclass(frozen=True, slots=True)
class count_stocks__ReturnTypeRow:
    count: int | None

class count_stocks__ReturnType:
    def __init__(self, cursor: CursorType):
        self.cursor = cursor

    def __iter__(self) -> Generator[count_stocks__ReturnTypeRow, None, None]:
        with closing(self.cursor):
            for row in self.cursor:
                yield count_stocks__ReturnTypeRow(*row)

    def item(self) -> int | None:
        with closing(self.cursor):
            row = self.cursor.fetchone()
            assert row is not None, "Received zero rows"
            ret = cast(int | None, row[0])
            return ret


def create_schema(connection: ConnectionType) -> None:
    """Create the table schema."""
    try:
        sql = SCHEMA["table_stocks"]

        connection.execute(sql)
    except Exception as e:
        raise RuntimeError(f"Error executing schema: table_stocks: {e}") from e




def insert_into_stocks(connection: ConnectionType, date: str | None, trans: str | None, symbol: str | None, qty: float | None, price: float | None, ) -> None:
    """Query insert_into_stocks."""
    cursor = connection.cursor()
    try:
        sql = QUERY["insert_into_stocks"]
        query_args = dict(date=date, trans=trans, symbol=symbol, qty=qty, price=price, )

        cursor.execute(sql, query_args)

    except Exception as e:
        raise RuntimeError(f"Error executing query: insert_into_stocks: {e}") from e

def select_from_stocks(connection: ConnectionType, ) -> Stock:
    """Query select_from_stocks."""
    cursor = connection.cursor()
    try:
        sql = QUERY["select_from_stocks"]
        query_args = dict()

        cursor.execute(sql, query_args)

        return Stock(cursor)
    except Exception as e:
        raise RuntimeError(f"Error executing query: select_from_stocks: {e}") from e

def count_stocks(connection: ConnectionType, ) -> count_stocks__ReturnType:
    """Query count_stocks."""
    cursor = connection.cursor()
    try:
        sql = QUERY["count_stocks"]
        query_args = dict()

        cursor.execute(sql, query_args)

        return count_stocks__ReturnType(cursor)
    except Exception as e:
        raise RuntimeError(f"Error executing query: count_stocks: {e}") from e

