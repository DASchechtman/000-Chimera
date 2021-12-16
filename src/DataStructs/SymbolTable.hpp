#pragma once

#include <map>
#include <string>
#include "../Types/ChimeraObject.hpp"

using namespace std;

struct TableItem {
    ChimeraObject* item;
    bool is_temp;
    bool is_ref;
    string created_from;

    TableItem() {};

    TableItem(const TableItem &old) {
        item = old.item;
        is_temp = old.is_temp;
        is_ref = old.is_ref;
        created_from = old.created_from;
    }
};

const string REF_SIGNLE = "a-ref";

class SymbolTable {
private:
    map<string, TableItem> m_table;
    map<ChimeraObject*, uint32_t> m_ref_counter;
    unsigned long long m_cur_reg = 0;
    unsigned long long m_reg = 0;
    bool m_is_being_copied = false;

    void UpdateCurReg();
    bool DecreaseRefCount(ChimeraObject *object);
protected:


public:

    SymbolTable();
    SymbolTable (SymbolTable *old);
    ~SymbolTable();

    bool Has(string var_id);
    bool CameFromVar(string var_id);
    bool IsRef(string var_id);
    void SetParent(string var_id, string parent_id);
    void SetCopyStat(bool is_copying);
    string GetParent(string var_id);
    string AddEntry(string var_id, ChimeraObject *object);
    string AddOrUpdateRef(string var_id, ChimeraObject *object);
    ChimeraObject* GetEntry(string var_id);
    void RemoveEntry(string var_id);
    void FreeTempItems();
    void CopyTable(SymbolTable *old, bool full_copy = false);
};