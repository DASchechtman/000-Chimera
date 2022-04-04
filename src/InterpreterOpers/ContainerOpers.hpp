#pragma once

#include <string>
#include <vector>
#include "../DataStructs/Memory.hpp"

using namespace std;

typedef Memory& VarTbl;

string MakeArray(string list, string list_type, VarTbl tbl);
string MakeArray(string list, vector<string> list_type, VarTbl tbl);
string MakeMap(string map, string key_type_name, string val_type_name, VarTbl tbl);
string PutInArray(string container, string item, VarTbl tbl);
string PutInMap(string map, string key, string item, VarTbl tbl);
string GetFromContainer(string container, string index, VarTbl tbl);
string SetInContainer(string container, string index, string item, VarTbl tbl);
string ReassignContainer(string old, string latest, VarTbl tbl);
string GetContainerSize(string container, VarTbl tbl);
string RemoveFromContainer(string container, string item, VarTbl tbl);
string QueryContainer(string container, string item, VarTbl tbl);

