#pragma once

#include <string>
#include "../DataStructs/SymbolTable.hpp"

using namespace std;

string Less(string var_1, string var_2, SymbolTable *tbl);
string LessEqual(string var_1, string var_2, SymbolTable *tbl);
string Greater(string var_1, string var_2, SymbolTable *tbl);
string GreaterEqual(string var_1, string var_2, SymbolTable *tbl);
string Equal(string var_1, string var_2, SymbolTable *tbl);