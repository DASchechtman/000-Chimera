#pragma once

#include "../SymbolTable.hpp"
#include "Scope.hpp"
#include <string>

using namespace std;

/*
A general purpose type that doesn't have any functionality beyond being a placeholder scope when no other scope
is a suitable tool to use
*/

class GenScope : public Scope {
private:
    SymbolTable m_table;
    bool m_runnable_scope = true;
    Scope *m_parent = nullptr;
    string scope_type;

protected:
public:

    GenScope();
    GenScope(SymbolTable *table, Scope *parent);
    GenScope(string type, SymbolTable *table, Scope *parent);
    ~GenScope();

    SymbolTable* GetTable();
    bool IsntRunnable();
    bool ParentIsntRunnable();
    void SetRunnableState(bool is_runnable);
    string GetType();
    Scope *GetParent();
    size_t NumOfScopeMembers();
};