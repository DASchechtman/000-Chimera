%{
#include "Utils/UnionStruct.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string.h>
using namespace std;

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

%%
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
\"{CHAR}*\"                     { yylval.str_val.SetWithOmittedEnds(yytext); return STRING_VAL; }
\'{CHAR}\'                      { yylval.char_val = yytext[1]; return CHAR_VAL; }

{SINGLE_CHAR_TOKS}              { return yytext[0]; }
{NEWLINE_TOKS}                  { return NEWLINE; }
{SEPERATOR}                     { return MULTI_WS; }
{SINGLE_SEP}                    { return SINGLE_WS; }

.                               { return UNKNOWN;}
%%

int yywrap() {return 1;}