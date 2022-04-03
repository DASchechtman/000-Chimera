#include "CompareOper.hpp"
#include "../Types/Bool/Bool.hpp"
#include "DisplayErrors.hpp"

string Less(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }
    

    return tbl.GetConstsData(obj_1->Less(obj_2));
}

string LessEqual(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }
    

    return tbl.GetConstsData(obj_1->LessEqual(obj_2));
}

string Greater(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(obj_1->Greater(obj_2));
}

string GreaterEqual(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(obj_1->GreaterEqual(obj_2));
}

string Equal(string var_1, string var_2, Memory &tbl) {
    ChimeraObject *obj_1 = tbl.GetData(ORIGINAL, var_1);
    ChimeraObject *obj_2 = tbl.GetData(ORIGINAL, var_2);

    if (obj_1 == nullptr || obj_2 == nullptr) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    return tbl.GetConstsData(obj_1->Equal(obj_2));
}