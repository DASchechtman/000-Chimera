#include "Scope.hpp"

Scope::Scope() {}

Scope::Scope(SymbolTable *table):
m_table(table) 
{}

SymbolTable* Scope::GetTable() {
    return &m_table;
}

bool Scope::IsntRunnable() {
    return !m_runnable_scope;
}

void Scope::SetRunnableState(bool is_runnable) {
    m_runnable_scope = is_runnable;
}