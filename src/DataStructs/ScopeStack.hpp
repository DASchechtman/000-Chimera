#pragma once

#include "Scope.hpp"
#include "SymbolTable.hpp"
#include <stack>

using namespace std;

class ScopeStack {
private:
    stack<Scope*> m_stack;
    bool m_next_scope_runnable = true;

protected:
public:

    ScopeStack();
    ~ScopeStack();

    void CreateScope();
    void DestroyScope();
    void SetNextScopeRunStat(bool runnable);
    SymbolTable* GetTable();
    bool IsntRunnable();

};