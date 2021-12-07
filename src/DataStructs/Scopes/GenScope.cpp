#include "GenScope.hpp"

GenScope::GenScope() {
    m_type = GEN_SCOPE;
}

GenScope::GenScope(SymbolTable *table):
m_table(table) 
{
    m_type = GEN_SCOPE;
}

GenScope::~GenScope() {}

SymbolTable* GenScope::GetTable() {
    return &m_table;
}

bool GenScope::IsntRunnable() {
    return !m_runnable_scope;
}

void GenScope::SetRunnableState(bool is_runnable) {
    m_runnable_scope = is_runnable;
}

string GenScope::GetType() {
    return GEN_SCOPE;
}