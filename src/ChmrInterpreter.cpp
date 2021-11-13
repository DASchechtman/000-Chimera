#include "ChmrInterpreter.hpp"
#include "Types/Number/Number.hpp"
#include "Types/Text/Text.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// PRIVATE METHODS BELOW ---------------------------------------------------------------------------

string ChmrInterpreter::MakeBind(string to, string from, string type)
{
    if (!m_table.Has(from))
    {
        cout << "Error: can't bind data to nonexistant symbol\n";
        return EMPTY_VAR_NAME;
    }

    auto obj = m_table.GetEntry(from);
    string var_id = EMPTY_VAR_NAME;
    string p = m_table.GetParent(to);

    switch (obj->GetType())
    {
    case INT_DATA_TYPE:
    {
        int64 data = 0;
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case FLOAT_DATA_TYPE:
    {
        float data = 0;
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case DOUBLE_DATA_TYPE:
    {
        long double data = 0;
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case CHAR_DATA_TYPE:
    {
        char32_t data = 'a';
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case STRING_DATA_TYPE:
    {
        string data;
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case BOOL_DATA_TYPE:
    {
        bool data = false;
        obj->Get(data);
        var_id = CloneOrCreate(to, type, data);
        break;
    }
    case LIST_DATA_TYPE: {
        var_id = m_table.AddEntry(EMPTY_VAR_NAME, obj->Clone());
        break;
    }
    default:
    {
        cout << "Error: cannot create var of type " << type << "\n";
    }
    }

    return var_id;
}

string ChmrInterpreter::DoLogicOper(string var_id_1, string var_id_2, bool (*oper)(bool, bool))
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: can't and a nonexistent value\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    string temp_bool_1 = m_table.AddEntry("", var_1->ConvertTo(BOOL_TYPE_NAME));
    string temp_bool_2 = m_table.AddEntry("", var_2->ConvertTo(BOOL_TYPE_NAME));

    ChimeraObject *bool_1 = m_table.GetEntry(temp_bool_1);
    ChimeraObject *bool_2 = m_table.GetEntry(temp_bool_2);

    bool res_1 = false;
    bool res_2 = false;
    bool_1->Get(res_1);
    bool_2->Get(res_2);

    return Create(EMPTY_VAR_NAME, BOOL_TYPE_NAME, (*oper)(res_1, res_2));
}

int ChmrInterpreter::DoMath(string var_id_1, string var_id_2, OPER_CODE code, int (*oper)(ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num))
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: trying to do math operation on a non-numerical value\n";
        return FAIL;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    int err = 1;

    const char *oper_code_names[] = { "ADD\0", "SUBTRACT\0", "MULTIPLY\0", "DIVIDE\0", "POW\0" };

    if (code == ADD_CODE || code == SUBTRACT_CODE)
    {
        if (var_1->IsNumber() && var_2->IsNumber())
        {
            err = (*oper)(var_1, var_2, true);
        }
        else if (var_1->IsText() && var_2->IsText())
        {
            err = (*oper)(var_1, var_2, false);
        }
        else
        {
            cout << "Error: cannont perform oper " << oper_code_names[code] << " on a number and a non-number\n";
        }
    }
    else if (code == MULTIPLY_CODE || code == DIVIDE_CODE || code == POW_CODE)
    {
        if (var_1->IsNumber() && var_2->IsNumber())
        {
            err = (*oper)(var_1, var_2, true);
        }
        else
        {
            cout << "Error: cannot peform oper " << oper_code_names[code] << " on non-number data\n";
        }
    }

    return err;
}

ChimeraObject* ChmrInterpreter::GetListItem(Container *list, ChimeraObject *index) {
    ChimeraObject *item = nullptr;

    switch(index->GetType()) {
        
        case INT_DATA_TYPE: {
            int64 i = 0;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }

        case FLOAT_DATA_TYPE: {
            float i = 0;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }

        case DOUBLE_DATA_TYPE: {
            dbl128 i = 0;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }

        case STRING_DATA_TYPE: {
            string i;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }

        case CHAR_DATA_TYPE: {
            char32_t i = 0;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }

        case BOOL_DATA_TYPE: {
            bool i = false;
            index->Get(i);
            item = list->GetItem(i);
            break;
        }
        
        default: {
            cout << "Error: index is an unsupported type\n";
        }
    }

    return item;
}

int ChmrInterpreter::SetData(ChimeraObject *to, ChimeraObject *from) {

    switch(from->GetType()) {
        
        case INT_DATA_TYPE: {
            int64 i = 0;
            from->Get(i);
            return to->Set(i);
            break;
        }

        case FLOAT_DATA_TYPE: {
            float i = 0;
            from->Get(i);
            return to->Set(i);
            break;
        }

        case DOUBLE_DATA_TYPE: {
            dbl128 i = 0;
            from->Get(i);
            return to->Set(i);
            break;
        }

        case STRING_DATA_TYPE: {
            string i;
            from->Get(i);
            return to->Set(i);
            break;
        }

        case CHAR_DATA_TYPE: {
            char32_t i = 0;
            from->Get(i);
            return to->Set(i);
            break;
        }

        case BOOL_DATA_TYPE: {
            bool i = false;
            from->Get(i);
            return to->Set(i);
            break;
        }
        
        default: {
            cout << "Error: index is an unsupported type\n";
        }
    }
    return FAIL;
}

// PRIVATE METHODS ABOVE ---------------------------------------------------------------------------

// PROTECTED METHODS BELOW -------------------------------------------------------------------------
// PROTECTED METHODS ABOVE -------------------------------------------------------------------------

// PUBLIC METHODS BELOW -----------------------------------------------------------------------------

string ChmrInterpreter::Bind(string to, string from, string type)
{
    if (m_table.Has(to))
    {
        cout << "Error: var " << to << " already exists\n";
        return EMPTY_VAR_NAME;
    }
    else
    {
        return MakeBind(to, from, type);
    }
}

string ChmrInterpreter::Rebind(string to, string from)
{   
    if (!m_table.Has(to))
    {
        cout << "Error: couldn't clone var\n";
        return EMPTY_VAR_NAME;
    }
    else
    {
        auto obj = m_table.GetEntry(to);
        if (obj->GetGeneralType() == COLLECTION_DATA_TYPE) {
            return ReassignContainer(to, from);
        }
        return MakeBind(to, from, m_table.GetEntry(to)->GetTypeName());
    }
}

string ChmrInterpreter::RefBind(string ref_id, string var_id, string ref_type) {

    // makes sure that the variable being bound to a ref
    // is valid
    if (!m_table.Has(var_id)) {
        cout << "Error: cannot bind a reference to a nonexistent var\n";
        return EMPTY_VAR_NAME;
    }
    else if(m_table.CameFromVar(var_id)) {
        cout << "Error: cannot bind ref to a temp value\n";
        return EMPTY_VAR_NAME;
    }

    auto obj = m_table.GetEntry(m_table.GetParent(var_id));

    // makes sure that the reference id is valid in cases
    // that a reference is being rebound
    if(ref_type.empty() && m_table.Has(ref_id)) {
        ref_type = m_table.GetEntry(ref_id)->GetTypeName();
    }
    else if (ref_type.empty() && !m_table.Has(ref_id)) {
        cout << "Error: can't rebind a nonexistent ref\n";
        return EMPTY_VAR_NAME;
    }

    // makes sure that the right time of variable is being bound
    // to the same type of reference
    if (obj->GetTypeName() != ref_type) {
        cout << "Error: cannot reference type '" << obj->GetTypeName() << "' as " << ref_type << "-ref\n";
        return EMPTY_VAR_NAME;
    }
    else if (obj->GetGeneralType() == UNION_DATA_TYPE) {
        cout << "Error: cannot make a reference to dynamic types 'unions'\n";
        return EMPTY_VAR_NAME;
    }

    return m_table.AddOrUpdateRef(ref_id, obj);
}

string ChmrInterpreter::MakeUnion(string var_id, vector<string> types, string var_id_2, bool unknown) {
    if (!m_table.Has(var_id_2)) {
        cout << "Error: cannot make a union type, var " << var_id_2 << " doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    auto type_list = types;

    if (unknown) {
        type_list = {
            INT_TYPE_NAME, 
            FLOAT_TYPE_NAME, 
            DOUBLE_TYPE_NAME, 
            CHAR_TYPE_NAME, 
            BOOL_TYPE_NAME, 
            STRING_TYPE_NAME
        };
    }

    auto from = m_table.GetEntry(var_id_2);
    ChimeraObject *to = new ChimeraUnion(type_list, from);

    if (to->GetType() == UNDEFINED_DATA_TYPE) {
        cout << "Error: initalized union with non-allowable type\n";
        delete to;
        return EMPTY_VAR_NAME;
    }

    return m_table.AddEntry(var_id, to);
}

string ChmrInterpreter::MakeList(string var_id, string type) {
    VAR_TYPES list_type = UNDEFINED_DATA_TYPE;
    
    if (type == INT_TYPE_NAME) {
        list_type = INT_DATA_TYPE;
    }
    else if (type == FLOAT_TYPE_NAME) {
        list_type = FLOAT_DATA_TYPE;
    }
    else if (type == DOUBLE_TYPE_NAME) {
        list_type = DOUBLE_DATA_TYPE;
    }
    else if (type == STRING_TYPE_NAME) {
        list_type = STRING_DATA_TYPE;
    }
    else if (type == CHAR_TYPE_NAME) {
        list_type = CHAR_DATA_TYPE;
    }
    else if (type == BOOL_TYPE_NAME) {
        list_type = BOOL_DATA_TYPE;
    }
    
    List *list = new List(list_type);

    return m_table.AddEntry(var_id, list);
}

string ChmrInterpreter::PutInContainer(string list_id, string item_id) {
    if (!m_table.Has(list_id) || !m_table.Has(item_id)) {
        cout << "Error: cannot add because one of the items don't exist\n";
        return EMPTY_VAR_NAME;
    }

    auto list = m_table.GetEntry(list_id);

    if (list->GetGeneralType() == COLLECTION_DATA_TYPE) {
        auto item = m_table.GetEntry(item_id);
        if(((Container*)list)->PutItem(item) == FAIL) {
            return EMPTY_VAR_NAME;
        }
        return item_id;
    }
    else {
        cout << "Error: cannot put item into non-container type\n";
        return EMPTY_VAR_NAME;
    }
}

string ChmrInterpreter::GetFromContainer(string list_id, string index_id) {
    if (!m_table.Has(list_id) || !m_table.Has(index_id)) {
        cout << "Error: cannot get a value with non-existent parts\n";
        return EMPTY_VAR_NAME;
    }

    auto obj = m_table.GetEntry(list_id);

    if (obj->GetGeneralType() == COLLECTION_DATA_TYPE) {
        auto index = m_table.GetEntry(index_id);
        Container *list = (Container*)obj;

        ChimeraObject *item = GetListItem(list, index);


        if (item == nullptr) {
            return EMPTY_VAR_NAME;
        }
        else {
            return m_table.AddEntry(EMPTY_VAR_NAME, item->Clone());
        }

    }
    else {
        cout << "Error: cannot get index from non-containter type\n";
        return EMPTY_VAR_NAME;
    }
}

string ChmrInterpreter::SetInContainer(string list_id, string index_id, string new_item_id){
    if (!m_table.Has(list_id) || !m_table.Has(index_id) || !m_table.Has(new_item_id)) {
        cout << "Error: cannot set item in list cuz one of the args don't exist\n";
        return EMPTY_VAR_NAME;
    }
    auto obj_1 = m_table.GetEntry(list_id);
    auto index = m_table.GetEntry(index_id);

    if (obj_1->GetGeneralType() == COLLECTION_DATA_TYPE) {
        auto item = GetListItem((Container*)obj_1, index);
        auto new_item = m_table.GetEntry(new_item_id);

        if (item == nullptr) {
            cout << "Error: item does not exist in list\n";
            return EMPTY_VAR_NAME;
        }
        else if (SetData(item, new_item) == FAIL) {
            return EMPTY_VAR_NAME;
        }

        return m_table.AddEntry(EMPTY_VAR_NAME, item->Clone());
    }
    else {
        cout << "Error: cannot access element of non-list type\n";
        return EMPTY_VAR_NAME;
    }
}

string ChmrInterpreter::ReassignContainer(string list_id_1, string list_id_2) {
    if (!m_table.Has(list_id_1) || !m_table.Has(list_id_2)) {
        cout << "Error: cannot assign to list because one of the args don't exist\n";
        return EMPTY_VAR_NAME;
    }

    auto list_1 = m_table.GetEntry(list_id_1);
    auto list_2 = m_table.GetEntry(list_id_2);

    if (list_1->GetGeneralType() == COLLECTION_DATA_TYPE && list_2->GetGeneralType() == COLLECTION_DATA_TYPE) {
        if (list_1->GetType() == list_2->GetType()) {
            ((Container*)list_1)->SetToNewContainer((Container*)list_2);
            return list_id_1;
        } 
        else {
            cout << "Error: cannot assign " << list_1->GetTypeName() << " to " << list_2->GetTypeName() << '\n';
            return EMPTY_VAR_NAME;
        }
    }
    else {
        cout << "Error: cannot perform operation 'reassign' on a list on non-list type\n";
        return EMPTY_VAR_NAME;
    }
}

string ChmrInterpreter::CloneToTemp(string var_id)
{
    if (!m_table.Has(var_id))
    {
        cout << "Error: var doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    auto obj = m_table.GetEntry(var_id);
    auto c = obj->Clone();
    string tmp = m_table.AddEntry(EMPTY_VAR_NAME, c);
    m_table.SetParent(tmp, var_id);
    return MakeBind(tmp, var_id, obj->GetTypeName());
}

int ChmrInterpreter::Add(string var_id_1, string var_id_2)
{
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num)
    {
        int err = 1;
        if (is_num)
        {
            err = ((Number *)obj_1)->Add(*(Number *)obj_2);
        }
        else
        {
            err = ((Text *)obj_1)->Add(*(Text *)obj_2);
        }

        return err;
    };

    return DoMath(var_id_1, var_id_2, ADD_CODE, callback);
}

int ChmrInterpreter::Subtract(string var_id_1, string var_id_2)
{
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num)
    {
        int err = 1;
        if (is_num)
        {
            err = ((Number *)obj_1)->Subtract(*(Number *)obj_2);
        }
        else
        {
            err = ((Text *)obj_1)->Subtract(*(Text *)obj_2);
        }

        return err;
    };

    return DoMath(var_id_1, var_id_2, SUBTRACT_CODE, callback);
}

int ChmrInterpreter::Multiply(string var_id_1, string var_id_2)
{
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num)
    {
        if (!is_num)
        {
            return FAIL;
        }

        return ((Number *)obj_1)->Multiply(*(Number *)obj_2);
    };

    return DoMath(var_id_1, var_id_2, MULTIPLY_CODE, callback);
}

int ChmrInterpreter::Divide(string var_id_1, string var_id_2)
{
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num)
    {
        if (!is_num)
        {
            return FAIL;
        }

        return ((Number *)obj_1)->Divide(*(Number *)obj_2);
    };

    return DoMath(var_id_1, var_id_2, DIVIDE_CODE, callback);
}

int ChmrInterpreter::Pow(string base_id, string exp_id)
{
    auto callback = [](ChimeraObject *obj_1, ChimeraObject *obj_2, bool is_num)
    {
        if (!is_num)
        {
            return FAIL;
        }

        return ((Number*)obj_1)->Pow(*(Number*)obj_2);
    };

    return DoMath(base_id, exp_id, POW_CODE, callback);
}

string ChmrInterpreter::Cast(string var_id, string type)
{
    if (!m_table.Has(var_id))
    {
        cout << "Error: var " << var_id << " doesn't exist\n";
        return EMPTY_VAR_NAME;
    }

    auto var = m_table.GetEntry(var_id)->ConvertTo(type);

    if (var == nullptr)
    {
        cout << "Error: trying to convert to non-supported type " << type << '\n';
        return EMPTY_VAR_NAME;
    }

    return m_table.AddEntry("", var);
}

string ChmrInterpreter::And(string var_id_1, string var_id_2)
{
    return DoLogicOper(var_id_1, var_id_2, [](bool b1, bool b2) { return b1 && b2; });
}

string ChmrInterpreter::Or(string var_id_1, string var_id_2)
{
    return DoLogicOper(var_id_1, var_id_2, [](bool b1, bool b2) { return b1 || b2; });
}

string ChmrInterpreter::Not(string var_id_1)
{
    if (!m_table.Has(var_id_1))
    {
        cout << "Error: cannot perform logical oper on nonexistent\n";
        return EMPTY_VAR_NAME;
    }

    auto var = m_table.GetEntry(var_id_1);
    auto bool_var_name = m_table.AddEntry("", var->ConvertTo(BOOL_TYPE_NAME));
    auto bool_var = m_table.GetEntry(bool_var_name);

    bool res = false;
    bool_var->Get(res);

    return Create(EMPTY_VAR_NAME, BOOL_TYPE_NAME, !res);
}

string ChmrInterpreter::Less(string var_id_1, string var_id_2)
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: cannot compare nonexistent values\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Less(var_2));
}

string ChmrInterpreter::LessEqual(string var_id_1, string var_id_2)
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: cannot compare nonexistent values\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->LessEqual(var_2));
}

string ChmrInterpreter::Greater(string var_id_1, string var_id_2)
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: cannot compare nonexistent values\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Greater(var_2));
}

string ChmrInterpreter::GreaterEqual(string var_id_1, string var_id_2)
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: cannot compare nonexistent values\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->GreaterEqual(var_2));
}

string ChmrInterpreter::Equal(string var_id_1, string var_id_2)
{
    if (!m_table.Has(var_id_1) || !m_table.Has(var_id_2))
    {
        cout << "Error: cannot compare nonexistent values\n";
        return EMPTY_VAR_NAME;
    }

    auto var_1 = m_table.GetEntry(var_id_1);
    auto var_2 = m_table.GetEntry(var_id_2);

    return CreateTmpVar(var_1->Equal(var_2));
}

void ChmrInterpreter::GarbageCollect()
{
    m_table.FreeTempItems();
}

bool ChmrInterpreter::HasVar(string var_id)
{
    return m_table.Has(var_id);
}

int ChmrInterpreter::PrintVar(string var_id, char end)
{
    if (!m_table.Has(var_id))
    {
        cout << "Error: cannot print var " << var_id << '\n';
        return FAIL;
    }

    auto obj = m_table.GetEntry(var_id);
    cout << *obj << end;

    return SUCCEED;
}

// PUBLIC METHODS ABOVE -----------------------------------------------------------------------------