#include "ScopeStack.hpp"

ScopeStack::ScopeStack() {
    m_stack.push_back(new GenScope());
    base = m_stack.back()->GetTable();
}

ScopeStack::ScopeStack(const ScopeStack &old) {
   for(auto scope : old.m_stack) {
       GenScope *s = (GenScope*)scope;
       SymbolTable *tbl = s->GetTable();
       if (s->GetParent() != nullptr) {
           tbl = s->GetParent()->GetTable();
       }
       m_stack.push_back(new GenScope(s->GetType(), tbl, s->GetParent()));
       if (m_stack.size() == 1) {
           base = m_stack.back()->GetTable();
       }
   }
}

ScopeStack::~ScopeStack() {
    for(auto scope : m_stack) {
        delete scope;
    }
}

void ScopeStack::CreateScope(string type) {
    Scope *n_scope = nullptr;
    if (type == GEN_SCOPE) {
        n_scope = new GenScope(GetTable(), m_stack.back());
    }
    else {
        n_scope = new GenScope(base, m_stack.back());
    }

    m_override = false;
    n_scope->SetRunnableState(true);
    m_stack.push_back(n_scope);
}

void ScopeStack::DestroyScope() {
    delete m_stack.back();
    m_stack.pop_back();
}

void ScopeStack::CopyScopeBaseSymbolTable(const ScopeStack &other) {
    base->CopyTable(other.base, true);
}

SymbolTable* ScopeStack::GetTable() {
    if (m_stack.size() == 0) {
        return nullptr;
    }
    return m_stack.back()->GetTable();
}

string ScopeStack::GetScopeType() {
    return m_stack.back()->GetType();
}

size_t ScopeStack::Size() {
    return m_stack.size();
}