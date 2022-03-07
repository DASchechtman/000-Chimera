#pragma once

#include "Scopes/Scope.hpp"
#include "Scopes/GenScope.hpp"
#include "SymbolTable.hpp"
#include <stack>
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
    stack<Scope*> m_stack;
    SymbolTable *base = nullptr;

    // the state a new scope should have
    bool m_next_scope_runnable = true;

    // used to check when a scope's runnable state should be ignored and a different value
    // should be used instead
    bool m_override = false;

protected:
public:

    ScopeStack();
    ~ScopeStack();

    void CreateScope(string type);
    void DestroyScope();

    // depricated function, will be removed in further development
    void SetNextScopeRunStat(bool runnable);
    SymbolTable* GetTable();

    string GetScopeType();
    size_t Size();

};