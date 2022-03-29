#pragma once

#include <map>
#include <string>
#include <type_traits>
#include <cmath>
#include "../Types/ChimeraObject.hpp"
#include "../Types/Bool/Bool.hpp"
#include "../Types/Number/Derived/Char.hpp"
#include "../Types/Number/Derived/Double.hpp"
#include "../Types/Number/Derived/Float.hpp"
#include "../Types/Number/Derived/Int.hpp"
#include "../Types/Text/Derived/String.hpp"

using namespace std;

struct TableItem
{
    ChimeraObject *item;
    bool is_temp;
    bool is_ref;
    bool is_weak;
    string created_from;

    TableItem(){};

    TableItem(const TableItem &old)
    {
        item = old.item;
        is_temp = old.is_temp;
        is_ref = old.is_ref;
        created_from = old.created_from;
    }
};

const string REF_SIGNLE = "a-ref";

class SymbolTable
{
private:
    map<string, TableItem> m_table;
    map<ChimeraObject *, uint32_t> m_ref_counter;
    unsigned long long m_cur_reg = 0;
    unsigned long long m_reg = 0;
    bool m_is_being_copied = false;

    void UpdateCurReg();
    bool DecreaseRefCount(ChimeraObject *object);

    template<class T>
    string GetConstEntry(T data, false_type);

    template<class T>
    string GetConstEntry(T data, true_type);
    string KeyToString(int64 key);
    

protected:
public:
    SymbolTable();
    SymbolTable(SymbolTable *old);
    ~SymbolTable();

    bool Has(string var_id);
    bool CameFromVar(string var_id);
    bool IsRef(string var_id);
    bool IsTemp(string var_id);
    void SetParent(string var_id, string parent_id);
    void SetCopyStat(bool is_copying);
    string GetParent(string var_id);
    string AddEntry(string var_id, ChimeraObject *object);
    string OverwriteEntry(string var_id, ChimeraObject *object);
    string AddOrUpdateRef(string var_id, ChimeraObject *object, bool is_weak_ref = false);
    ChimeraObject *GetEntry(string var_id);
    void RemoveEntry(string var_id);
    void FreeTempItems();
    void CopyTable(SymbolTable *old, bool full_copy = false);

    template <class T>
    string GetConstEntry(T data);
};

template <class T>
string SymbolTable::GetConstEntry(T data)
{
    return GetConstEntry(data, is_same<T, string>());
}

template<class T>
string SymbolTable::GetConstEntry(T data, true_type) {
    string key = data.empty() ? "empty" : "str-" + data + '!';

    if (!Has(key))
    {
        
        ChimeraObject *val = new String();
        val->Set(data);
        val->SetConstStatus(true);
        AddEntry(key, val);
    }

    return key;
}

template<class T>
string SymbolTable::GetConstEntry(T data, false_type) {
    
    string key;

    bool is_bool = is_same<T, bool>::value;
    bool is_char = is_same<T, char32_t>::value;
    if (is_bool)
    {
        key = data ? "true!" : "false!";
    }
    else if (is_char) {
        key = "chr" + to_string(data) + '!';
    }
    else {
        key = to_string(data) + '!';
    }

    if (!Has(key))
    {
        ChimeraObject *val = nullptr;
        const int INT_BRANCH = 1;
        const int FLOAT_BRANCH = 2;
        const int DOUBLE_BRANCH = 3;
        const int CHAR_BRANCH = 4;
        const int BOOL_BRANCH = 5;
        int branch = 0;

        branch += INT_BRANCH * is_same<T, int64>::value;
        branch += FLOAT_BRANCH * is_same<T, float>::value;
        branch += DOUBLE_BRANCH * is_same<T, dbl128>::value;
        branch += CHAR_BRANCH * is_same<T, char32_t>::value;
        branch += BOOL_BRANCH * is_same<T, bool>::value;

        switch(branch) {
            case INT_BRANCH: {
                val = new Int();
                break;
            }
            case FLOAT_BRANCH: {
                val = new Float();
                break;
            }
            case DOUBLE_BRANCH: {
                val = new Double();
                break;
            }
            case CHAR_BRANCH: {
                val = new Char();
                break;
            }
            case BOOL_BRANCH: {
                val = new Bool();
                break;
            }
            default: {}
        }

        val->Set(data);
        val->SetConstStatus(true);
        AddEntry(key, val);
    }

    return key;
}