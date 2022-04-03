#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../DataStructs/Memory.hpp"

using namespace std;

string GetMissingData(vector<string> &data_names, Memory &tbl);

template<class... T>
void ShowErr(Memory &tbl, string err_msg, T ... args) {
    vector<string> names = {args...};
    cout << err_msg << " " << GetMissingData(names, tbl) << endl;
}