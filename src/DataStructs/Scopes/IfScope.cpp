#include "IfScope.hpp"
#include <iostream>

using namespace std;

stack<Grouping> IfScope::if_groups;

IfScope::IfScope() {
    m_type = IF_SCOPE;
}

IfScope::IfScope(string cur_scope_type, SymbolTable* old) {
    m_type = IF_SCOPE;
    m_table.CopyTable(old);
    scope_type = cur_scope_type;

    if (scope_type == IF_SCOPE) {
        Grouping g;
        g.not_runnable = false;
        g.members = 1;
        if_groups.push(g);
    }
    else if(if_groups.size() > 0) {
        if_groups.top().members++;
    }
}

IfScope::~IfScope() {
    if (scope_type == ELSE_SCOPE) {
        if_groups.pop();
    }
}

SymbolTable* IfScope::GetTable() {
    return &m_table;
}

bool IfScope::IsntRunnable() {
    return !m_single_branch_run;
}

void IfScope::SetRunnableState(bool is_runnable) {
    if (!IfScope::if_groups.top().not_runnable) {
        m_single_branch_run = is_runnable;
        IfScope::if_groups.top().not_runnable = is_runnable;
    }
}

string IfScope::GetType() {
    return IF_SCOPE;
}

void IfScope::ClearGroups() {
    while(if_groups.size() > 0) {
        if_groups.pop();
    }
}