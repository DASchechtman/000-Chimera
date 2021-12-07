#pragma once

#include "Scope.hpp"
#include <stack>

using namespace std;

struct Grouping {
    bool not_runnable;
    size_t members;
};

class IfScope : public Scope {
private:
    bool m_single_branch_run = false;
    static stack<Grouping> if_groups;

    SymbolTable m_table;
    string scope_type;

protected:
public:

    IfScope();
    IfScope(string cur_scope_type, SymbolTable* old);
    ~IfScope();

    SymbolTable* GetTable();
    bool IsntRunnable();
    void SetRunnableState(bool is_runnable);
    string GetType();

    static void ClearGroups();
};