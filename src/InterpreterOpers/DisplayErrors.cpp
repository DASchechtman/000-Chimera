#include "DisplayErrors.hpp"

string GetMissingData(vector<string> &data_names, Memory &tbl)  {
    string ret = "all-vars-found";
    for (auto name : data_names) {
        if (tbl.GetData(ORIGINAL, name) == nullptr) {
            ret = name;
            break;
        }
    }
    return ret;
}