#pragma once
#include "../../Cmds.hpp"
#include "../ChimeraObject.hpp"
#include "../Number/Derived/Int.hpp"
#include "../../DataStructs/Memory.hpp"
#include <map>
#include <vector>
#include <string>

using namespace std;

class ChmrFunc : public ChimeraObject {
private:
    vector<string> m_param_type_list;
    string m_func_name;
    COMMANDS m_type = NO_CMD;
    size_t m_start_point = 0;
    size_t m_end_of_func_point = 0;
    ChimeraObject *ret_val = nullptr;


protected:

public:
    ChmrFunc(
        size_t start_point,
        string &ret_type,
        COMMANDS func_type,
        string func_name = "anon"
    );
    ~ChmrFunc();

    Memory *create_scope_mem = nullptr;

    size_t GetStartPoint();
    size_t GetEndPoint();
    ChimeraObject* GetRet();
    void SetFuncEndPoint(size_t new_end_point);
    void AddParam(string name, string type);
    void SetRetDest(ChimeraObject *dest);
    int StoreValInRet(ChimeraObject *ret);
    string GetParamData(size_t index);
    size_t ParamNums();
    void CopyParamsToNewContext(
        vector<string> &names, 
        Memory &tbl,
        Memory &other_tbl
    );

    int Get(int64 &data);
    int Get(float &data);
    int Get(dbl128 &data);
    int Get(char32_t &data);
    int Get(bool &data);
    int Get(string &data);

    string ToStr();
    int64 ToInt();
    float ToFloat();
    dbl128 ToDouble();
    char32_t ToChar();
    bool ToBool();

    ChimeraObject* Clone();

};