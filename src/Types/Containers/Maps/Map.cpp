#include "Map.hpp"
#include <sstream>
#include <iostream>

using namespace std;

Map::Map() {
    free_hash_indexes = 10;
    for(size_t i = 0; i < free_hash_indexes; i++) {
        m_map.push_back(nullptr);
    }

    SetType(MAP_DATA_TYPE);
    SetGeneralType(COLLECTION_DATA_TYPE);
}

Map::Map(VAR_TYPES key_type, VAR_TYPES val_type) : m_key_type(key_type),
                                                   m_val_type(val_type),
                                                   free_hash_indexes(10)
{
    SetType(MAP_DATA_TYPE);
    SetGeneralType(COLLECTION_DATA_TYPE);

    for (size_t i = 0; i < free_hash_indexes; i++)
    {
        m_map.push_back(nullptr);
    }
}

Map::~Map()
{
    Clear();
}

int Map::PutItem(ChimeraObject *obj)
{
    return FAIL;
}

int Map::SetToNewContainer(Container *new_container)
{
    if (new_container->GetType() == MAP_DATA_TYPE)
    {
        Map *new_map = (Map *)new_container;
        Clear();
        size_t index = 0;
        ResizeIfNeeded(new_map->m_map.size());

        for (const auto &item : new_map->m_map)
        {
            if (item != nullptr)
            {
                auto start = item->begin();
                auto end = item->end();
                m_map[index] = new list<MapItem>();

                while (start != end)
                {
                    MapItem data;
                    if (start->val != nullptr)
                    {
                        data.val = start->val->Clone();
                        data.was_cloned = true;
                    }
                    data.key = start->key;
                    m_map[index]->push_back(data);
                    start++;
                }
            }
            index++;
        }
    }

    return SUCCEED;
}

bool Map::HasItem(ChimeraObject *item) {
    string val = item->ToStr();
    size_t index = StrHash(val);
    bool has = false;

    if (m_map[index] != nullptr) {
        auto start = m_map[index]->begin();
        auto end = m_map[index]->end();

        while(start != end) {
            if (start->EqualsKey(val)) {
                has = true;
                break;
            }
            start++;
        }
    }

    return has;
}

int Map::RemoveItem(ChimeraObject *item) {
    string val = item->ToStr();
    size_t index = StrHash(val);
    int removed = FAIL;

    if (m_map[index] != nullptr) {
        auto start = m_map[index]->begin();
        auto end = m_map[index]->end();

        while(start != end) {
            if (start->EqualsKey(val)) {
                start->was_cloned=true;
                m_map[index]->erase(start);
                removed = SUCCEED;
                break;
            }
            start++;
        }
    }

    return removed;
}

void Map::SetDeclaredType(VAR_TYPES type)
{
    m_declared_type = type;
}

VAR_TYPES Map::GetDeclaredType()
{
    return m_declared_type;
}

size_t Map::Hash(ChimeraObject *item)
{
    size_t total_size = Size() == 0 ? 1 : Size();
    chmr_int hash = item->ToInt();
    return hash % total_size;
}

bool Map::MatchingDataTypes(VAR_TYPES key_type, VAR_TYPES val_type)
{
    return true;
}

void Map::ResizeIfNeeded(size_t new_size)
{
    if (m_map.size() == 0 && new_size == 0)
    {
        m_map.push_back(nullptr);
    }
    else if (new_size >= m_map.size())
    {
        size_t size = new_size - m_map.size();
        for (size_t i = 0; i < size; i++)
        {
            m_map.push_back(nullptr);
        }
    }
}

int Map::MapData(size_t hash, VAR_TYPES key_type, ChimeraObject *data, MapItem item)
{
    int ret_code = SUCCEED;

    if (free_hash_indexes <= m_map.size() / 4)
    {
        RehashIndexes();

        if (key_type == INT_DATA_TYPE)
        {
            hash = NonStrHash(item.key.i);
        }
        else if (key_type == FLOAT_DATA_TYPE)
        {
            hash = NonStrHash(item.key.f);
        }
        else if (key_type == DOUBLE_DATA_TYPE)
        {
            hash = NonStrHash(item.key.d);
        }
        else if (key_type == CHAR_DATA_TYPE)
        {
            hash = NonStrHash(item.key.c);
        }
        else if (key_type == STRING_DATA_TYPE)
        {
            hash = StrHash(item.key.s);
        }
        else if (key_type == BOOL_DATA_TYPE)
        {
            hash = NonStrHash(item.key.b);
        }
    }

    if (m_map[hash] == nullptr)
    {
        m_map[hash] = new list<MapItem>();
        free_hash_indexes--;
    }

    bool matching_key = false;

    for (auto hash_item = m_map[hash]->begin(); hash_item != m_map[hash]->end(); hash_item++)
    {
        if (key_type == INT_DATA_TYPE)
        {
            matching_key = hash_item->key.i == item.key.i;
        }
        else if (key_type == FLOAT_DATA_TYPE)
        {
            matching_key = hash_item->key.f == item.key.f;
        }
        else if (key_type == DOUBLE_DATA_TYPE)
        {
            matching_key = hash_item->key.d == item.key.d;
        }
        else if (key_type == CHAR_DATA_TYPE)
        {
            matching_key = hash_item->key.c == item.key.c;
        }
        else if (key_type == STRING_DATA_TYPE)
        {
            matching_key = hash_item->key.s == item.key.s;
        }
        else if (key_type == BOOL_DATA_TYPE)
        {
            matching_key = hash_item->key.b == item.key.b;
        }

        if (matching_key)
        {
            delete hash_item->val;
            hash_item->val = item.val->Clone();
            break;
        }
    }

    if (!matching_key)
    {
        m_map[hash]->push_back(item);
    }

    return ret_code;
}

void Map::RehashIndexes()
{
    size_t new_size = m_map.size() * 2;
    size_t non_null_items = 0;
    vector<list<MapItem>*> copy;

    for(size_t i = 0; i < m_map.size(); i++) {
        copy.push_back(m_map[i]);
        non_null_items = m_map[i] != nullptr ? non_null_items + 1 : non_null_items;
        m_map[i] = nullptr;
    }

    m_map.resize(new_size, nullptr);

    for(auto el : copy) {
        if (el == nullptr) { continue; }
        auto start = el->begin();
        size_t index = StrHash(start->key.s);
        m_map[index] = el;
    }

    free_hash_indexes = m_map.size() - non_null_items;

}

void Map::FreeHashIndex(list<MapItem> *index)
{
    auto start = index->begin();
    auto end = index->end();

    while (start != end)
    {
        delete start->val;
        start->val = nullptr;
        start++;
    }

    delete index;
}

int Map::SetData(string index, ChimeraObject *data, VAR_TYPES type, MapItem &item)
{
    int ret_code = FAIL;

    size_t hash = StrHash(index);
    ret_code = MapData(hash, type, data, item);
    m_size = ret_code == SUCCEED ? m_size + 1 : m_size;

    return ret_code;
}

size_t Map::StrHash(string index)
{
    int p = 255;
    int m = m_map.size();
    size_t hash = 0;

    for (size_t i = 0; i < index.length(); i++)
    {
        hash += index[i] * pow(p, i);
    }

    return hash % m;
}

size_t Map::Size()
{
    return m_size;
}

int Map::SetItem(chmr_int index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.i = index;
    return SetData(index, data, INT_DATA_TYPE, item);
}

int Map::SetItem(chmr_flt index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.f = index;
    return SetData(index, data, FLOAT_DATA_TYPE, item);
}

int Map::SetItem(chmr_dbl index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.d = index;
    return SetData(index, data, DOUBLE_DATA_TYPE, item);
}

int Map::SetItem(chmr_char index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.c = index;
    return SetData(index, data, CHAR_DATA_TYPE, item);
}

int Map::SetItem(string index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.s = index;
    return SetData(index, data, STRING_DATA_TYPE, item);
}

int Map::SetItem(bool index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.b = index;
    return SetData(index, data, BOOL_DATA_TYPE, item);
}

ChimeraObject *Map::GetItem(chmr_int index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(chmr_flt index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(chmr_dbl index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(chmr_char index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(string index)
{
    size_t hash = StrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(bool index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

void Map::Clear()
{
    for (const list<MapItem> *list : m_map)
    {
        if (list != nullptr)
        {
            for (auto start = list->begin(); start != list->end(); start++)
            {
                delete start->val;
            }
        }
    }

    m_map.resize(0);
}

string Map::ToStr()
{
    stringstream str_val;
    str_val << "{";
    size_t max_size = Size();
    size_t index = 0;

    for (const list<MapItem> *item : m_map)
    {
        if (item == nullptr)
        {
            continue;
        }

        for (auto start = item->begin(); start != item->end(); start++)
        {
            str_val << start->key.s << ": " << start->val->ToStr();

            if (index < max_size - 1)
            {
                str_val << ", ";
            }
            index++;
        }
    }

    str_val << "}";

    return str_val.str();
}

chmr_int Map::ToInt()
{
    return (chmr_int)Size();
}

chmr_flt Map::ToFloat()
{
    return (chmr_flt)Size();
}

chmr_dbl Map::ToDouble()
{
    return (chmr_dbl)Size();
}

chmr_char Map::ToChar()
{
    return m_map[0]->begin()->val->ToChar();
}

bool Map::ToBool()
{
    return Size() > 0;
}

ChimeraObject *Map::Clone()
{
    Map *map = new Map(m_key_type, m_val_type);
    map->SetDeclaredType(m_declared_type);
    map->SetToNewContainer(this);
    return map;
}