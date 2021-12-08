#include "IfScope.hpp"
#include <iostream>

using namespace std;

stack<Grouping> IfScope::if_groups;

IfScope::IfScope() {
    m_type = IF_SCOPE;
}

IfScope::IfScope(string cur_scope_type, SymbolTable* old, Scope *parent) {
    m_type = IF_SCOPE;
    scope_type = cur_scope_type;

    // used to create a new grouping to differntiate between nested if-statements
    if (scope_type == IF_SCOPE) {
        Grouping g;
        g.not_runnable = false;
        g.members = 1;

        if (if_groups.size() == 0) {
            g.tbl.CopyTable(old);
        }
        else {
            g.tbl.CopyTable(&if_groups.top().tbl);
        }

        g.parent = parent;

        if_groups.push(g);
    }
    else if(if_groups.size() > 0) {
        if_groups.top().members++;
    }

    m_table = &if_groups.top().tbl;
    m_parent = if_groups.top().parent;
}

IfScope::~IfScope() {
    if (scope_type == IF_SCOPE) {
        if_groups.pop();
    }
}

SymbolTable* IfScope::GetTable() {
    return m_table;
}

bool IfScope::IsntRunnable() {
    return !m_single_branch_run;
}

bool IfScope::ParentIsntRunnable() {
    return m_parent->IsntRunnable();
}

void IfScope::SetRunnableState(bool is_runnable) {
    if (!IfScope::if_groups.top().not_runnable) {
        m_single_branch_run = is_runnable;
        IfScope::if_groups.top().not_runnable = is_runnable;
    }
}

string IfScope::GetType() {
    return scope_type;
}

size_t IfScope::NumOfScopeMembers() {
    return if_groups.top().members;
}