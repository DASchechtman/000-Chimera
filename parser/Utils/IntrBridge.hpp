/*
this is a header full of wrapper functions that wrap the public method of the interpreter class.
I did this because bison/yacc mix code and parser syntax into one thing, so I was trying to extract as
much code into it's own cpp file as possible so that I can keep things more flexible
*/
#pragma once

#include <string>
#include <vector>
#include "../../src/ChmrInterpreter.hpp"
#include "StrWrapper.hpp"

using namespace std;

string Assign(StrWrapper new_var, StrWrapper data_var, StrWrapper type, ChmrInterpreter &i);
string RefBind(StrWrapper id, StrWrapper expr, StrWrapper types, ChmrInterpreter &i);
string RefBind(StrWrapper id, StrWrapper expr, ChmrInterpreter &i);
string Reassign(StrWrapper var, StrWrapper data_var, ChmrInterpreter &i);
string CloneToTemp(StrWrapper id, ChmrInterpreter &i);
string MakeUnion(StrWrapper id, vector<string> types, StrWrapper data, ChmrInterpreter &i);
string MakeUnknown(StrWrapper id, StrWrapper data, ChmrInterpreter &i);
string MakeList(StrWrapper id, StrWrapper types, ChmrInterpreter &i);
string MakeMap(StrWrapper id, StrWrapper key_type, StrWrapper val_types, ChmrInterpreter &i);
int Print(StrWrapper var_id, char end, ChmrInterpreter &i);

string Add(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Subtract(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Multiply(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Divide(StrWrapper var_id_1, StrWrapper var_id_2, ChmrInterpreter &i);
string Pow(StrWrapper id_1, StrWrapper id_2, ChmrInterpreter &i);

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

string PutInContainer(StrWrapper list_id, StrWrapper item_id, ChmrInterpreter &i);
string PutInMap(StrWrapper map_id, StrWrapper key, StrWrapper val, ChmrInterpreter &i);
string GetFromContainer(StrWrapper list_id, StrWrapper index_id, ChmrInterpreter &i);
string SetInContainer(StrWrapper list_id, StrWrapper index_id, StrWrapper new_item_id, ChmrInterpreter &i);
string ReassignContainer(StrWrapper list_id_1, StrWrapper types, StrWrapper list_id_2, ChmrInterpreter &i);

void CreateScope(ChmrInterpreter &i);
void DestroyScope(ChmrInterpreter &i);
void GarbageCollect(ChmrInterpreter &i);
int SetNextScopeRunState(StrWrapper expr_id, ChmrInterpreter &i);

template<class T>
string CreateTempVar(T data, ChmrInterpreter &i) {
    return i.CreateTmpVar(data);
}