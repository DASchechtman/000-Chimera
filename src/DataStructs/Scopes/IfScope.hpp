#pragma once

#include "Scope.hpp"
#include <stack>

using namespace std;

/*
single scope representing an signle if/else-if/else (or any combination of those) chain. 
*/

struct Grouping {
    // indicates if any branch of an if-statement was run. so there's a way to make sure
    // only one if branch at most is run
    bool not_runnable;

    // keeps track of how many chain blocks are in an if-statement
    size_t members;

    // the symbol table to be shared amongst all blocks in a chain
    SymbolTable tbl;

    // parent scope to be shared amongst all blocks in a chain
    Scope *parent;
};

class IfScope : public Scope {
private:

    // indicates if a single branch of an if-statement was run
    bool m_single_branch_run = false;
    static stack<Grouping> if_groups;

    SymbolTable* m_table = nullptr;
    string scope_type;
    Scope *m_parent;

protected:
public:

    IfScope();
    IfScope(string cur_scope_type, SymbolTable* old, Scope *parent);
    ~IfScope();

    SymbolTable* GetTable();
    bool IsntRunnable();
    bool ParentIsntRunnable();
    void SetRunnableState(bool is_runnable);
    string GetType();
    size_t NumOfScopeMembers();
};