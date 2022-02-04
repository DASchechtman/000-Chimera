#pragma once

#include "../Container.hpp"
#include <vector>
#include <list>
#include <functional>
#include <string>
#include <cmath>
#include <type_traits>
#include <iostream>

using namespace std;

// a means to keep track of both the key and data values in the event of a key collision
struct MapItem {
    ChimeraObject *val = nullptr;
    struct Key {
        int64 i;
        float f;
        dbl128 d;
        char32_t c;
        string s;
        bool b;
    } key;
    bool was_cloned = false;

    bool EqualsKey(int64 index) {
        return key.i == index;
    }

    bool EqualsKey(float index) {
        return key.f == index;
    }

    bool EqualsKey(dbl128 index) {
        return key.d == index;
    }

    bool EqualsKey(char32_t index) {
        return key.c == index;
    }

    bool EqualsKey(string index) {
        return key.s == index;
    }

    bool EqualsKey(bool index) {
        return key.b == index;
    }

    MapItem() {};

    MapItem(ChimeraObject *old_val, Key old_key) {
        was_cloned = true;
        val = old_val->Clone();
        key = old_key;
    }

    MapItem(const MapItem &old) {
        was_cloned = true;
        val = old.val->Clone();
        key = old.key;
    };

    ~MapItem() {
        if (val != nullptr && was_cloned) {
            delete val;
        }
    }
};

class Map : public Container {
public:
    Map(VAR_TYPES key_type, VAR_TYPES val_type);
    ~Map();

private:
    // didn't use the built in std::map because I needed controll
    // of the value in empty indexes
    vector<list<MapItem>*> m_map;
    VAR_TYPES m_key_type = UNDEFINED_DATA_TYPE;
    VAR_TYPES m_val_type = UNDEFINED_DATA_TYPE;
    VAR_TYPES m_declared_type = UNDEFINED_DATA_TYPE;
    size_t m_size = 0;

    // used to determine when to resize the map and rehash all it's keys
    size_t free_hash_indexes;

    size_t Hash(ChimeraObject *item);

    // makes sure that the key and val types match for what the map is set up
    // to store
    bool MatchingDataTypes(VAR_TYPES key_type, VAR_TYPES val_type);
    void ResizeIfNeeded(size_t new_size);
    int MapData(size_t hash, VAR_TYPES key_type, ChimeraObject *data, MapItem item);
    void RehashIndexes();
    void FreeHashIndex(list<MapItem> *index);

    int SetData(string index, ChimeraObject *data, VAR_TYPES type, MapItem &item);

    template<class T>
    int SetData(T index, ChimeraObject *data, VAR_TYPES type, MapItem &item);

    template<class T>
    ChimeraObject* GetData(size_t hash, T index);

    template<class T>
    size_t NonStrHash(T index);
    size_t StrHash(string index);

protected:
public:

    int PutItem(ChimeraObject *data);
    size_t Size();
    void SetToNewContainer(Container *new_container);
    void SetDeclaredType(VAR_TYPES type);
    VAR_TYPES GetDeclaredType();

    int SetItem(int64 index, ChimeraObject *data);
    int SetItem(float index, ChimeraObject *data);
    int SetItem(dbl128 index, ChimeraObject *data);
    int SetItem(char32_t index, ChimeraObject *data);
    int SetItem(string index, ChimeraObject *data);
    int SetItem(bool index, ChimeraObject *data);

    ChimeraObject* GetItem(int64 index);
    ChimeraObject* GetItem(float index);
    ChimeraObject* GetItem(dbl128 index);
    ChimeraObject* GetItem(char32_t index);
    ChimeraObject* GetItem(string index);
    ChimeraObject* GetItem(bool index);

    void Clear();

    string ToStr();
    int64 ToInt();
    float ToFloat();
    dbl128 ToDouble();
    char32_t ToChar();
    bool ToBool();

    ChimeraObject* Clone();
};

template<class T>
size_t Map::NonStrHash(T index) {
    int64 to_hash = (int64)round(index) % m_map.size();;
    return (size_t)abs(to_hash);
}

template<class T>
int Map::SetData(T index, ChimeraObject *data, VAR_TYPES type, MapItem &item) {
    int ret_code = FAIL;

    
        size_t hash = NonStrHash(index);
        ret_code =  MapData(hash, type, data, item);
        m_size = ret_code == SUCCEED ? m_size+1 : m_size;
    
    
    
    return SUCCEED;
}

template<class T>
ChimeraObject* Map::GetData(size_t hash, T index) {
    ChimeraObject* item = nullptr;
    list<MapItem> *hash_location = m_map[hash];

    if (hash_location != nullptr) {
        auto start = hash_location->begin();
        auto end = hash_location->end();

        while(!start->EqualsKey(index) && start != end) {
            start++;
        }

        if (start != end) {
            item = start->val;
        }
    } else {
        cout << "Error: element doesn't exist in map\n";
    }

    return item;
}