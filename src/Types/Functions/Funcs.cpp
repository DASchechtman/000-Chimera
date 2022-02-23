#include "Funcs.hpp"

ChmrFunc::ChmrFunc(
    size_t start_point,
    string &ret_type,
    string func_name
) {
    m_start_point = start_point;
    m_func_name = func_name;

    ChimeraObject *default_val = new Int();
    ret_val = default_val->ConvertTo(ret_type);
    SetType(FUNC_DATA_TYPE);
    delete default_val;
}

ChmrFunc::~ChmrFunc() {
    delete ret_val;
}

size_t ChmrFunc::GetStartPoint() {
    return m_start_point;
}

size_t ChmrFunc::GetEndPoint() {
    return m_call_point;
}

ChimeraObject* ChmrFunc::GetRet() {
    return ret_val;
}

void ChmrFunc::SetEndPoint(size_t new_end_point) {
    m_call_point = new_end_point;
}

void ChmrFunc::AddParam(string name, string type) {
    m_param_type_list.insert(m_param_type_list.end(), {name, type});
}

void ChmrFunc::SetRetDest(ChimeraObject *dest) {
    ret_val = dest;
}

void ChmrFunc::StoreValInRet(ChimeraObject *ret) {
    if (ret_val != nullptr && ret != nullptr) {
        ret_val->Set(ret);
    }
}

string ChmrFunc::GetParamData(size_t index) {
    return m_param_type_list[index];
}

size_t ChmrFunc::ParamNums() {
    return m_param_type_list.size();
}

int ChmrFunc::Get(int64 &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(float &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(dbl128 &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(char32_t &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(bool &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(string &data) {
    return ret_val->Get(data);
}

string ChmrFunc::ToStr() {
    return m_func_name;
}

int64 ChmrFunc::ToInt() {
    return (int64)m_param_type_list.size();
}

float ChmrFunc::ToFloat() {
    return (float)ToInt();
}

dbl128 ChmrFunc::ToDouble() {
    return (dbl128)ToInt();
}

char32_t ChmrFunc::ToChar() {
    return m_func_name[0];
}

bool ChmrFunc::ToBool() {
    return true;
}

ChimeraObject* ChmrFunc::Clone() {
    string type = ret_val->GetTypeName();
    return new ChmrFunc(
        m_start_point,
        type,
        m_func_name
    );
}

