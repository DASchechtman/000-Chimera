%{
#include "Utils/UnionStruct.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

vector<YYSTYPEs*> ptrs;

char CharVal(const char* str);
string TextVal(const char* str);
void Init(YYSTYPEs *&data);
%}

%option nounput
%option noinput

ID                      [a-zA-Z][a-zA-Z0-9_?]*
DIGIT                   [0-9]
DEC                     ({DIGIT}+[.]{DIGIT}+|[.]{DIGIT}+|{DIGIT}+d)
FLOAT                   ({DEC}f|{DIGIT}+f)
CHAR                    (\\.|[^\\"])
SINGLE_CHAR_TOKS        [=:()/|\[\].{}]
SINGLE_SEP              [ \f\v\t]
MULTI_SEP               {SINGLE_SEP}{2,}
COMMENT                 #[^\n]*\n?
MULTI_LN_COMMENT        $[^$]*$\n?

%%
{COMMENT}                       { ; }
{MULTI_LN_COMMENT}              { ; }

int                             { Init(yylval.data); yylval.data->types = yytext; return INT; }
float                           { Init(yylval.data); yylval.data->types = yytext; return FLOAT; }
double                          { Init(yylval.data); yylval.data->types = yytext; return DOUBLE; }
bool                            { Init(yylval.data); yylval.data->types = yytext; return BOOL; }
char                            { Init(yylval.data); yylval.data->types = yytext; return CHAR; }
string                          { Init(yylval.data); yylval.data->types = yytext; return STRING; }
unknown                         { Init(yylval.data); yylval.data->types = yytext; return UNKNOWN; }
list                            { Init(yylval.data); yylval.data->types = yytext; return LIST; }
ref                             { return REF; }
map                             { Init(yylval.data); yylval.data->types = yytext; return MAP; }

cast                            { return CAST; }
(\<|less)                       { return LESS; }
(>|greater)                     { return GREATER; }
(\<=|less-equal)                { return LESS_EQUAL; }
(>=|greater-equal)              { return GREATER_EQUAL; }
(==|equal)                      { return EQUAL; }
(!=|not-equal)                  { return NOT_EQUAL; }
print                           { return PRINT; }
(&|:S|and)                      { return AND; }
(\^|:\\|or)                     { return OR; }
(!|=o|not)                      { return NOT; }
exit                            { return EXIT; }
(\+|add)                        { return ADD; }
(\-|sub)                        { return SUB; }
(\*|mul)                        { return MUL; }
(\/|div)                        { return DIV; }
(\^|pow)                        { return POW; }
(\%|mod)                        { return MOD; }
var                             { return ASSIGN; }
addTo                           { return ADD_LIST; }
put                             { return ADD_MAP; }
set                             { return SET; }
get                             { return GET; }
start                           { return START; }
end                             { return END; }
if                              { return IF; }
else-if                         { return ELSE_IF; }
else                            { return ELSE; }
while                           { return WHILE; }
size                            { return SIZE; }
repeat                          { return REPEAT; }
with                            { return WITH; }
inc                             { return INC; }
suro                            { return SURO; }
furo                            { return FURO; }
func                            { return FUNC; }
call                            { return CALL; }
return                          { return FUNC_RET; }
has                             { return HAS; }
remove                          { return REMOVE; }
typeof                          { return TYPEOF; }

true                            { Init(yylval.data); yylval.data->bol_val = true; return BOOL_VAL; }
false                           { Init(yylval.data); yylval.data->bol_val = false; return BOOL_VAL; }
{ID}                            { Init(yylval.data); yylval.data->id = yytext; return ID; }
-?{DEC}                         { Init(yylval.data); yylval.data->dou_val = strtod(yytext, nullptr); return DOUBLE_VAL; }
-?{FLOAT}                       { Init(yylval.data); yylval.data->flo_val = strtod(yytext, nullptr); return FLOAT_VAL; }
-?{DIGIT}+                      { Init(yylval.data); yylval.data->int_val = stoll(string(yytext)); return INT_VAL; }
\"{CHAR}*\"                     { Init(yylval.data); yylval.data->str_val.SetWithOmittedEnds(TextVal(yytext).c_str()); return STRING_VAL; }
\'{CHAR}\'                      { Init(yylval.data); yylval.data->char_val = CharVal(yytext); return CHAR_VAL; }

{SINGLE_CHAR_TOKS}              { return yytext[0]; }
(\n|\r\n|\r)                    { return NEWLINE; }
;                               { return SEMICOLON; }

\t+                             { return MULTI_WS; }
{MULTI_SEP}                     { return MULTI_WS; }
{SINGLE_SEP}                    { return SINGLE_WS; }

<<EOF>>                         { return EOPU; }

.                               { return UNKNOWN;}
%%

void AddEscapeCharToString(char type, string &str) {
    switch(type) {
        case 'n': {
            str += '\n';
            break;
        }
        case 't': {
            str += '\t';
            break;
        }
        case '\'': {
            str += '\'';
            break;
        }
        case '"': {
            str += '"';
            break;
        }
        case '\\': {
            str += '\\';
            break;
        }
        case 'r': {
            str += '\r';
            break;
        }
        case 'b': {
            str += '\b';
            break;
        }
        case 'f': {
            str += '\f';
            break;
        }
        case 'v': {
            str += '\v';
            break;
        }
    }
}

char CharVal(const char* str) {
    auto char_val = string(yytext);
    char ret = 0;
    if (char_val[1] == '\\') {
        auto esp_char = string();
        AddEscapeCharToString(char_val[2], esp_char);
        ret = esp_char[0];
    }
    else {
        ret = char_val[1];
    }
    return ret;
}

string TextVal(const char* str) {
    auto str_val = string(str);
    string ret_val = "";
    for(size_t i = 0; i < str_val.length(); i++) {
        char c = str_val[i];
        if (c == '\\') {
            char next_c = str_val[i+1];
            AddEscapeCharToString(next_c, ret_val);
            i++;
            continue;
        }

        ret_val += c;
    }
    return ret_val;
}

void Init(YYSTYPEs *&data) {
    if (data != nullptr) {
        return;
    }
    data = new YYSTYPEs();
    ptrs.push_back(data);
}

void Destroy() {
    for(auto ptr : ptrs) {
        delete ptr;
    }
    ptrs.resize(0);
}

int yywrap() {return 1;}