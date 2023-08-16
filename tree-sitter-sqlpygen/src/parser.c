#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 41
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 9

enum {
  sym_identifier = 1,
  anon_sym_module = 2,
  anon_sym_dialect = 3,
  anon_sym_schema = 4,
  anon_sym_query = 5,
  anon_sym_table = 6,
  anon_sym_LPAREN = 7,
  anon_sym_COMMA = 8,
  anon_sym_RPAREN = 9,
  anon_sym_COLON = 10,
  anon_sym_BANG = 11,
  anon_sym_DASH_GT = 12,
  sym_schema_sql = 13,
  sym_query_sql = 14,
  sym_comment = 15,
  sym__whitespace = 16,
  sym_source_file = 17,
  sym_module_stmt = 18,
  sym_dialect_stmt = 19,
  sym_schema_fn = 20,
  sym_query_fn = 21,
  sym_table = 22,
  sym_fields = 23,
  sym_field = 24,
  sym__type = 25,
  sym_nullable_type = 26,
  sym_non_nullable_type = 27,
  sym_anon_table = 28,
  sym_named_table = 29,
  sym_return_ = 30,
  aux_sym_source_file_repeat1 = 31,
  aux_sym_fields_repeat1 = 32,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_module] = "module",
  [anon_sym_dialect] = "dialect",
  [anon_sym_schema] = "schema",
  [anon_sym_query] = "query",
  [anon_sym_table] = "table",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH_GT] = "->",
  [sym_schema_sql] = "schema_sql",
  [sym_query_sql] = "query_sql",
  [sym_comment] = "comment",
  [sym__whitespace] = "_whitespace",
  [sym_source_file] = "source_file",
  [sym_module_stmt] = "module_stmt",
  [sym_dialect_stmt] = "dialect_stmt",
  [sym_schema_fn] = "schema_fn",
  [sym_query_fn] = "query_fn",
  [sym_table] = "table",
  [sym_fields] = "fields",
  [sym_field] = "field",
  [sym__type] = "_type",
  [sym_nullable_type] = "nullable_type",
  [sym_non_nullable_type] = "non_nullable_type",
  [sym_anon_table] = "anon_table",
  [sym_named_table] = "named_table",
  [sym_return_] = "return_",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_fields_repeat1] = "fields_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_dialect] = anon_sym_dialect,
  [anon_sym_schema] = anon_sym_schema,
  [anon_sym_query] = anon_sym_query,
  [anon_sym_table] = anon_sym_table,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [sym_schema_sql] = sym_schema_sql,
  [sym_query_sql] = sym_query_sql,
  [sym_comment] = sym_comment,
  [sym__whitespace] = sym__whitespace,
  [sym_source_file] = sym_source_file,
  [sym_module_stmt] = sym_module_stmt,
  [sym_dialect_stmt] = sym_dialect_stmt,
  [sym_schema_fn] = sym_schema_fn,
  [sym_query_fn] = sym_query_fn,
  [sym_table] = sym_table,
  [sym_fields] = sym_fields,
  [sym_field] = sym_field,
  [sym__type] = sym__type,
  [sym_nullable_type] = sym_nullable_type,
  [sym_non_nullable_type] = sym_non_nullable_type,
  [sym_anon_table] = sym_anon_table,
  [sym_named_table] = sym_named_table,
  [sym_return_] = sym_return_,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_fields_repeat1] = aux_sym_fields_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dialect] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_schema] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_query] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_table] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_schema_sql] = {
    .visible = true,
    .named = true,
  },
  [sym_query_sql] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_module_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_dialect_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_schema_fn] = {
    .visible = true,
    .named = true,
  },
  [sym_query_fn] = {
    .visible = true,
    .named = true,
  },
  [sym_table] = {
    .visible = true,
    .named = true,
  },
  [sym_fields] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_nullable_type] = {
    .visible = true,
    .named = true,
  },
  [sym_non_nullable_type] = {
    .visible = true,
    .named = true,
  },
  [sym_anon_table] = {
    .visible = true,
    .named = true,
  },
  [sym_named_table] = {
    .visible = true,
    .named = true,
  },
  [sym_return_] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fields_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_fields = 1,
  field_name = 2,
  field_params = 3,
  field_return = 4,
  field_sql = 5,
  field_type = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fields] = "fields",
  [field_name] = "name",
  [field_params] = "params",
  [field_return] = "return",
  [field_sql] = "sql",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 3},
  [5] = {.index = 8, .length = 1},
  [6] = {.index = 9, .length = 1},
  [7] = {.index = 10, .length = 4},
  [8] = {.index = 14, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 1},
    {field_sql, 2},
  [3] =
    {field_fields, 2},
    {field_name, 1},
  [5] =
    {field_name, 1},
    {field_params, 2},
    {field_sql, 3},
  [8] =
    {field_name, 0},
  [9] =
    {field_fields, 0},
  [10] =
    {field_name, 1},
    {field_params, 2},
    {field_return, 3},
    {field_sql, 4},
  [14] =
    {field_name, 0},
    {field_type, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(31);
      if (lookahead == '!') ADVANCE(36);
      if (lookahead == '#') ADVANCE(40);
      if (lookahead == '(') ADVANCE(32);
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == ',') ADVANCE(33);
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == ':') ADVANCE(35);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(63);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(48);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(59);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(55);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(40);
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(23);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(10);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(19);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(15);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(41);
      END_STATE();
    case 2:
      if (lookahead == ';') ADVANCE(38);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == ';') ADVANCE(39);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '>') ADVANCE(37);
      END_STATE();
    case 5:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(27);
      END_STATE();
    case 6:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(28);
      END_STATE();
    case 7:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(26);
      END_STATE();
    case 8:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(6);
      END_STATE();
    case 9:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(2);
      END_STATE();
    case 10:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(17);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(5);
      END_STATE();
    case 12:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 13:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 14:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 15:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 17:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 19:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(2);
      END_STATE();
    case 22:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 23:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 24:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 25:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(14);
      END_STATE();
    case 26:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(3);
      END_STATE();
    case 27:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(9);
      END_STATE();
    case 28:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(13);
      END_STATE();
    case 29:
      if (eof) ADVANCE(31);
      if (lookahead == '#') ADVANCE(40);
      if (lookahead == '(') ADVANCE(32);
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 30:
      if (eof) ADVANCE(31);
      if (lookahead == '#') ADVANCE(40);
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(49);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(59);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(55);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_schema_sql);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_query_sql);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ';') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == ';') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(57);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'd') ADVANCE(1);
      if (lookahead == 'm') ADVANCE(2);
      if (lookahead == 'q') ADVANCE(3);
      if (lookahead == 's') ADVANCE(4);
      if (lookahead == 't') ADVANCE(5);
      END_STATE();
    case 1:
      if (lookahead == 'i') ADVANCE(6);
      END_STATE();
    case 2:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'c') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 'd') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'h') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'b') ADVANCE(15);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 12:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 13:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 18:
      if (lookahead == 'y') ADVANCE(23);
      END_STATE();
    case 19:
      if (lookahead == 'm') ADVANCE(24);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(26);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_query);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(28);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 26:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_schema);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_dialect);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 29},
  [2] = {.lex_state = 29},
  [3] = {.lex_state = 29},
  [4] = {.lex_state = 29},
  [5] = {.lex_state = 30},
  [6] = {.lex_state = 30},
  [7] = {.lex_state = 30},
  [8] = {.lex_state = 29},
  [9] = {.lex_state = 29},
  [10] = {.lex_state = 29},
  [11] = {.lex_state = 29},
  [12] = {.lex_state = 29},
  [13] = {.lex_state = 29},
  [14] = {.lex_state = 29},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 29},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 29},
  [22] = {.lex_state = 29},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 29},
  [31] = {.lex_state = 29},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 29},
  [34] = {.lex_state = 29},
  [35] = {.lex_state = 29},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 29},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [anon_sym_dialect] = ACTIONS(1),
    [anon_sym_schema] = ACTIONS(1),
    [anon_sym_query] = ACTIONS(1),
    [anon_sym_table] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [sym_schema_sql] = ACTIONS(1),
    [sym_query_sql] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym__whitespace] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(39),
    [sym_module_stmt] = STATE(21),
    [anon_sym_module] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [sym__whitespace] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_schema,
    ACTIONS(11), 1,
      anon_sym_query,
    ACTIONS(13), 1,
      anon_sym_table,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(3), 4,
      sym_schema_fn,
      sym_query_fn,
      sym_table,
      aux_sym_source_file_repeat1,
  [23] = 6,
    ACTIONS(9), 1,
      anon_sym_schema,
    ACTIONS(11), 1,
      anon_sym_query,
    ACTIONS(13), 1,
      anon_sym_table,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(4), 4,
      sym_schema_fn,
      sym_query_fn,
      sym_table,
      aux_sym_source_file_repeat1,
  [46] = 6,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      anon_sym_schema,
    ACTIONS(22), 1,
      anon_sym_query,
    ACTIONS(25), 1,
      anon_sym_table,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(4), 4,
      sym_schema_fn,
      sym_query_fn,
      sym_table,
      aux_sym_source_file_repeat1,
  [69] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(28), 6,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
      anon_sym_DASH_GT,
      sym_query_sql,
  [82] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(30), 6,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
      anon_sym_DASH_GT,
      sym_query_sql,
  [95] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(32), 6,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
      anon_sym_DASH_GT,
      sym_query_sql,
  [108] = 5,
    ACTIONS(34), 1,
      sym_identifier,
    ACTIONS(36), 1,
      anon_sym_LPAREN,
    STATE(37), 1,
      sym_fields,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(38), 2,
      sym_anon_table,
      sym_named_table,
  [126] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(38), 4,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
  [137] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(40), 4,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
  [148] = 3,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(25), 3,
      sym__type,
      sym_nullable_type,
      sym_non_nullable_type,
  [161] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(44), 4,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
  [172] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(46), 4,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
  [183] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(48), 4,
      ts_builtin_sym_end,
      anon_sym_schema,
      anon_sym_query,
      anon_sym_table,
  [194] = 4,
    ACTIONS(50), 1,
      anon_sym_COMMA,
    ACTIONS(52), 1,
      anon_sym_RPAREN,
    STATE(17), 1,
      aux_sym_fields_repeat1,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [208] = 4,
    ACTIONS(50), 1,
      anon_sym_COMMA,
    ACTIONS(54), 1,
      anon_sym_RPAREN,
    STATE(15), 1,
      aux_sym_fields_repeat1,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [222] = 4,
    ACTIONS(56), 1,
      anon_sym_COMMA,
    ACTIONS(59), 1,
      anon_sym_RPAREN,
    STATE(17), 1,
      aux_sym_fields_repeat1,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [236] = 4,
    ACTIONS(61), 1,
      sym_identifier,
    ACTIONS(63), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      sym_field,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [250] = 4,
    ACTIONS(65), 1,
      anon_sym_DASH_GT,
    ACTIONS(67), 1,
      sym_query_sql,
    STATE(32), 1,
      sym_return_,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [264] = 3,
    ACTIONS(71), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(69), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [276] = 3,
    ACTIONS(73), 1,
      anon_sym_dialect,
    STATE(2), 1,
      sym_dialect_stmt,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [287] = 3,
    ACTIONS(61), 1,
      sym_identifier,
    STATE(26), 1,
      sym_field,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [298] = 3,
    ACTIONS(36), 1,
      anon_sym_LPAREN,
    STATE(19), 1,
      sym_fields,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [309] = 3,
    ACTIONS(36), 1,
      anon_sym_LPAREN,
    STATE(14), 1,
      sym_fields,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [320] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(75), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [329] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(59), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [338] = 2,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(77), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [347] = 2,
    ACTIONS(79), 1,
      sym_schema_sql,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [355] = 2,
    ACTIONS(81), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [363] = 2,
    ACTIONS(83), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [371] = 2,
    ACTIONS(85), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [379] = 2,
    ACTIONS(87), 1,
      sym_query_sql,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [387] = 2,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [395] = 2,
    ACTIONS(91), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [403] = 2,
    ACTIONS(93), 1,
      anon_sym_dialect,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [411] = 2,
    ACTIONS(95), 1,
      sym_query_sql,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [419] = 2,
    ACTIONS(97), 1,
      sym_query_sql,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [427] = 2,
    ACTIONS(99), 1,
      sym_query_sql,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [435] = 2,
    ACTIONS(101), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [443] = 2,
    ACTIONS(103), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 46,
  [SMALL_STATE(5)] = 69,
  [SMALL_STATE(6)] = 82,
  [SMALL_STATE(7)] = 95,
  [SMALL_STATE(8)] = 108,
  [SMALL_STATE(9)] = 126,
  [SMALL_STATE(10)] = 137,
  [SMALL_STATE(11)] = 148,
  [SMALL_STATE(12)] = 161,
  [SMALL_STATE(13)] = 172,
  [SMALL_STATE(14)] = 183,
  [SMALL_STATE(15)] = 194,
  [SMALL_STATE(16)] = 208,
  [SMALL_STATE(17)] = 222,
  [SMALL_STATE(18)] = 236,
  [SMALL_STATE(19)] = 250,
  [SMALL_STATE(20)] = 264,
  [SMALL_STATE(21)] = 276,
  [SMALL_STATE(22)] = 287,
  [SMALL_STATE(23)] = 298,
  [SMALL_STATE(24)] = 309,
  [SMALL_STATE(25)] = 320,
  [SMALL_STATE(26)] = 329,
  [SMALL_STATE(27)] = 338,
  [SMALL_STATE(28)] = 347,
  [SMALL_STATE(29)] = 355,
  [SMALL_STATE(30)] = 363,
  [SMALL_STATE(31)] = 371,
  [SMALL_STATE(32)] = 379,
  [SMALL_STATE(33)] = 387,
  [SMALL_STATE(34)] = 395,
  [SMALL_STATE(35)] = 403,
  [SMALL_STATE(36)] = 411,
  [SMALL_STATE(37)] = 419,
  [SMALL_STATE(38)] = 427,
  [SMALL_STATE(39)] = 435,
  [SMALL_STATE(40)] = 443,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(33),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(31),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(30),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fields, 4),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fields, 3),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fields, 2),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_schema_fn, 3, .production_id = 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_fn, 5, .production_id = 7),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialect_stmt, 2, .production_id = 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_fn, 4, .production_id = 4),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 3, .production_id = 3),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fields_repeat1, 2), SHIFT_REPEAT(22),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fields_repeat1, 2),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nullable_type, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 3, .production_id = 8),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_nullable_type, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_stmt, 2, .production_id = 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_named_table, 1, .production_id = 5),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_table, 1, .production_id = 6),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_, 2),
  [101] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_sqlpygen(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
