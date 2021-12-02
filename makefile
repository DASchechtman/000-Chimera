SRCS := $(shell find ./src -name '*.cpp')
PARSER_UTILS := $(shell find ./parser/Utils -name '*.cpp')
EXE_NAME = main
CWD := $(shell pwd)
TEST_FILES = $(shell find "./tests/" -name '*.ch')
FOR_TEST = $(foreach i,$(TEST_FILES),echo $(i); ./$(EXE_NAME) $(i); echo "";)

build:
	bison -d ./parser/Parser.y -o ./parser/Parser.cpp
	flex ./parser/Lexer.l
	mv lex.yy.c ./parser/
	g++ -Wall ./parser/Parser.cpp ./parser/lex.yy.c $(PARSER_UTILS) $(SRCS) -o $(EXE_NAME)

debug:
	bison -d ./parser/Parser.y -o ./parser/Parser.cpp
	flex ./parser/Lexer.l
	mv lex.yy.c ./parser/
	g++ -g -Wall ./parser/Parser.cpp ./parser/lex.yy.c $(PARSER_UTILS) $(SRCS) -o $(EXE_NAME)

run:
	./$(EXE_NAME)

backup-and-push:
	mount -t drvfs E: /mnt/e/
	rsync --exclude desktop.ini --exclude *.gdoc -r --delete ./ "/mnt/c/Users/dsche/OneDrive - carthage.edu/Chimera PL/"
	rsync --exclude desktop.ini --exclude *.gdoc -r --delete ./ /mnt/e/Machine/Lenovo_legion_5/Thesis/
	git push

test:
	@echo ""
	$(FOR_TEST)

debug-png:
	bison -g ./parser/Parser.y -o ./parser/Parser.cpp
	dot -Tpng ./parser/Parser.dot -o ./parser/Parser.png

debug-txt:
	bison --verbos ./parser/Parser.y
	rm Parser.tab.c