#include "DisplayErrors.hpp"

string GetMissingData(vector<string> &data_names, SymbolTable *tbl)  {
    string ret = "all-vars-found";
    for (auto name : data_names) {
        if (!tbl->Has(name)) {
            ret = name;
            break;
        }
    }
    return ret;
}