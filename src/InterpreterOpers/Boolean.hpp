#pragma once

#include <string>
#include "../DataStructs/SymbolTable.hpp"

using namespace std;

string And(string var_1, string var_2, SymbolTable *var_table);
string Or(string var_1, string var_2, SymbolTable *var_table);
string Not(string var, SymbolTable *var_table);