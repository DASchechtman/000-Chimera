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
    m_override = false;

    if (type == IF_SCOPE || type == ELIF_SCOPE || type == ELSE_SCOPE) {
        n_scope = new IfScope(type, GetTable(), m_stack.top());
    }
    else if (type == GEN_SCOPE) {
        n_scope = new GenScope(GetTable(), m_stack.top());
    }
    else if (type == WHILE_LOOP_SCOPE) {
        n_scope = new GenScope(WHILE_LOOP_SCOPE, GetTable(), m_stack.top());
    }

    n_scope->SetRunnableState(m_next_scope_runnable);
    m_stack.push(n_scope);
}

void ScopeStack::DestroyScope() {
    size_t num_o_pops = m_stack.top()->NumOfScopeMembers();
    for(size_t i = 0; i < num_o_pops; i++) {
        delete m_stack.top();
        m_stack.pop();
        m_next_scope_runnable = !m_stack.top()->IsntRunnable();
    }
}

void ScopeStack::SetNextScopeRunStat(bool is_runnable) {
    m_next_scope_runnable = is_runnable;
}

void ScopeStack::MakeRunnable() {
    m_override = true;
}

SymbolTable* ScopeStack::GetTable() {
    return m_stack.top()->GetTable();
}

bool ScopeStack::IsntRunnable() {
    if (m_override) {
        return false;
    }
    return m_stack.top()->IsntRunnable();
}

bool ScopeStack::ParentIsntRunnable() {
    return m_stack.top()->ParentIsntRunnable();
}

string ScopeStack::GetScopeType() {
    return m_stack.top()->GetType();
}

size_t ScopeStack::Size() {
    return m_stack.size();
}