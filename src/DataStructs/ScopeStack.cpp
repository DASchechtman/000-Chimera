#include "ScopeStack.hpp"

ScopeStack::ScopeStack() {
    m_stack.push(new Scope());
}

ScopeStack::~ScopeStack() {
    while (m_stack.size() > 0) {
        delete m_stack.top();
        m_stack.pop();
    }
}

void ScopeStack::CreateScope() {
    auto n_scope = new Scope(GetTable());
    n_scope->SetRunnableState(m_next_scope_runnable);
    m_stack.push(n_scope);
    m_next_scope_runnable = !m_stack.top()->IsntRunnable();
}

void ScopeStack::DestroyScope() {
    if (m_stack.size() > 1) {
        delete m_stack.top();
        m_stack.pop();
        m_next_scope_runnable = !m_stack.top()->IsntRunnable();
    }
}

void ScopeStack::SetNextScopeRunStat(bool is_runnable) {
    m_next_scope_runnable = is_runnable;
}

SymbolTable* ScopeStack::GetTable() {
    return m_stack.top()->GetTable();
}

bool ScopeStack::IsntRunnable() {
    return m_stack.top()->IsntRunnable();
}
