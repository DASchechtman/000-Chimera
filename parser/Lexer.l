%{
#include "Utils/UnionStruct.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char CharVal(const char* str);
string TextVal(const char* str);
%}

ID                      [a-zA-Z][a-zA-Z0-9_?]*
DIGIT                   [0-9]
DEC                     ({DIGIT}+[.]{DIGIT}+|[.]{DIGIT}+)
FLOAT                   ({DEC}f|{DIGIT}+f)
CHAR                    (\\.|[^\\"])
SINGLE_CHAR_TOKS        [=:()+\-*/|^]
NEWLINE_TOKS            [\n;]
SEPERATOR               [ \t]{2,}
SINGLE_SEP              [ ]
COMMENT                 #[^\n]*\n?
MULTI_LN_COMMENT        $[^$]*$\n?

%%
{COMMENT}                       { ; }
{MULTI_LN_COMMENT}              { ; }
int                             { yylval.types = yytext; return INT; }
float                           { yylval.types = yytext; return FLOAT; }
double                          { yylval.types = yytext; return DOUBLE; }
bool                            { yylval.types = yytext; return BOOL; }
char                            { yylval.types = yytext; return CHAR; }
string                          { yylval.types = yytext; return STRING; }

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

true                            { yylval.bol_val = true; return BOOL_VAL; }
false                           { yylval.bol_val = false; return BOOL_VAL; }
{ID}                            { yylval.id = yytext; return ID; }
{DEC}                           { yylval.dou_val = strtod(yytext, nullptr); return DOUBLE_VAL; }
{FLOAT}                         { yylval.flo_val = atof(yytext); return FLOAT_VAL; }
{DIGIT}+                        { yylval.int_val = atoi(yytext); return INT_VAL; }
\"{CHAR}*\"                     { yylval.str_val.SetWithOmittedEnds(TextVal(yytext).c_str()); return STRING_VAL; }
\'{CHAR}\'                      { yylval.char_val = CharVal(yytext); return CHAR_VAL; }

{SINGLE_CHAR_TOKS}              { return yytext[0]; }
\n                              { return NEWLINE; }
;                               { return SEMICOLON; }
{SEPERATOR}                     { return MULTI_WS; }
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

    for (unsigned int i = 0; i < yyleng; i++) {
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

    return ret_str.c_str();
}

int yywrap() {return 1;}