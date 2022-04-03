#include "Boolean.hpp"
#include "../Types/Bool/Bool.hpp"

string NameOfMissingVar(string var_1, string var_2, Memory &tbl) {
    return !(tbl.GetData(ORIGINAL, var_1) == nullptr) ? var_1 : var_2;
}

void ShowErrorVarDontExist(string var_1, string var_2, Memory &tbl) {
    cout << "Error: " << NameOfMissingVar(var_1, var_2, tbl) << " doesn't exist\n";
}

string And(string var_1, string var_2, Memory &tbl) {

    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErrorVarDontExist(var_1, var_2, tbl);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(obj_1->ToBool() && obj_2->ToBool());
}

string Or(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErrorVarDontExist(var_1, var_2, tbl);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(obj_1->ToBool() || obj_2->ToBool());
}

string Not(string var, Memory &tbl) {
    ChimeraObject *obj = tbl.GetData(ORIGINAL, var);
    if (obj == nullptr) {
        ShowErrorVarDontExist(var, EMPTY_VAR_NAME, tbl);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(!obj->ToBool());
}