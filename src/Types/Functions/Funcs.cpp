#include "Funcs.hpp"

ChmrFunc::ChmrFunc(
    size_t start_point,
    string &ret_type,
    COMMANDS func_type,
    string func_name
) {
    m_start_point = start_point;
    m_func_name = func_name;
    m_type = func_type;

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
    return m_end_of_func_point;
}

ChimeraObject* ChmrFunc::GetRet() {
    return ret_val;
}

void ChmrFunc::SetFuncEndPoint(size_t new_end_point) {
    m_end_of_func_point = new_end_point;
}

void ChmrFunc::AddParam(string name, string type) {
    m_param_type_list.insert(m_param_type_list.end(), {name, type});
}

void ChmrFunc::SetRetDest(ChimeraObject *dest) {
    ret_val = dest;
}

int ChmrFunc::StoreValInRet(ChimeraObject *ret) {
    int store_res = FAIL;
    if (ret_val != nullptr && ret != nullptr) {
        store_res = ret_val->Set(ret);
    }
    return store_res;
}

string ChmrFunc::GetParamData(size_t index) {
    return m_param_type_list[index];
}

size_t ChmrFunc::ParamNums() {
    return m_param_type_list.size();
}

void ChmrFunc::CopyParamsToNewContext(
    vector<string> &names, 
    Memory &tbl,
    Memory &other_tbl
) {
    for(size_t i = 0; i < names.size(); i += 2) {
        switch(m_type) {
            case FUNC_SURO_TYPE: {
                tbl.TransferData(names[i], names[i+1], other_tbl, [](string &name, Memory &mem) {
                    return mem.IsTemp(name) || mem.IsConst(name) ? CLONED : ORIGINAL;
                });
                break;
            }
            case FUNC_FURO_TYPE: {
                tbl.TransferData(names[i], names[i+1], other_tbl, [](string &name, Memory &mem) {
                    return CLONED;
                });
                break;
            }
            case FUNC_FUNC_TYPE: {
                tbl.TransferData(names[i], names[i+1], other_tbl, [](string &name, Memory &mem) {
                    if (mem.IsTemp(name) || mem.IsConst(name)) {
                        return CLONED;
                    }

                    if (mem.GetData(ORIGINAL, name)->GetGeneralType() == COLLECTION_DATA_TYPE) {
                        return ORIGINAL;
                    }

                    return CLONED;
                });
                break;
            }
            default: {}
        }
    }
}

int ChmrFunc::Get(chmr_int &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(chmr_flt &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(chmr_dbl &data) {
    return ret_val->Get(data);
}

int ChmrFunc::Get(chmr_char &data) {
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

chmr_int ChmrFunc::ToInt() {
    return (chmr_int)m_param_type_list.size();
}

chmr_flt ChmrFunc::ToFloat() {
    return (chmr_flt)ToInt();
}

chmr_dbl ChmrFunc::ToDouble() {
    return (chmr_dbl)ToInt();
}

chmr_char ChmrFunc::ToChar() {
    return m_func_name[0];
}

bool ChmrFunc::ToBool() {
    return true;
}

ChimeraObject* ChmrFunc::Clone() {
    string type = ret_val->GetTypeName();
    auto new_func =  new ChmrFunc(
        m_start_point,
        type,
        m_type,
        m_func_name
    );

    for(size_t i = 0; i < m_param_type_list.size(); i += 2) {
        new_func->AddParam(m_param_type_list[i], m_param_type_list[i+1]);
    }

    return new_func;
}

