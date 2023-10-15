SqlPyGen: Generate Type Annotated Python from Annotated SQL
===========================================================

sqlpygen is a utility to generate
type annotated Python code from annotated SQL.

The current version of the tool only supports
generating code for SQLite3.

Installation
------------

You can install SqlPyGen using pip.

.. code:: bash

   $ pip install sqlpygen

Example Usage
-------------

When using sqlpygen to generate Python code from SQL,
one creates a sqlpygen file.
See `examples` directory for syntax of sqlpygen files.

Next use the following command to generate the python code.

.. code:: bash

   $ cd examples
   $ sqlpygen compile example1.sqlpygen
   Executed schema table_stocks successfully
   Executed query insert_into_stocks successfully
   Executed query select_from_stocks successfully
   Executed query count_stocks successfully
   Writing output to: example1.py
   Module example1 generated successfully.

