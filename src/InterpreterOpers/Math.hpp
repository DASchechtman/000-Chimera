#pragma once

#include "../DataStructs/SymbolTable.hpp"
#include "../Types/ChimeraObject.hpp"
#include "../Types/Number/Number.hpp"
#include "../Types/Text/Text.hpp"
#include <string>

using namespace std;

enum OPER_CODE {ADD_CODE, SUBTRACT_CODE, MULTIPLY_CODE, DIVIDE_CODE, POW_CODE};

int Add(string var_1, string var_2, SymbolTable *var_table);
int Subtract(string var_1, string var_2, SymbolTable *var_table);
int Multiply(string var_1, string var_2, SymbolTable *var_table);
int Divide(string var_1, string var_2, SymbolTable *var_table);
int Pow(string var_1, string var_2, SymbolTable *var_table);