["module" "schema" "query" "table"] @keyword

(comment) @comment

(module_stmt name: (identifier) @module)
(schema_fn name: (identifier) @function)
(query_fn name: (identifier) @function)
(table name: (identifier) @type)
(named_table name: (identifier) @type)
(field
  name: (identifier) @variable.parameter
)
(nullable_type (identifier) @type.builtin)
(non_nullable_type (identifier) @type.builtin)
