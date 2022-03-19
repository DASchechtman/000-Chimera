#pragma once

#include <string>
#include <vector>
#include "Types/Functions/Funcs.hpp"
#include "./DataStructs/ScopeTree.hpp"
#include "./DataStructs/CircularList.hpp"
#include "./DataStructs/ScopeStack.hpp"

using namespace std;

struct Context {
    Context(size_t cur_i, string c_name, ChmrFunc *c_func) {
        cur_instruction = cur_i;
        name = c_name;
        func = c_func;
    }

    Context() {};

    bool NewScopeEntered();
    bool ScopeWasExecuted();

    // keeps track of where the instructions are for each context on the stack
    size_t cur_instruction;
    string name = "base";
    ChmrFunc *func = nullptr;
    
    // keeps track of scope information for each context pushed on the stack
    ScopeTree tree;
    size_t cur_scope_level = 0;
    vector<JumpInfo> jump_points;
    ScopeStack scopes;
    stack<size_t> scope_branches_entered;
};