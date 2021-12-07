#pragma once

#include "Scopes/Scope.hpp"
#include "Scopes/IfScope.hpp"
#include "Scopes/GenScope.hpp"
#include "SymbolTable.hpp"
#include <stack>
#include <string>

using namespace std;

const string PLACE_HOLDER_NAME = "#";

class ScopeStack {
private:
    stack<Scope*> m_stack;
    bool m_next_scope_runnable = true;

protected:
public:

    ScopeStack();
    ~ScopeStack();

    void CreateScope(string type);
    void DestroyScope();
    void SetNextScopeRunStat(bool runnable);
    SymbolTable* GetTable();
    bool IsntRunnable();
    string GetScopeType();

};