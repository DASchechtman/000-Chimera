#include "GenScope.hpp"

void GenScope::SetFields(Memory &mem, Scope *parent, string scope_type) {
    m_scope_memory = mem;
    m_parent = parent;
    this->scope_type = scope_type;
}

GenScope::GenScope() {
    m_type = GEN_SCOPE;
}

GenScope::GenScope(Memory &mem_space, Scope *parent)
{
    scope_type = GEN_SCOPE;
    m_parent = parent;
    m_scope_memory.LinkOtherMemory(&mem_space);
}

GenScope::GenScope(string type, Memory &mem_space, Scope *parent) {
    m_parent = parent;
    m_scope_memory.LinkOtherMemory(&mem_space);
    scope_type = type;
}

GenScope::~GenScope() {}

Memory& GenScope::GetMemory() {
    return m_scope_memory;
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

GenScope* GenScope::Clone() {
    GenScope *new_scope = new GenScope();
    new_scope->SetFields(m_scope_memory, m_parent, scope_type);
    return new_scope;
}