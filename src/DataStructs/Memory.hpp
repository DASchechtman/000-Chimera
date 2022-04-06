#pragma once
#include "SymbolTable.hpp"
#include "../DataTypes.hpp"
#include "../Cmds.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

enum MemStates {
    CLONED,
    ORIGINAL
};

class Memory {
private:
    SymbolTable m_var_memory;
    Memory *m_mem_next = nullptr;
    Memory *m_mem_head = nullptr;
    map<string, string> m_ref_map;
    map<string, ChimeraObject*> m_transfered_data;

    string CreateConstKey(string data);
    
    template<class T>
    string CreateConstKey(T data);

public:
    string CreateData(string &data_name, VAR_TYPES data_type);
    string CreateData(string &data_name, string &data_type);
    string CreateUnionData(string &data_name, vector<string> &allowed_types, ChimeraObject *init_data);
    string CreateFunc(string &data_name, size_t start, string &ret_type, COMMANDS func_type);
    ChimeraObject* GetData(MemStates mode, string &data_name);
    void CreateRef(const string &ref, const string &var);
    void EraseData(const string &data_name);
    void LinkOtherMemory(Memory *mem);
    bool IsTemp(string &data_name);
    bool IsConst(string &data_name);
    bool IsRef(string &data_name);
    int CastData(string &data_name, string &type);
    void CleanUp();
    bool HasData(string &data_name);
    bool HasDataInLocalScope(string &name);
    void TransferData(string &data_name, string &ref_name, Memory &other_memory, MemStates (*Mode)(string &name, Memory &mem));
    VAR_TYPES GetDataType(string &data_name);

    template<class T>
    int InitData(T raw_data, string &mem_data_name);

    template<class T>
    string GetConstsData(T data);
};

template<class T>
int Memory::InitData(T raw_data, string &mem_data_name) {
    if (!m_var_memory.Has(mem_data_name)) {
        return FAIL;
    }

    return m_var_memory.GetEntry(mem_data_name)->Set(raw_data);
}

template<class T>
string Memory::GetConstsData(T data) {
    string key = CreateConstKey(data);
    
    Memory *copy = m_mem_head;

    if (copy == nullptr) {
        copy = m_mem_next;
        while(copy != nullptr && copy->m_mem_next != nullptr) {
            copy = copy->m_mem_next;
            if (copy->m_mem_head != nullptr) {
                m_mem_head = copy->m_mem_head;
                copy = copy->m_mem_head;
                break;
            }
        }

        if (copy == nullptr) {
            m_mem_head = this;
            copy = m_mem_head;
        }
    }

    ChimeraObject *const_data = copy->GetData(ORIGINAL, key);

    if (const_data == nullptr) {
        if (is_same<T, chmr_int>::value) {
            copy->CreateData(key, INT_DATA_TYPE);
        }
        else if (is_same<T, chmr_flt>::value) {
            copy->CreateData(key, FLOAT_DATA_TYPE);
        }
        else if (is_same<T, chmr_dbl>::value) {
            copy->CreateData(key, DOUBLE_DATA_TYPE);
        }
        else if (is_same<T, chmr_char>::value) {
            copy->CreateData(key, CHAR_DATA_TYPE);
        }
        else if (is_same<T, bool>::value) {
            copy->CreateData(key, BOOL_DATA_TYPE);
        }
        else if (is_same<T, string>::value) {
            copy->CreateData(key, STRING_DATA_TYPE);
        }
        copy->InitData(data, key);
    }

    return key;
}

template<class T>
string Memory::CreateConstKey(T data) {
    string key;

    if (is_same<T, bool>::value)
    {
        key = data ? "true" : "false";
    }
    else if (is_same<T, chmr_char>::value) {
        key = "chr" + to_string(data);
    }
    else if (is_same<T, chmr_flt>::value) {
        key = "f" + to_string(data);
    }
    else if (is_same<T, chmr_dbl>::value) {
        key = "d" + to_string(data);
    }
    else {
        key = "i" + to_string(data);
    }
    
    return key + '!';
}