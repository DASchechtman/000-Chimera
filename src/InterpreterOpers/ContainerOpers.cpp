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

    if (tbl.HasData(list)) {
        cout << "Error: " << list << " already exists.\n";
        return EMPTY_VAR_NAME;
    }
    else if (type == UNDEFINED_DATA_TYPE) {
        cout << "Error: setting list to unsupported type.\n";
        return EMPTY_VAR_NAME;
    }

    return tbl.CreateData(list, LIST_DATA_TYPE);
}

string MakeArray(string list, vector<string> list_type, VarTbl tbl) {
    
    if (tbl.HasData(list)) {
        cout << "Error: " << list << " already exists.\n";
        return EMPTY_VAR_NAME;
    }

    return tbl.CreateData(list, LIST_DATA_TYPE);
}

string MakeMap(string map, string key_type_name, string val_type_name, VarTbl tbl) {

    if (tbl.HasData(map)) {
        cout << "Error: " << map << " already exists.\n";
        return EMPTY_VAR_NAME;
    } 

    return tbl.CreateData(map, MAP_DATA_TYPE);
}

string PutInArray(string container, string item, VarTbl tbl) {
    if (!tbl.HasData(container) || !tbl.HasData(item)) {
        ShowErr(tbl, "Error: variable doesn't exist", container, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj = GetObjContents(tbl.GetData(ORIGINAL, container));

    if (obj->GetType() != LIST_DATA_TYPE) {
        cout << "Error: initializing array to unsupported type.\n";
        return EMPTY_VAR_NAME;
    }

    List *array = (List*)obj;
    ChimeraObject *item_obj = GetObjContents(tbl.GetData(ORIGINAL, item));

    if (array->PutItem(item_obj) == FAIL) {
        return EMPTY_VAR_NAME;
    }

    return item;
}

string PutInMap(string map, string key, string item, VarTbl tbl) {
    bool map_exists = tbl.HasData(map);
    bool key_exists = tbl.HasData(key);
    bool item_exists = tbl.HasData(item);

    if (!map_exists || !key_exists || !item_exists) {
        ShowErr(tbl, "Error: variable doesn't exist", map, key, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container = GetObjContents(tbl.GetData(ORIGINAL, map));

    if (container->GetType() != MAP_DATA_TYPE) {
        cout << "Error: cannot add data to map.\n";
        return EMPTY_VAR_NAME;
    }

    Map *map_obj = (Map*) container;
    ChimeraObject *key_obj = GetObjContents(tbl.GetData(ORIGINAL, key));
    ChimeraObject *item_obj = GetObjContents(tbl.GetData(ORIGINAL, item));

    string key_val = key_obj->ToStr();

    if (map_obj->SetItem(key_val, item_obj) == FAIL) {
        return EMPTY_VAR_NAME;
    }

    return item;
}

string GetFromContainer(string container, string index, VarTbl tbl) {
    if (!tbl.HasData(container) || !tbl.HasData(index)) {
        ShowErr(tbl, "Error: variable doesn't exist", container, index);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *data_struct = GetObjContents(tbl.GetData(ORIGINAL, container));
    ChimeraObject *index_obj = GetObjContents(tbl.GetData(ORIGINAL, index));

    
    string empty_name = EMPTY_VAR_NAME;
    
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
            string index_name = tbl.CreateData(empty_name, data->GetType());
            ((Container*) tbl.GetData(ORIGINAL, index_name))->SetToNewContainer((Container*)data);
            return index_name;
        }

        string index_name = tbl.CreateData(empty_name, data->GetType());
        tbl.InitData(data, index_name);

        return index_name;
    }
    else if (data_struct->GetType() == MAP_DATA_TYPE) {
        
        string key = index_obj->ToStr();
        ChimeraObject *data = ((Map*) data_struct)->GetItem(key);
        
        if (data == nullptr) {
            cout << "Error: item in map does not exist\n";
            return EMPTY_VAR_NAME;
        }
        else if (data->GetGeneralType() == COLLECTION_DATA_TYPE) {
            string index_name = tbl.CreateData(empty_name, data->GetType());
            ((Container*) tbl.GetData(ORIGINAL, index_name))->SetToNewContainer((Container*)data);
            return index_name;;
        }

        string index_name = tbl.CreateData(empty_name, data->GetType());
        tbl.InitData(data, index_name);
        return index_name;
    }
    cout << "Error: cannot get data from non-container.\n";
    return EMPTY_VAR_NAME;
}

string SetInContainer(string container, string index, string item, VarTbl tbl) {
    bool container_exists = tbl.HasData(container);
    bool index_exists = tbl.HasData(index);
    bool item_exists = tbl.HasData(item);

    if (!container_exists || !index_exists || !item_exists) {
        ShowErr(tbl, "Error: variable doesn't exist", container, index, item);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container_obj = GetObjContents(tbl.GetData(ORIGINAL, container));

    if (container_obj->GetType() == LIST_DATA_TYPE) {
        int64 index_val;
        ChimeraObject *index_obj = GetObjContents(tbl.GetData(ORIGINAL, index));
        ChimeraObject *item_obj = GetObjContents(tbl.GetData(ORIGINAL, item));
        index_obj->Get(index_val);

        int err = ((List*) container_obj)->SetItem(index_val, item_obj);
        return err == FAIL ? EMPTY_VAR_NAME : item;
    }
    else if (container_obj->GetType() == MAP_DATA_TYPE) {
        ChimeraObject *index_obj = GetObjContents(tbl.GetData(ORIGINAL, index));
        ChimeraObject *item_obj = GetObjContents(tbl.GetData(ORIGINAL, item));

        int err = ((Map*) container_obj)->SetItem(index_obj->ToStr(), item_obj);
        return err == FAIL ? EMPTY_VAR_NAME : item;
    }

    cout << "Error: cannot set data into non-container type.\n";
    return EMPTY_VAR_NAME;
}

string ReassignContainer(string old, string latest, VarTbl tbl) {
    if (!tbl.HasData(old) || !tbl.HasData(latest)) {
        ShowErr(tbl, "Error: variable doesn't exist", old, latest);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *old_container = GetObjContents(tbl.GetData(ORIGINAL, old));
    ChimeraObject *new_container = GetObjContents(tbl.GetData(ORIGINAL, latest));

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
    if (!tbl.HasData(container)) {
        ShowErr(tbl, "Error: variable doesn't exist", container);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *container_obj = GetObjContents(tbl.GetData(ORIGINAL, container));

    if(container_obj->GetGeneralType() == COLLECTION_DATA_TYPE) {
        int64 size = (int64)((Container*) container_obj)->Size();
        string empty_name = EMPTY_VAR_NAME;
        string container_size = tbl.CreateData(empty_name, INT_DATA_TYPE);
        tbl.InitData(size, container_size);
        return container_size;
    }
    cout << "Error: cannot get size of non-container.\n";
    return EMPTY_VAR_NAME;
}

string RemoveFromContainer(string container, string item, VarTbl tbl) {
    if (!tbl.HasData(container) || !tbl.HasData(item)) {
        cout << "Error: cannot remove item from nonexistent container" << endl;
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_container = tbl.GetData(ORIGINAL, container);
    ChimeraObject *obj_item = tbl.GetData(ORIGINAL, item);

    if (obj_container->GetGeneralType() != COLLECTION_DATA_TYPE) {
        cout << "Error: cannot remove item from a non-collection type" << endl;
        return EMPTY_VAR_NAME;
    }

    ((Container*)obj_container)->RemoveItem(obj_item);

    return item;
}

string QueryContainer(string container, string item, VarTbl tbl) {
    if (!tbl.HasData(container) || !tbl.HasData(item)) {
        cout << "Error: cannot remove item from nonexistent container" << endl;
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_container = tbl.GetData(ORIGINAL, container);
    ChimeraObject *obj_item = tbl.GetData(ORIGINAL, item);

    if (obj_container->GetGeneralType() != COLLECTION_DATA_TYPE) {
        cout << "Error: cannot remove item from a non-collection type" << endl;
        return EMPTY_VAR_NAME;
    }

    bool res = ((Container*)obj_container)->HasItem(obj_item);

    return tbl.GetConstsData(res);
}