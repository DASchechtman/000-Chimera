#include "Boolean.hpp"
#include "../Types/Bool/Bool.hpp"

string NameOfMissingVar(string var_1, string var_2, SymbolTable *tbl) {
    return !tbl->Has(var_1) ? var_1 : var_2;
}

void ShowErrorVarDontExist(string var_1, string var_2, SymbolTable *tbl) {
    cout << "Error: " << NameOfMissingVar(var_1, var_2, tbl) << " doesn't exist\n";
}

string And(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErrorVarDontExist(var_1, var_2, tbl);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->AddEntry(EMPTY_VAR_NAME, new Bool(obj_1->ToBool() && obj_2->ToBool()));
}

string Or(string var_1, string var_2, SymbolTable *tbl) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2)) {
        ShowErrorVarDontExist(var_1, var_2, tbl);
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    return tbl->AddEntry(EMPTY_VAR_NAME, new Bool(obj_1->ToBool() || obj_2->ToBool()));
}

string Not(string var, SymbolTable *tbl) {
    if (!tbl->Has(var)) {
        ShowErrorVarDontExist(var, EMPTY_VAR_NAME, tbl);
        return EMPTY_VAR_NAME;
    }

    return tbl->AddEntry(EMPTY_VAR_NAME, new Bool(!tbl->GetEntry(var)->ToBool()));
}