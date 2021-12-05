#pragma once

#include "SymbolTable.hpp"
#include <string>

using namespace std;

const string PLACE_HOLDER_NAME = "#";

class Scope {
private:
    SymbolTable m_table;
    bool m_runnable_scope = true;
protected:
public:

    Scope();
    Scope(SymbolTable *table);

    SymbolTable* GetTable();
    bool IsntRunnable();
    void SetRunnableState(bool is_runnable);
};