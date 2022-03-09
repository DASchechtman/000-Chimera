#pragma once

#include <string>
#include <stack>
#include <memory>
#include <iostream>
#include <vector>
#include "../Context.hpp"
#include "../Ast.hpp"
#include "../DataStructs/SymbolTable.hpp"
#include "../Types/Functions/Funcs.hpp"

using namespace std;

string MakeFunc(AstNode *root, SymbolTable *tbl, string func_name, string ret_type, size_t cur_i);
string CallFunc(AstNode *root, SymbolTable *tbl, string func_name);
string RetFromFunc(AstNode *root, stack<Context> &sp);