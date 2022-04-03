#pragma once

#include <string>
#include "../DataStructs/Memory.hpp"


using namespace std;

string And(string var_1, string var_2, Memory &var_table);
string Or(string var_1, string var_2, Memory &var_table);
string Not(string var, Memory &var_table);