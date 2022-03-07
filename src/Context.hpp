#pragma once

#include <string>
#include "Types/Functions/Funcs.hpp"

using namespace std;

struct Context {
    Context(size_t cur_i, string c_name, ChmrFunc *c_func) {
        cur_instruction = cur_i;
        name = c_name;
        func = c_func;
    }

    Context() {};

    size_t cur_instruction;
    string name = "base";
    ChmrFunc *func = nullptr;
};