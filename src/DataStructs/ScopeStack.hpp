#pragma once

#include "Scopes/GenScope.hpp"
#include <vector>
#include <string>

using namespace std;

/*
Keeps track of a stack that holds scopes. Makes creating a scope and destroying a scope easier in other
parts of the code.
*/

// a return value for when a scope can't be run
const string PLACE_HOLDER_NAME = "#";

class ScopeStack {
private:
    vector<GenScope*> m_stack;
    Memory *base = nullptr;

    // the state a new scope should have
    bool m_next_scope_runnable = true;

    // used to check when a scope's runnable state should be ignored and a different value
    // should be used instead
    bool m_override = false;

protected:
public:

    ScopeStack();
    ScopeStack(const ScopeStack &old);
    ~ScopeStack();

    void CreateScope(string type);
    void DestroyScope();
    void CopyScopeBaseSymbolTable(const ScopeStack &other);

    Memory& GetMemory();

    string GetScopeType();
    size_t Size();

};