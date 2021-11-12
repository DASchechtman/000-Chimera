#pragma once

// #include "Container.hpp"
// #include <vector>
// #include <list>

// using namespace std;

// struct MapItem {
//     ChimeraObject *key = nullptr;
//     ChimeraObject *val = nullptr;
// };

// class Map : public Container {
// private:
//     vector<list<MapItem>> m_map;
//     VAR_TYPES m_key_type = UNDEFINED_DATA_TYPE;
//     VAR_TYPES m_val_type = UNDEFINED_DATA_TYPE;

//     size_t Hash(ChimeraObject *item);
// protected:
// public:
//     Map(VAR_TYPES key_type, VAR_TYPES val_type);

//     int PutItem(ChimeraObject *data);
//     size_t Size();
//     void SetToNewContainer(Container *new_container);

//     int SetItem(int64 index, ChimeraObject *data);
//     int SetItem(float index, ChimeraObject *data);
//     int SetItem(dbl128 index, ChimeraObject *data);
//     int SetItem(char32_t index, ChimeraObject *data);
//     int SetItem(string index, ChimeraObject *data);
//     int SetItem(bool index, ChimeraObject *data);

//     ChimeraObject* GetItem(int64 index);
//     ChimeraObject* GetItem(float index);
//     ChimeraObject* GetItem(dbl128 index);
//     ChimeraObject* GetItem(char32_t index);
//     ChimeraObject* GetItem(string index);
//     ChimeraObject* GetItem(bool index);

// };