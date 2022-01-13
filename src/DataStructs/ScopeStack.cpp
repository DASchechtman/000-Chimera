#include "ScopeStack.hpp"

ScopeStack::ScopeStack() {
    m_stack.push(new GenScope());
}

ScopeStack::~ScopeStack() {
    while (m_stack.size() > 0) {
        delete m_stack.top();
        m_stack.pop();
    }
}

void ScopeStack::CreateScope(string type) {
    Scope *n_scope = new GenScope(GetTable(), m_stack.top());
    m_override = false;
    n_scope->SetRunnableState(true);
    m_stack.push(n_scope);
}

void ScopeStack::DestroyScope() {
    delete m_stack.top();
    m_stack.pop();
}

void ScopeStack::SetNextScopeRunStat(bool is_runnable) {
    m_next_scope_runnable = is_runnable;
}

SymbolTable* ScopeStack::GetTable() {
    return m_stack.top()->GetTable();
}

string ScopeStack::GetScopeType() {
    return m_stack.top()->GetType();
}

size_t ScopeStack::Size() {
    return m_stack.size();
}