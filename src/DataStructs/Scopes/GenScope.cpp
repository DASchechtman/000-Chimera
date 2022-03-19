#include "GenScope.hpp"

GenScope::GenScope() {
    m_type = GEN_SCOPE;
}

GenScope::GenScope(SymbolTable *table, Scope *parent)
{
    scope_type = GEN_SCOPE;
    m_parent = parent;
    m_table.CopyTable(table);
}

GenScope::GenScope(string type, SymbolTable *table, Scope *parent) {
    m_parent = parent;
    m_table.CopyTable(table, true);
    scope_type = type;
}

GenScope::~GenScope() {}

SymbolTable* GenScope::GetTable() {
    return &m_table;
}

bool GenScope::IsntRunnable() {
    return !m_runnable_scope;
}

bool GenScope::ParentIsntRunnable() {
    if (m_parent != nullptr) {
        return m_parent->IsntRunnable();
    }
    return false;
}

void GenScope::SetRunnableState(bool is_runnable) {
    m_runnable_scope = is_runnable;
}

string GenScope::GetType() {
    return scope_type;
}

Scope *GenScope::GetParent() {
    return m_parent;
}

size_t GenScope::NumOfScopeMembers() {
    return 1;
}