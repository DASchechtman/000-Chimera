SRCS := $(shell find ./src -name '*.cpp')
PARSER_UTILS := $(shell find ./parser/Utils -name '*.cpp')

build:
	bison -d ./parser/Parser.y -o ./parser/Parser.cpp
	flex ./parser/Lexer.l
	mv lex.yy.c ./parser/
	g++ ./parser/Parser.cpp ./parser/lex.yy.c $(SRCS) $(PARSER_UTILS)