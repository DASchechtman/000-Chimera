#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

string ChmrInterpreter::DoLogicOper(string var_id_1, string var_id_2, bool(*oper)(bool, bool)) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: can't and a nonexistent value\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    string temp_bool_1 = m_table.AddEntry("", var_1->ConvertTo(BOOL_TYPE));
    string temp_bool_2 = m_table.AddEntry("", var_2->ConvertTo(BOOL_TYPE));

    ChimeraObject *bool_1 = m_table.GetEntry(temp_bool_1);
    ChimeraObject *bool_2 = m_table.GetEntry(temp_bool_2);

    bool res_1 = false;
    bool res_2 = false;
    bool_1->Get(res_1);
    bool_2->Get(res_2);

    return Create("", BOOL_TYPE, (*oper)(res_1, res_2));
}

int ChmrInterpreter::DoMath(string var_id_1, string var_id_2, int(*oper)(ChimeraObject* obj_1, ChimeraObject* obj_2)) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: trying to add a nonexistent value\n";
        return 1;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return (*oper)(var_1, var_2);
}

string ChmrInterpreter::MakeBind(string to, string from, string type) {
     if (!m_table.Has(from)) {
        return "";
    }

    auto obj = m_table.GetEntry(from);
    string var_id;

    switch (obj->GetType())
    {
        case INT_DATA_TYPE: {
            int data = 0;
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        case FLOAT_DATA_TYPE: {
            float data = 0;
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        case DOUBLE_DATA_TYPE: {
            long double data = 0;
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        case CHAR_DATA_TYPE: {
            unsigned char data = 'a';
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        case STRING_DATA_TYPE: {
            string data;
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        case BOOL_DATA_TYPE: {
            bool data = false;
            obj->Get(data);
            var_id = CloneOrCreate(to, type, data);
            break;
        }
        default: {

        }
    }

    return var_id;
}

string ChmrInterpreter::Bind(string to, string from, string type) {
    if (m_table.Has(to)) {
        cout << "Error: var " << to << " already exists\n";
        return "";
    }
    else {
        return MakeBind(to, from, type);
    }
}

string ChmrInterpreter::Rebind(string to, string from) {
    if (!m_table.Has(to)) {
        cout << "Error: couldn't clone var\n";
        return "";
    }
    else {
        return MakeBind(to, from, m_table.GetEntry(to)->GetTypeName());
    }
}

int ChmrInterpreter::PrintVar(string var_id, char end) {
    if (!m_table.Has(var_id)) {
        cout << "Error: cannot print var " << var_id << '\n';
        return 1;
    }

    auto obj = m_table.GetEntry(var_id);
    cout << *obj << end;

    return 0;
}

string ChmrInterpreter::CloneToTemp(string var_id) {
    if (!m_table.Has(var_id)) {
        cout << "Error: var doesn't exist\n";
        return "";
    }

    auto obj = m_table.GetEntry(var_id);
    string tmp_name;

    switch(obj->GetType()) {
        case INT_DATA_TYPE: {
            int data = 0;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }
        case FLOAT_DATA_TYPE: {
            float data = 0;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }
        case DOUBLE_DATA_TYPE: {
            long double data = 0;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }
        case CHAR_DATA_TYPE: {
            unsigned char data = 0;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }
        case STRING_DATA_TYPE: {
            string data;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }
        case BOOL_DATA_TYPE: {
            bool data = 0;
            obj->Get(data);
            tmp_name = Create("", obj->GetTypeName(), data);
            break;
        }

        default: {
            cout << "Error: trying to clone an unsupported type of " << obj->GetTypeName() << '\n';
            break;
        }
    }
    return tmp_name;
}

int ChmrInterpreter::Add(string var_id_1, string var_id_2) {
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2) {
        bool converted_1 = false;
        bool converted_2 = false;
        bool is_num_1 = (
            obj_1->GetType() == INT_DATA_TYPE
            || obj_1->GetType() == FLOAT_DATA_TYPE
            || obj_1->GetType() == DOUBLE_DATA_TYPE
            || obj_1->GetType() == CHAR_DATA_TYPE
        );

        bool is_num_2 = (
            obj_2->GetType() == INT_DATA_TYPE
            || obj_2->GetType() == FLOAT_DATA_TYPE
            || obj_2->GetType() == DOUBLE_DATA_TYPE
            || obj_2->GetType() == CHAR_DATA_TYPE
        );


        int err = 0;

        if (obj_1->GetType() == STRING_DATA_TYPE && obj_2->GetType() == STRING_DATA_TYPE) {
            err = ((Text*)obj_1)->Add(*(Text*)obj_2);
        }
        else if (is_num_1 && is_num_2) {
            err = ((Number*)obj_1)->Add(*(Number*)obj_2);
        }
        else {
            cout << "Error: trying to add a non number, non string value\n";
            err = 1;
        }

        if (converted_1) {
            delete obj_1;
        }
        if (converted_2) {
            delete obj_2;
        }

        return err;
    };

    return DoMath(var_id_1, var_id_2, callback);   
}

int ChmrInterpreter::Subtract(string var_id_1, string var_id_2) {
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2) {
        bool converted_1 = false;
        bool converted_2 = false;
        bool is_num_1 = (
            obj_1->GetType() == INT_DATA_TYPE
            || obj_1->GetType() == FLOAT_DATA_TYPE
            || obj_1->GetType() == DOUBLE_DATA_TYPE
            || obj_1->GetType() == CHAR_DATA_TYPE
        );

        bool is_num_2 = (
            obj_2->GetType() == INT_DATA_TYPE
            || obj_2->GetType() == FLOAT_DATA_TYPE
            || obj_2->GetType() == DOUBLE_DATA_TYPE
            || obj_2->GetType() == CHAR_DATA_TYPE
        );

        int err = 0;

        if (obj_1->GetType() == STRING_DATA_TYPE && obj_2->GetType() == STRING_DATA_TYPE) {
            err = ((Text*)obj_1)->Subtract(*(Text*)obj_2);
        }
        else if (is_num_1 && is_num_2) {
            err = ((Number*)obj_1)->Subtract(*(Number*)obj_2);
        }
        else {
            cout << "Error: trying to add a non number, non string value\n";
            err = 1;
        }

        if (converted_1) {
            delete obj_1;
        }
        if (converted_2) {
            delete obj_2;
        }

        return err;
    };

    return DoMath(var_id_1, var_id_2, callback);   
}

int ChmrInterpreter::Multiply(string var_id_1, string var_id_2) {
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2) {
        bool is_num_1 = (
            obj_1->GetType() == INT_DATA_TYPE
            || obj_1->GetType() == FLOAT_DATA_TYPE
            || obj_1->GetType() == DOUBLE_DATA_TYPE
            || obj_1->GetType() == CHAR_DATA_TYPE
        );

        bool is_num_2 = (
            obj_2->GetType() == INT_DATA_TYPE
            || obj_2->GetType() == FLOAT_DATA_TYPE
            || obj_2->GetType() == DOUBLE_DATA_TYPE
            || obj_2->GetType() == CHAR_DATA_TYPE
        );


        if (is_num_1 && is_num_2) {
            return ((Number*)obj_1)->Multiply(*(Number*)obj_2);
        }
        else {
            cout << "Error: trying to add a non number, non string value\n";
            return 1;
        }
    };

    return DoMath(var_id_1, var_id_2, callback);   
}

int ChmrInterpreter::Divide(string var_id_1, string var_id_2) {
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2) {
        bool is_num_1 = (
            obj_1->GetType() == INT_DATA_TYPE
            || obj_1->GetType() == FLOAT_DATA_TYPE
            || obj_1->GetType() == DOUBLE_DATA_TYPE
            || obj_1->GetType() == CHAR_DATA_TYPE
        );

        bool is_num_2 = (
            obj_2->GetType() == INT_DATA_TYPE
            || obj_2->GetType() == FLOAT_DATA_TYPE
            || obj_2->GetType() == DOUBLE_DATA_TYPE
            || obj_2->GetType() == CHAR_DATA_TYPE
        );


        if (is_num_1 && is_num_2) {
            return ((Number*)obj_1)->Divide(*(Number*)obj_2);
        }
        else {
            cout << "Error: trying to add a non number, non string value\n";
            return 1;
        }
    };

    return DoMath(var_id_1, var_id_2, callback);   
}

int ChmrInterpreter::Pow(string base_id, string exp_id) {
    if (!m_table.Has(base_id) || !m_table.Has(exp_id)) {
        cout << "Error: cannot do math oper on nonexist\n";
        return 1;
    }

    auto obj_1 = m_table.GetEntry(base_id);
    auto obj_2 = m_table.GetEntry(exp_id);

    bool is_num_1 = (
            obj_1->GetType() == INT_DATA_TYPE
            || obj_1->GetType() == FLOAT_DATA_TYPE
            || obj_1->GetType() == DOUBLE_DATA_TYPE
            || obj_1->GetType() == CHAR_DATA_TYPE
        );

    bool is_num_2 = (
        obj_2->GetType() == INT_DATA_TYPE
        || obj_2->GetType() == FLOAT_DATA_TYPE
        || obj_2->GetType() == DOUBLE_DATA_TYPE
        || obj_2->GetType() == CHAR_DATA_TYPE
    );

    if (is_num_1 && is_num_2) {
        auto num_1 = ((Number*)obj_2)->GetOtherNumber(*(Number*)obj_1);
        auto num_2 = ((Number*)obj_1)->GetOtherNumber(*(Number*)obj_2);
        long double result = pow(num_1, num_2);

        obj_1->Set(result);
        return 0;
    }
    else {
        cout << "Error: cannot perform oper on non-num type\n";
        return 1;
    }
}

void ChmrInterpreter::GarbageCollect() {
    m_table.FreeMemory();
}

string ChmrInterpreter::Cast(string var_id, string type) {
    if (!m_table.Has(var_id)) {
        cout << "Error: var " << var_id << " doesn't exist\n";
        return ""; 
    }

    auto var = m_table.GetEntry(var_id)->ConvertTo(type);

    if (var == nullptr) {
        return "";
    }

    return m_table.AddEntry("", var);
}

bool ChmrInterpreter::HasVar(string var_id) {
    return m_table.Has(var_id);
}

string ChmrInterpreter::And(string var_id_1, string var_id_2) {
    return DoLogicOper(var_id_1, var_id_2, [](bool b1, bool b2) { return b1 && b2; });
}

string ChmrInterpreter::Or(string var_id_1, string var_id_2) {
    return DoLogicOper(var_id_1, var_id_2, [](bool b1, bool b2) { return b1 || b2; });
}

string ChmrInterpreter::Not(string var_id_1) {
    if (!m_table.Has(var_id_1)) {
        cout << "Error: cannot perform logical oper on nonexistent\n";
        return "";
    }

    auto var = m_table.GetEntry(var_id_1);
    auto bool_var_name = m_table.AddEntry("", var->ConvertTo(BOOL_TYPE));
    auto bool_var = m_table.GetEntry(bool_var_name);

    bool res = false;
    bool_var->Get(res);

    return Create("", BOOL_TYPE, !res);
}

string ChmrInterpreter::Less(string var_id_1, string var_id_2) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: cannot compare nonexistent values\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Less(var_2));
}

string ChmrInterpreter::LessEqual(string var_id_1, string var_id_2) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: cannot compare nonexistent values\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->LessEqual(var_2));
}

string ChmrInterpreter::Greater(string var_id_1, string var_id_2) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: cannot compare nonexistent values\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Greater(var_2));
}

string ChmrInterpreter::GreaterEqual(string var_id_1, string var_id_2) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: cannot compare nonexistent values\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->GreaterEqual(var_2));
}

string ChmrInterpreter::Equal(string var_id_1, string var_id_2) {
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2)) {
        cout << "Error: cannot compare nonexistent values\n";
        return "";
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Equal(var_2));
}