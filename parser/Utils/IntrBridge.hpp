/*
this is a header full of wrapper functions that wrap the public method of the interpreter class.
I did this because bison/yacc mix code and parser syntax into one thing, so I was trying to extract as
much code into it's own cpp file as possible so that I can keep things more flexible
*/
#pragma once

#include <string>
#include <vector>
#include "../../src/ChmrInterpreter.hpp"
#include "StrWrapper.hpp"

using namespace std;

void Perform(AstNode *&root, AstNode *node, COMMANDS type);