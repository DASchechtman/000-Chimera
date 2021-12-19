#include "Map.hpp"
#include <sstream>
#include <iostream>

using namespace std;

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

void Map::SetToNewContainer(Container *new_container)
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
}

size_t Map::Hash(ChimeraObject *item)
{
    size_t total_size = Size() == 0 ? 1 : Size();
    unsigned long long hash = item->ToInt();
    return hash % total_size;
}

bool Map::MatchingDataTypes(VAR_TYPES key_type, VAR_TYPES val_type)
{
    return key_type == m_key_type && val_type == m_val_type;
}

void Map::ResizeIfNeeded(size_t new_size)
{
    if (m_map.size() == 0 && new_size == 0)
    {
        m_map.push_back(nullptr);
    }
    else if (new_size >= m_map.size())
    {
        auto size = new_size - m_map.size();
        for (size_t i = 0; i < size; i++)
        {
            m_map.push_back(nullptr);
        }
    }
}

int Map::MapData(size_t hash, VAR_TYPES key_type, ChimeraObject *data, MapItem item)
{
    int ret_code = SUCCEED;

    if (MatchingDataTypes(key_type, data->GetType()))
    {
        
        if (free_hash_indexes <= m_map.size() / 4)
        {
            RehashIndexes();

            if (key_type == INT_DATA_TYPE) {
                hash = NonStrHash(item.key.i);
            }
            else if (key_type == FLOAT_DATA_TYPE) {
                hash = NonStrHash(item.key.f);
            }
            else if (key_type == DOUBLE_DATA_TYPE) {
                hash = NonStrHash(item.key.d);
            }
            else if (key_type == CHAR_DATA_TYPE) {
                hash = NonStrHash(item.key.c);
            }
            else if (key_type == STRING_DATA_TYPE) {
                hash = StrHash(item.key.s);
            }
            else if (key_type == BOOL_DATA_TYPE) {
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
    }
    else
    {
        ret_code = FAIL;
    }

    return ret_code;
}

void Map::RehashIndexes()
{
    auto copy = m_map;
    auto new_size = m_map.size() * 2;

    for (size_t i = 0; i < new_size; i++)
    {
        if (i < m_map.size())
        {
            if (m_map[i] != nullptr) {
                //FreeHashIndex(m_map[i]);
                m_map[i] = nullptr;
            }
        }
        else
        {
            m_map.push_back(nullptr);
            free_hash_indexes++;
        }
    }

    for (const auto item : copy)
    {
        if (item != nullptr)
        {
            auto start = item->begin();
            auto end = item->end();
            size_t cur_index = 0;

            if (m_key_type == INT_DATA_TYPE)
            {
                cur_index = NonStrHash(start->key.i);
            }
            else if (m_key_type == FLOAT_DATA_TYPE)
            {
                cur_index = NonStrHash(start->key.f);
            }
            else if (m_key_type == DOUBLE_DATA_TYPE)
            {
                cur_index = NonStrHash(start->key.d);
            }
            else if (m_key_type == CHAR_DATA_TYPE)
            {
                cur_index = NonStrHash(start->key.c);
            }
            else if (m_key_type == STRING_DATA_TYPE)
            {
                cur_index = StrHash(start->key.s);
            }
            else if (m_key_type == BOOL_DATA_TYPE)
            {
                cur_index = NonStrHash(start->key.b);
            }

            while (start != end)
            {

                if (m_map[cur_index] == nullptr)
                {
                    m_map[cur_index] = new list<MapItem>();
                }

                MapItem new_item(start->val, start->key);
                m_map[cur_index]->push_back(new_item);
                start++;
            }

            delete item;
        }
    }
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

    if (m_key_type == type)
    {
        size_t hash = StrHash(index);
        ret_code = MapData(hash, type, data, item);
        m_size = ret_code == SUCCEED ? m_size+1 : m_size;
    }
    else
    {
        cout << "Error: key type does not match\n";
    }

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

int Map::SetItem(int64 index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.i = index;
    return SetData(index, data, INT_DATA_TYPE, item);
}

int Map::SetItem(float index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.f = index;
    return SetData(index, data, FLOAT_DATA_TYPE, item);
}

int Map::SetItem(dbl128 index, ChimeraObject *data)
{
    MapItem item;
    item.val = data;
    item.key.d = index;
    return SetData(index, data, DOUBLE_DATA_TYPE, item);
}

int Map::SetItem(char32_t index, ChimeraObject *data)
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

ChimeraObject *Map::GetItem(int64 index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(float index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(dbl128 index)
{
    size_t hash = NonStrHash(index);
    return GetData(hash, index);
}

ChimeraObject *Map::GetItem(char32_t index)
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
    for (const auto *list : m_map)
    {
        if (list != nullptr)
        {
           for(auto start = list->begin(); start != list->end(); start++) {
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
    auto max_size = Size();
    size_t index = 0;

    for (const auto &item : m_map)
    {
        if (item == nullptr)
        {
            continue;
        }
        
        for (auto start = item->begin(); start != item->end(); start++)
        {
            switch (m_key_type)
            {
            case INT_DATA_TYPE:
            {
                str_val << start->key.i;
                break;
            }
            case FLOAT_DATA_TYPE:
            {
                str_val << start->key.f;
                break;
            }
            case DOUBLE_DATA_TYPE:
            {
                str_val << start->key.d;
                break;
            }
            case CHAR_DATA_TYPE:
            {
                str_val << "'" << (char)start->key.c << "'";
                break;
            }
            case STRING_DATA_TYPE:
            {
                str_val << '"' << start->key.s << '"';
                break;
            }
            case BOOL_DATA_TYPE:
            {
                if (start->key.b)
                {
                    str_val << "true";
                }
                else
                {
                    str_val << "false";
                }
                break;
            }

            default:
            {
            }
            }

            str_val << ": ";
            switch (m_val_type)
            {
            case INT_DATA_TYPE:
            {
                int64 data;
                start->val->Get(data);
                str_val << data;
                break;
            }
            case FLOAT_DATA_TYPE:
            {
                float data;
                start->val->Get(data);
                str_val << data;
                break;
            }
            case DOUBLE_DATA_TYPE:
            {
                dbl128 data;
                start->val->Get(data);
                str_val << data;
                break;
            }
            case CHAR_DATA_TYPE:
            {
                char32_t data;
                start->val->Get(data);
                str_val << "'" << (char)data << "'";
                break;
            }
            case STRING_DATA_TYPE:
            {
                string data;
                start->val->Get(data);
                str_val << '"' << data << '"';
                break;
            }
            case BOOL_DATA_TYPE:
            {
                str_val << start->val->ToStr();
                break;
            }

            default:
            {
            }
            }

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

int64 Map::ToInt()
{
    return (int64)Size();
}

float Map::ToFloat()
{
    return (float)Size();
}

dbl128 Map::ToDouble()
{
    return (dbl128)Size();
}

char32_t Map::ToChar()
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
    map->SetToNewContainer(this);
    return map;
}