module.exports = grammar({
    name: 'sqlpygen',

    word: $ => $.identifier,

    rules: {
        source_file: $ => seq(
            $.module_stmt,
            $.dialect_stmt,
            repeat(choice($.schema_fn, $.query_fn, $.table))
        ),

        module_stmt: $ => seq(
            'module',
            field('name', $.identifier)
        ),
        
        dialect_stmt: $ => seq(
            'dialect',
            field('name', $.identifier)
        ),

        schema_fn: $ => seq(
            'schema',
            field('name', $.identifier),
            field('sql', $.schema_sql),
        ),

        query_fn: $ => seq(
            'query',
            field('name', $.identifier),
            field('params', $.fields),
            field('return', optional($.return_)),
            field('sql', $.query_sql),
        ),

        table: $ => seq(
            'table',
            field('name', $.identifier),
            field('fields', $.fields),
        ),

        fields: $ => seq(
            '(',
            commaSep($.field),
            ')'
        ),

        field: $ => seq(
            field('name', $.identifier),
            ':',
            field('type', $._type),
        ),

        _type: $ => choice($.nullable_type, $.non_nullable_type),

        nullable_type: $ => $.identifier,

        non_nullable_type: $ => seq($.identifier, '!'),

        anon_table: $ => seq(
            field('fields', $.fields),
        ),

        named_table: $ => seq(
            field('name', $.identifier),
        ),

        return_: $ => seq(
            '->',
            choice($.named_table, $.anon_table)
        ),

        schema_sql: _ => token(seq(
            choice(
                reservedWord("create"),
                reservedWord("drop")
            ),
            /[^;]*/,
            ';'
        )),

        query_sql: _ => token(seq(
            choice(
                reservedWord("insert"),
                reservedWord("update"),
                reservedWord("delete"),
                reservedWord("select"),
            ),
            /[^;]*/,
            ';'
        )),

        comment: _ => token(seq('#', /.*/)),

        _whitespace: _ => /\s+/,

        identifier: _ => /[_a-zA-Z][_a-zA-Z0-9]*/,
    },

    extras: $ => [
        $.comment,
        $._whitespace
    ]
});

function commaSep1(rule) {
    return seq(rule, repeat(seq(',', rule)));
}

function commaSep(rule) {
    return optional(commaSep1(rule));
}

function reservedWord(word) {
    //return word // when debuging
    return alias(reserved(caseInsensitive(word)), word)
}

function reserved(regex) {
    return token(prec(1, new RegExp(regex)))
}

function caseInsensitive(word) {
    return word.split('')
        .map(letter => `[${letter}${letter.toUpperCase()}]`)
        .join('')
}
