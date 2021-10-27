#pragma once

#include <string>
#include "../../src/ChmrInterpreter.hpp"
#include "StrWrapper.hpp"

using namespace std;

string Assign(string new_var, string data_var, string type, ChmrInterpreter &i);
string Reassign(string var, string data_var, ChmrInterpreter &i);
string CloneToTemp(string id, ChmrInterpreter &i);
void Print(string var_id, char end, ChmrInterpreter &i);

string Add(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Subtract(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Multiply(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Divide(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);

string Add(StrWrapper var_id_1, ChmrInterpreter &i);
string Subtract(StrWrapper var_id_1, ChmrInterpreter &i);
string Multiply(StrWrapper var_id_1, ChmrInterpreter &i);
string Divide(StrWrapper var_id_1, ChmrInterpreter &i);

string And(StrWrapper var_id_1,  StrWrapper var_id_2, ChmrInterpreter &i);
string Or(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Not(StrWrapper var_id_1, ChmrInterpreter &i);

string Less(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string LessEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Greater(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string GreaterEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Equal(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string NotEqual(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);

string Cast(StrWrapper &store, StrWrapper var_id, string type, ChmrInterpreter &i);

template<class T>
string CreateTempVar(T data, ChmrInterpreter &i) {
    return i.CreateTmpVar(data);
}