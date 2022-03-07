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
SINGLE_CHAR_TOKS        [=:()+\-*/|^&\[\]<>.{}]
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
less                            { return LESS; }
greater                         { return GREATER; }
less-equal                      { return LESS_EQUAL; }
greater-equal                   { return GREATER_EQUAL; }
equal                           { return EQUAL; }
not-equal                       { return NOT_EQUAL; }
print                           { return PRINT; }
and                             { return AND; }
or                              { return OR; }
not                             { return NOT; }
exit                            { return EXIT; }
(\+|add)                        { return ADD; }
(\-|sub)                        { return SUB; }
(\*|mul)                        { return MUL; }
(\/|div)                        { return DIV; }
(\^|pow)                        { return POW; }
(\%|mod)                        { return MOD; }
addTo                           { return ADD_LIST; }
put                             { return ADD_MAP; }
set                             { return SET; }
get                             { return GET; }
->                              { return POINTS_TO; }
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
call                            { return CALL; }

true                            { Init(yylval.data); yylval.data->bol_val = true; return BOOL_VAL; }
false                           { Init(yylval.data); yylval.data->bol_val = false; return BOOL_VAL; }
{ID}                            { Init(yylval.data); yylval.data->id = yytext; return ID; }
-?{DEC}                         { Init(yylval.data); yylval.data->dou_val = strtod(yytext, nullptr); return DOUBLE_VAL; }
-?{FLOAT}                       { Init(yylval.data); yylval.data->flo_val = strtod(yytext, nullptr); return FLOAT_VAL; }
-?{DIGIT}+                      { Init(yylval.data); yylval.data->int_val = strtod(yytext, nullptr); return INT_VAL; }
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

char CharVal(const char* str) {
    char ret_val = 0;
    if (str[1] == '\\') {
        if (str[2] == 'n') {
            ret_val = '\n';
        }
        else if (str[2] == 't') {
            ret_val = '\t';
        }
        else {
            ret_val = str[2];
        }
    }
    else {
        ret_val = str[1];
    }
    return ret_val;
}

string TextVal(const char* str) {
    string ret_str;

    for (int i = 0; i < yyleng; i++) {
        char *c = nullptr;
        if (str[i] == '\\' && i+1 < yyleng) {
            c = new char[3];
            c[0] = '\0';
            c[1] = str[i];
            c[2] = str[i+1];  
            i++;
        }
        else {
           c = new char[2];
           c[0] = '\0';
           c[1] = str[i];
        }
        ret_str += CharVal(c);
        delete[] c;
    }

    return ret_str;
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