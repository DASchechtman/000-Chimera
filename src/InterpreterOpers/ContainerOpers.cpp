#include "ContainerOpers.hpp"
#include "../Types/Containers/Lists/List.hpp"
#include "../Types/Containers/Maps/Map.hpp"
#include "../Types/Number/Derived/Int.hpp"
#include "../Types/Composables/ComposableOr/ChimeraUnion.hpp"
#include "DisplayErrors.hpp"
#include <iostream>

using namespace std;

ChimeraObject* GetObjContents(ChimeraObject *data) {
    ChimeraObject *address = data;
    if (data->GetGeneralType() == UNION_DATA_TYPE) {
        address = ((ChimeraUnion*)data)->GetObj();
    }
    return address;
}

VAR_TYPES TypeNameToType(string type_name) {
    VAR_TYPES type = UNDEFINED_DATA_TYPE;

    if (type_name == INT_TYPE_NAME) {
        type = INT_DATA_TYPE;
    }
    else if (type_name == FLOAT_TYPE_NAME) {
        type = FLOAT_DATA_TYPE;
    }
    else if (type_name == DOUBLE_TYPE_NAME) {
        type = DOUBLE_DATA_TYPE;
    }
    else if (type_name == CHAR_TYPE_NAME) {
        type = CHAR_DATA_TYPE;
    }
    else if (type_name == BOOL_TYPE_NAME) {
        type = BOOL_DATA_TYPE;
    }
    else if (type_name == STRING_TYPE_NAME) {
        type = STRING_DATA_TYPE;
    }
    else if (type_name == UNKNOWN_TYPE_NAME) {
        type = UNKNOWN_DATA_TYPE;
    }

    return type;
}

string MakeArray(string list, string list_type, VarTbl tbl) {
    VAR_TYPES type = TypeNameToType(list_type);
    if (tbl->Has(list)) {
        cout << "Error: " << list << " already exists.\n";
        return EMPTY_VAR_NAME;
    }
    else if (type == UNDEFINED_DATA_TYPE) {
        cout << "Error: setting list to unsupported type.\n";
        return EMPTY_VAR_NAME;
    }

    List *new_list = new List();
    return tbl->AddEntry(list, new_list);
}

string MakeArray(string list, vector<string> list_type, VarTbl tbl) {
    vector<VAR_TYPES> type;

    for(auto type_name : list_type) {
        type.push_back(TypeNameToType(type_name));
    }

    if (tbl->Has(list)) {
        cout << "Error: " << list << " already exists.\n";
        return EMPTY_VAR_NAME;
    }
    else if (type.empty()) {
        cout << "Error: setting list to unsupported type.\n";
        return EMPTY_VAR_NAME;
    }

    List *new_list = new List(type);
    return tbl->AddEntry(list, new_list);
}

string MakeMap(string map, string key_type_name, string val_type_name, VarTbl tbl) {
    VAR_TYPES key_type = STRING_DATA_TYPE;
    VAR_TYPES declared_type = TypeNameToType(key_type_name);
    VAR_TYPES val_type = TypeNameToType(val_type_name);

    if (tbl->Has(map)) {
        cout << "Error: " << map << " already exists.\n";
        return EMPTY_VAR_NAME;
    } 
    else if (
        key_type == UNDEFINED_DATA_TYPE 
        || val_type == UNDEFINED_DATA_TYPE
        || declared_type == UNDEFINED_DATA_TYPE
        ) {
            cout << "Error: using undefined type to make map.\n";
            return EMPTY_VAR_NAME;
    }

    Map *new_map = new Map(key_type, val_type);
    new_map->SetDeclaredType(declared_type);
    return tbl->AddEntry(map, new_map);
}

string PutInArray(string container, string item, VarTbl tbl) {
    if (!tbl->Has(container) || !tbl->Has(item)) {
        ShowErr(tbl, "Error: variable doesn't exist", container, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = GetObjContents(tbl->GetEntry(container));

    if (obj->GetType() != LIST_DATA_TYPE) {
        cout << "Error: initializing array to unsupported type.\n";
        return EMPTY_VAR_NAME;
    }

    List *array = (List*)obj;
    ChimeraObject *item_obj = GetObjContents(tbl->GetEntry(item));

    if (array->PutItem(item_obj) == FAIL) {
        return EMPTY_VAR_NAME;
    }

    return item;
}

string PutInMap(string map, string key, string item, VarTbl tbl) {
    bool map_exists = tbl->Has(map);
    bool key_exists = tbl->Has(key);
    bool item_exists = tbl->Has(item);

    if (!map_exists || !key_exists || !item_exists) {
        ShowErr(tbl, "Error: variable doesn't exist", map, key, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container = GetObjContents(tbl->GetEntry(map));

    if (container->GetType() != MAP_DATA_TYPE) {
        cout << "Error: cannot add data to map.\n";
        return EMPTY_VAR_NAME;
    }

    Map *map_obj = (Map*) container;
    ChimeraObject *key_obj = GetObjContents(tbl->GetEntry(key));
    ChimeraObject *item_obj = GetObjContents(tbl->GetEntry(item));

    string key_val = key_obj->ToStr();

    if (map_obj->SetItem(key_val, item_obj) == FAIL) {
        return EMPTY_VAR_NAME;
    }

    return item;
}

string GetFromContainer(string container, string index, VarTbl tbl) {
    if (!tbl->Has(container) || !tbl->Has(index)) {
        ShowErr(tbl, "Error: variable doesn't exist", container, index);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *data_struct = GetObjContents(tbl->GetEntry(container));
    ChimeraObject *index_obj = GetObjContents(tbl->GetEntry(index));

    

    if (data_struct->GetType() == LIST_DATA_TYPE) {
        int64 index_val;
        if (index_obj->Get(index_val) == FAIL) {
            return EMPTY_VAR_NAME;
        }
        ChimeraObject *data = ((List*) data_struct)->GetItem(index_val);

        if (data == nullptr) {
            cout << "Error: item in list does not exist\n";
            return EMPTY_VAR_NAME;
        }
        else if (data->GetGeneralType() == COLLECTION_DATA_TYPE) {
            return tbl->AddOrUpdateRef(container+index, data, true);
        }

        return tbl->AddEntry(EMPTY_VAR_NAME, data->Clone());
    }
    else if (data_struct->GetType() == MAP_DATA_TYPE) {
        
        string key = index_obj->ToStr();
        ChimeraObject *data = ((Map*) data_struct)->GetItem(key);
        
        if (data == nullptr) {
            cout << "Error: item in map does not exist\n";
            return EMPTY_VAR_NAME;
        }
        else if (data->GetGeneralType() == COLLECTION_DATA_TYPE) {
            return tbl->AddOrUpdateRef(container+index, data, true);
        }

        return tbl->AddEntry(EMPTY_VAR_NAME, data->Clone());
    }
    cout << "Error: cannot get data from non-container.\n";
    return EMPTY_VAR_NAME;
}

string SetInContainer(string container, string index, string item, VarTbl tbl) {
    bool container_exists = tbl->Has(container);
    bool index_exists = tbl->Has(index);
    bool item_exists = tbl->Has(item);

    if (!container_exists || !index_exists || !item_exists) {
        ShowErr(tbl, "Error: variable doesn't exist", container, index, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container_obj = GetObjContents(tbl->GetEntry(container));

    if (container_obj->GetType() == LIST_DATA_TYPE) {
        int64 index_val;
        ChimeraObject *index_obj = GetObjContents(tbl->GetEntry(index));
        ChimeraObject *item_obj = GetObjContents(tbl->GetEntry(item));
        index_obj->Get(index_val);

        int err = ((List*) container_obj)->SetItem(index_val, item_obj);
        return err == FAIL ? EMPTY_VAR_NAME : item;
    }
    else if (container_obj->GetType() == MAP_DATA_TYPE) {
        ChimeraObject *index_obj = GetObjContents(tbl->GetEntry(index));
        if (((Map*) container_obj)->GetDeclaredType() != index_obj->GetType()) {
            return EMPTY_VAR_NAME;
        }

        ChimeraObject *item_obj = GetObjContents(tbl->GetEntry(item));
        int err = ((Map*) container_obj)->SetItem(index_obj->ToStr(), item_obj);
        return err == FAIL ? EMPTY_VAR_NAME : item;
    }

    cout << "Error: cannot set data into non-container type.\n";
    return EMPTY_VAR_NAME;
}

string ReassignContainer(string old, string latest, VarTbl tbl) {
    if (!tbl->Has(old) || !tbl->Has(latest)) {
        ShowErr(tbl, "Error: variable doesn't exist", old, latest);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *old_container = GetObjContents(tbl->GetEntry(old));
    ChimeraObject *new_container = GetObjContents(tbl->GetEntry(latest));

    if (
        old_container->GetGeneralType() == COLLECTION_DATA_TYPE
        && new_container->GetGeneralType() == COLLECTION_DATA_TYPE
        && old_container->GetType() == new_container->GetType()
    ) {
        ((Container*) old_container)->SetToNewContainer((Container*) new_container);
        return old;
    }

    cout << "Error: cannot perform assignment of one container to another.\n";
    return EMPTY_VAR_NAME;
}

string GetContainerSize(string container, VarTbl tbl) {
    if (!tbl->Has(container)) {
        ShowErr(tbl, "Error: variable doesn't exist", container);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container_obj = GetObjContents(tbl->GetEntry(container));

    if(container_obj->GetGeneralType() == COLLECTION_DATA_TYPE) {
        int64 size = (int64)((Container*) container_obj)->Size();
        Int *list_size = new Int(size);
        return tbl->AddEntry(EMPTY_VAR_NAME, list_size);
    }
    cout << "Error: cannot get size of non-container.\n";
    return EMPTY_VAR_NAME;
}