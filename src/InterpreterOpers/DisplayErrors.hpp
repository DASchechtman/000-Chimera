#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../DataStructs/SymbolTable.hpp"

using namespace std;

string GetMissingData(vector<string> &data_names, SymbolTable *tbl);

template<class... T>
void ShowErr(SymbolTable *tbl, string err_msg, T ... args) {
    vector<string> names = {args...};
    cout << err_msg << " " << GetMissingData(names, tbl) << '\n';
}