#include "ScopeStack.hpp"

ScopeStack::ScopeStack() {
    m_stack.push_back(new GenScope());
    base = &m_stack.front()->GetMemory();
}

ScopeStack::ScopeStack(const ScopeStack &old) {
    for(auto scope : old.m_stack) {
        m_stack.push_back(scope->Clone());
    }
    base = &m_stack.front()->GetMemory();
}

ScopeStack::~ScopeStack() {
    for (auto scope : m_stack) {
        delete scope;
    }
}

void ScopeStack::CreateScope(string type) {
  
    if (type == GEN_SCOPE) {
        Memory &mem = m_stack.back()->GetMemory();
        m_stack.push_back(new GenScope(mem, m_stack.back()));
    }
    else {
        Memory &mem = m_stack.front()->GetMemory();
        m_stack.push_back(new GenScope(mem, m_stack.back()));
    }

    m_override = false;
}

void ScopeStack::DestroyScope() {
    delete m_stack.back();
    m_stack.pop_back();
}

void ScopeStack::CopyScopeBaseSymbolTable(const ScopeStack &other) {
    base->LinkOtherMemory(other.base);
}

Memory& ScopeStack::GetMemory() {
    return m_stack.back()->GetMemory();
}

string ScopeStack::GetScopeType() {
    return m_stack.back()->GetType();
}

size_t ScopeStack::Size() {
    return m_stack.size();
}