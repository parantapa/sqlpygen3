.PHONY : parser test

export PATH := ./node_modules/.bin/:$(PATH)
PROJECT_ROOT = ..

parser: src/parser.c

src/parser.c : grammar.js
	tree-sitter generate
	cp -a src/parser.c $(PROJECT_ROOT)/src/sqlpygen/tree-sitter-sqlpygen/src

test : parser
	tree-sitter test

