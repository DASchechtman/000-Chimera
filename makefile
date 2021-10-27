SRCS := $(shell find ./src -name '*.cpp')
PARSER_UTILS := $(shell find ./parser/Utils -name '*.cpp')
EXE_NAME = main

build:
	bison -d ./parser/Parser.y -o ./parser/Parser.cpp
	flex ./parser/Lexer.l
	mv lex.yy.c ./parser/
	g++ ./parser/Parser.cpp ./parser/lex.yy.c $(PARSER_UTILS) $(SRCS) -o $(EXE_NAME)

run:
	./$(EXE_NAME)

debug-png:
	bison -g ./parser/Parser.y -o ./parser/Parser.cpp
	dot -Tpng ./parser/Parser.dot -o ./parser/Parser.png

debug-txt:
	bison --debug ./parser/Parser.y -o ./parser/Parser.cpp