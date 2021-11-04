/*
this is a header full of wrapper functions that wrap the public method of the interpreter class.
I did this because bison/yacc mix code and parser syntax into one thing, so I was trying to extract as
much code into it's own cpp file as possible so that I can keep things more flexible
*/
#pragma once

#include <string>
#include "../../src/ChmrInterpreter.hpp"
#include "StrWrapper.hpp"

using namespace std;

string Assign(StrWrapper new_var, StrWrapper data_var, StrWrapper type, ChmrInterpreter &i);
string Reassign(StrWrapper var, StrWrapper data_var, ChmrInterpreter &i);
string CloneToTemp(StrWrapper id, ChmrInterpreter &i);
int Print(StrWrapper var_id, char end, ChmrInterpreter &i);

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

string Cast(StrWrapper &store, StrWrapper var_id, StrWrapper type, ChmrInterpreter &i);

template<class T>
string CreateTempVar(T data, ChmrInterpreter &i) {
    return i.CreateTmpVar(data);
}