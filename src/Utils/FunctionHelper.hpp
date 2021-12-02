#pragma once

#include <vector>
#include <string>
#include "../Types/ChimeraObject.hpp"

using namespace std;

template<class T, class ... CorrectParams, class ... Params>
bool CanRunMethod(T (CorrectParams...), Params ... params) {
    vector<string> cor_p = {typeid(CorrectParams).name()...};
    vector<ChimeraObject> passed_p = {typeid(params).name()...};

    bool can_run = false;

    if (cor_p.size() == passed_p.size()) {
        can_run = true;
        for(size_t i = 0; i < passed_p.size(); i++) {
            string type_name;

            if (passed_p[i].GetType() == INT_DATA_TYPE) {
                type_name = typeid(int).name();
            }
            else if (passed_p[i].GetType() == FLOAT_DATA_TYPE) {
                type_name = typeid(float).name();
            }
            else if (passed_p[i].GetType() == DOUBLE_DATA_TYPE) {
                type_name = typeid(double).name();
            }
            else if (passed_p[i].GetType() == STRING_DATA_TYPE) {
                type_name = typeid(string).name();
            }
            else if (passed_p[i].GetType() == BOOL_DATA_TYPE) {
                type_name = typeid(bool).name();
            }
            else if (passed_p[i].GetType() == CHAR_DATA_TYPE) {
                type_name = typeid(char32_t);
            }

            if (type_name != cor_p[i] && cor_p[i] != typeid(ChimeraObject).name()) {
                can_run = false;
                break;
            }
        }
    }

    return can_run;
}