#pragma once

#include <string>
#include "../DataStructs/Memory.hpp"

using namespace std;

string Less(string var_1, string var_2, Memory &tbl);
string LessEqual(string var_1, string var_2, Memory &tbl);
string Greater(string var_1, string var_2, Memory &tbl);
string GreaterEqual(string var_1, string var_2, Memory &tbl);
string Equal(string var_1, string var_2, Memory &tbl);