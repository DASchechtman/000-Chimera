#pragma once

#include "../Memory.hpp"
#include "Scope.hpp"
#include <string>

using namespace std;

/*
A general purpose type that doesn't have any functionality beyond being a placeholder scope when no other scope
is a suitable tool to use
*/

class GenScope : public Scope {
private:
    Memory m_scope_memory;
    bool m_runnable_scope = true;
    Scope *m_parent = nullptr;
    string scope_type;

    void SetFields(Memory &mem, Scope *parent, string scope_type);

protected:
public:

    GenScope();
    GenScope(Memory &mem_space, Scope *parent);
    GenScope(string type, Memory &mem_space, Scope *parent);
    ~GenScope();

    Memory& GetMemory();
    bool IsntRunnable();
    bool ParentIsntRunnable();
    void SetRunnableState(bool is_runnable);
    string GetType();
    Scope *GetParent();
    size_t NumOfScopeMembers();

    GenScope *Clone();
};