#include "CompareOper.hpp"
#include "../Types/Bool/Bool.hpp"
#include "DisplayErrors.hpp"

string Less(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }
    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->GetConstEntry(obj_1->Less(obj_2));
}

string LessEqual(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }
    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->GetConstEntry(obj_1->LessEqual(obj_2));
}

string Greater(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->GetConstEntry(obj_1->Greater(obj_2));
}

string GreaterEqual(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->GetConstEntry(obj_1->GreaterEqual(obj_2));
}

string Equal(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErr(tbl, "Error. Variable doesn't exist", var_1, var_2);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->GetConstEntry(obj_1->Equal(obj_2));
}