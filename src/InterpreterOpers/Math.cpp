#include "Math.hpp"

typedef int (*operFunc)(ChimeraObject*, ChimeraObject*, bool);
typedef ChimeraObject ChrO;

int DoMath(string var_1, string var_2, OPER_CODE code, SymbolTable *tbl, operFunc oper) {
    if (!tbl->Has(var_1) || !tbl->Has(var_2))
    {
        cout << "Error: trying to do math operation on a non-numerical value\n";
        return FAIL;
    }

    ChimeraObject *obj_1 = tbl->GetEntry(var_1);
    ChimeraObject *obj_2 = tbl->GetEntry(var_2);

    int err = FAIL;

    const char *oper_code_names[] = { "ADD\0", "SUBTRACT\0", "MULTIPLY\0", "DIVIDE\0", "POW\0" };

    if (code == ADD_CODE || code == SUBTRACT_CODE)
    {
        if (obj_1->IsNumber() && obj_2->IsNumber())
        {
            err = (*oper)(obj_1, obj_2, true);
        }
        else if (obj_1->IsText() && obj_2->IsText())
        {
            err = (*oper)(obj_1, obj_2, false);
        }
        else
        {
            cout << "Error: cannont perform oper " << oper_code_names[code] << " on a number and a non-number\n";
        }
    }
    else if (code == MULTIPLY_CODE || code == DIVIDE_CODE || code == POW_CODE)
    {
        if (obj_1->IsNumber() && obj_2->IsNumber())
        {
            err = (*oper)(obj_1, obj_2, true);
        }
        else
        {
            cout << "Error: cannot peform oper " << oper_code_names[code] << " on non-number data\n";
        }
    }

    return err;
}

int Add(string var_1, string var_2, SymbolTable *var_table) {
    return DoMath(var_1, var_2, ADD_CODE, var_table, [](ChrO *obj_1, ChrO *obj_2, bool is_num) {
        int err = FAIL;
        if (is_num) {
            err = ((Number *)obj_1)->Add(*(Number*)obj_2);
        }
        else {
            err = ((Text *)obj_1)->Add(*(Text*)obj_2);
        }
        return err;
    });
}

int Subtract(string var_1, string var_2, SymbolTable *var_table) {
    return DoMath(var_1, var_2, SUBTRACT_CODE, var_table, [](ChrO *obj_1, ChrO *obj_2, bool is_num) {
        int err = FAIL;
        if (is_num) {
            err = ((Number *)obj_1)->Subtract(*(Number*)obj_2);
        }
        else {
            err = ((Text *)obj_1)->Subtract(*(Text*)obj_2);
        }
        return err;
    });
}

int Multiply(string var_1, string var_2, SymbolTable *var_table) {
    return DoMath(var_1, var_2, MULTIPLY_CODE, var_table, [](ChrO *obj_1, ChrO *obj_2, bool is_num) {
        if (!is_num) {
            return FAIL;
        }
        return ((Number *)obj_1)->Multiply(*(Number*)obj_2);
    });
}

int Divide(string var_1, string var_2, SymbolTable *var_table) {
    return DoMath(var_1, var_2, DIVIDE_CODE, var_table, [](ChrO *obj_1, ChrO *obj_2, bool is_num) {
        if (!is_num) {
            return FAIL;
        }
        return ((Number *)obj_1)->Divide(*(Number*)obj_2);
    });
}

int Pow(string var_1, string var_2, SymbolTable *var_table) {
    return DoMath(var_1, var_2, POW_CODE, var_table, [](ChrO *obj_1, ChrO *obj_2, bool is_num) {
        if (!is_num) {
            return FAIL;
        }
        return ((Number *)obj_1)->Pow(*(Number*)obj_2);
    });
}

int Inc(string var, SymbolTable *var_table) {
    if (!var_table->Has(var)) {
        cout << "Error: Variable does not exist\n";
        return FAIL;
    }

    ChimeraObject *var_obj = var_table->GetEntry(var);
    if (var_table->GetParent(var).length() > 0) {
        var_obj = var_table->GetEntry(var_table->GetParent(var));
    }
    if (var_obj->IsNumber()) {
        long double num = ((Number*)var_obj)->GetNumber() + 1;
        var_obj->Set(num);
        return SUCCEED;
    }

    cout << "Error: data isn't a number\n";
    return FAIL;
}

string Mod(string var_1, string var_2, SymbolTable *var_table) {
    if (!var_table->Has(var_1) || !var_table->Has(var_2)) {
        cout << "Error: Variable doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    ChimeraObject *var_1_obj = var_table->GetEntry(var_1);
    ChimeraObject *var_2_obj = var_table->GetEntry(var_2);

    if (var_1_obj->IsNumber() && var_2_obj->IsNumber()) {
        long double val_1 = ((Number*)var_1_obj)->GetNumber();
        long double val_2 = ((Number*)var_2_obj)->GetNumber();
        if(val_2 == 0) {
            cout << "Error: cannot get the results of " << val_1 << " % " << val_2 << '\n';
            return EMPTY_VAR_NAME;
        }
        
        return var_table->AddEntry(EMPTY_VAR_NAME, new Double(fmod(val_1, val_2)));
    }

    return EMPTY_VAR_NAME;
}