#include "Memory.hpp"
#include "../Types/Number/Derived/Int.hpp"
#include "../Types/Number/Derived/Float.hpp"
#include "../Types/Number/Derived/Double.hpp"
#include "../Types/Number/Derived/Char.hpp"
#include "../Types/Text/Derived/String.hpp"
#include "../Types/Bool/Bool.hpp"
#include "../Types/Containers/Lists/List.hpp"
#include "../Types/Containers/Maps/Map.hpp"
#include "../Types/Composables/ComposableOr/ChimeraUnion.hpp"
#include "../Types/Functions/Funcs.hpp"

string Memory::CreateConstKey(string data) {
    return data.empty() ? "empty" : "str-" + data + "!";
}

string Memory::CreateData(string &data_name, VAR_TYPES data_type) {
    string created_var_name;

    ChimeraObject *data = nullptr;

    // avoids memory leaks because trying to add something
    // already in the symbol table results in the table ignoring
    // the input value. and so nothing is tracking that memroy
    if (m_var_memory.Has(data_name)) {
        return data_name;
    }

    switch(data_type) {
        case INT_DATA_TYPE: {
            data = new Int();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case FLOAT_DATA_TYPE: {
            data = new Float();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case DOUBLE_DATA_TYPE: {
            data = new Double();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case CHAR_DATA_TYPE: {
            data = new Char();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case STRING_DATA_TYPE: {
            data = new String();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case BOOL_DATA_TYPE: {
            data = new Bool();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case LIST_DATA_TYPE: {
            data = new List();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        case MAP_DATA_TYPE: {
            data = new Map();
            created_var_name = m_var_memory.AddEntry(data_name, data);
            break;
        }
        default: {}
    }

    return created_var_name;
}

string Memory::CreateData(string &data_name, string &data_type) {
    string ret_name;
    if (data_type == INT_TYPE_NAME) {
        ret_name = CreateData(data_name, INT_DATA_TYPE);
    }
    else if (data_type == FLOAT_TYPE_NAME) {
        ret_name = CreateData(data_name, FLOAT_DATA_TYPE);
    }
    else if (data_type == DOUBLE_TYPE_NAME) {
        ret_name = CreateData(data_name, DOUBLE_DATA_TYPE);
    }
    else if (data_type == CHAR_TYPE_NAME) {
        ret_name = CreateData(data_name, CHAR_DATA_TYPE);
    }
    else if (data_type == BOOL_TYPE_NAME) {
        ret_name = CreateData(data_name, BOOL_DATA_TYPE);
    }
    else if (data_type == STRING_TYPE_NAME) {
        ret_name = CreateData(data_name, STRING_DATA_TYPE);
    }
    else if (data_type == LIST_TYPE_NAME) {
        ret_name = CreateData(data_name, LIST_DATA_TYPE);
    }
    else if (data_type == MAP_TYPE_NAME) {
        ret_name = CreateData(data_name, MAP_DATA_TYPE);
    }
    return ret_name;
}

string Memory::CreateUnionData(string &data_name, vector<string> &allowed_types, ChimeraObject *data) {
    if (m_var_memory.Has(data_name)) { return data_name; }
    return m_var_memory.AddEntry(data_name, new ChimeraUnion(allowed_types, data));
}

string Memory::CreateFunc(string &name, size_t start, string &type, COMMANDS func_type) {
    if (m_var_memory.Has(name)) { return name; }
    return m_var_memory.AddEntry(name, new ChmrFunc(start, type, func_type, name));
}

ChimeraObject* Memory::GetData(MemStates mode, string &data_name) {
    ChimeraObject *obj = nullptr;

    while(m_ref_map.find(data_name) != m_ref_map.end()) {
        data_name = m_ref_map[data_name];
    }

    bool has_data = m_var_memory.Has(data_name);

    if (m_transfered_data.find(data_name) != m_transfered_data.end()) {
        obj = m_transfered_data[data_name];
    }
    else if (!has_data && m_mem_next != nullptr) {
        obj = m_mem_next->GetData(ORIGINAL, data_name);
    }
    else if (!has_data && m_mem_next == nullptr) {
        return nullptr;
    }
    else {
        obj = m_var_memory.GetEntry(data_name);
    }

    if (mode == CLONED && obj != nullptr) {
        obj = obj->Clone();
        data_name = m_var_memory.AddEntry(EMPTY_VAR_NAME, obj);
    }

    return obj;
}

void Memory::LinkOtherMemory(Memory *mem) {
    m_mem_next = mem;
}

bool Memory::IsTemp(string &data_name) {
    return m_var_memory.Has(data_name) && m_var_memory.IsTemp(data_name);
}

bool Memory::IsConst(string &data_name) {
    bool is_const = false;

    if (!m_var_memory.Has(data_name) && m_mem_next != nullptr) {
        is_const = m_mem_next->IsConst(data_name);
    }
    
    is_const = m_var_memory.IsConst(data_name);
    return is_const;
}

bool Memory::IsRef(string &data_name) {
    bool is_ref = m_ref_map.find(data_name) != m_ref_map.end();
    if (!is_ref && m_mem_next != nullptr) {
        is_ref = m_mem_next->IsRef(data_name);
    }
    return is_ref;
}

void Memory::CreateRef(const string &ref, const string &var) {
    m_ref_map[ref] = var;
}

void Memory::EraseData(const string &data_name) {
    m_var_memory.RemoveEntry(data_name);
}

int Memory::CastData(string &data_name, string &type) {
    ChimeraObject *var = GetData(ORIGINAL, data_name);
    if (var == nullptr) {
        data_name = EMPTY_VAR_NAME;
        return FAIL;
    }

    ChimeraObject *casted = var->ConvertTo(type);

    if (casted == nullptr) {
        type = EMPTY_VAR_NAME;
        return FAIL;
    }

    data_name = m_var_memory.AddEntry(EMPTY_VAR_NAME, casted);
    return SUCCEED;
}

void Memory::CleanUp() {
    m_var_memory.FreeTempItems();
}

bool Memory::HasData(string &data_name) {
    bool has = HasDataInLocalScope(data_name);
    if (!has && m_mem_next != nullptr) {
        has = m_mem_next->HasData(data_name);
    }
    return has;
}

bool Memory::HasDataInLocalScope(string &data_name) {
    return (
        m_var_memory.Has(data_name)
        || m_transfered_data.find(data_name) != m_transfered_data.end()
        || m_ref_map.find(data_name) != m_ref_map.end()
    );
}

void Memory::TransferData(string &data_name, string &ref_name, Memory &other_memory, MemStates (*Mode)(string &name, Memory &mem)) {
    if (other_memory.HasData(data_name)) {
        MemStates mode = (*Mode)(data_name, other_memory);
        
        if (mode == CLONED) {
            ChimeraObject *obj = other_memory.GetData(ORIGINAL, data_name);
            if (m_var_memory.Has(ref_name)) { return; }
            m_var_memory.AddEntry(ref_name, obj->Clone());
            return;
        }

        m_transfered_data[ref_name] = other_memory.GetData(mode, data_name);
    }
}