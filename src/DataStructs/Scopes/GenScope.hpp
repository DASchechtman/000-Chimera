#pragma once

#include "../SymbolTable.hpp"
#include "Scope.hpp"
#include <string>

using namespace std;

class GenScope : public Scope {
private:
    SymbolTable m_table;
    bool m_runnable_scope = true;
protected:
public:

    GenScope();
    GenScope(SymbolTable *table);
    ~GenScope();

    SymbolTable* GetTable();
    bool IsntRunnable();
    void SetRunnableState(bool is_runnable);
    string GetType();
};