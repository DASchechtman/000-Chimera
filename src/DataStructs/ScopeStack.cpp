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
    Scope *n_scope = nullptr;

    if (type == IF_SCOPE || type == ELIF_SCOPE || type == ELSE_SCOPE) {
        n_scope = new IfScope(type, GetTable());
    }
    else if (type == GEN_SCOPE) {
        if(m_stack.size() == 1) {
            IfScope::ClearGroups();
        }
        n_scope = new GenScope(GetTable());
    }

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

string ScopeStack::GetScopeType() {
    return m_stack.top()->GetType();
}
