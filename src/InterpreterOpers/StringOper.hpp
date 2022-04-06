#pragma once

#include "../DataStructs/Memory.hpp"
#include "../Types/Text/Derived/String.hpp"
#include "../Types/Number/Derived/Int.hpp"
#include <string>

using namespace std;

string GetChar(string str_name, string index_name, Memory &mem);
string GetStrLen(string str_name, Memory &mem);