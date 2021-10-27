
%{
#include <iostream>
#include <string>
#include "Utils/UnionStruct.hpp"
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern char *yytext;

%}

%define parse.error verbose

// variable types
%token <types> INT FLOAT DOUBLE BOOL CHAR STRING

// keywords
%token CAST LESS GREATER LESS_EQUAL GREATER_EQUAL EQUAL NOT_EQUAL PRINT AND OR NOT EXIT 
%token NEWLINE

// data values
%token <int_val> INT_VAL 
%token <dou_val> DOUBLE_VAL 
%token <str_val> STRING_VAL
%token <char_val> CHAR_VAL 
%token <bol_val> BOOL_VAL 
%token <flo_val> FLOAT_VAL

// whitespaces
%token MULTI_WS SINGLE_WS

// user defined names
%token <id> ID

%type <types> types
%type <tmp_id> term expr expr_list

%token UNKNOWN

%start line

%%

newline:                        NEWLINE;

term:                           INT_VAL         { 
                                                    string tmp_name = CreateTempVar($1, i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    $$ = tmp_name;
                                                }
                                | DOUBLE_VAL    { 
                                                    string tmp_name = CreateTempVar($1, i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    $$ = tmp_name;
                                                }
                                | FLOAT_VAL     { 
                                                    string tmp_name = CreateTempVar($1, i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    $$ = tmp_name;
                                                }
                                | STRING_VAL    { 
                                                    // deliberately declared data type here
                                                    // because $1 is a StrWrapper, not a string. 
                                                    // so implicit conversion will cause bugs that don't
                                                    // allow for compilation
                                                     string tmp_name = CreateTempVar<string>($1, i);
                                                     if (tmp_name.empty()) {
                                                         cout << "Error: couldn't create temp var\n";
                                                         return 1;
                                                     }
                                                     $$ = tmp_name;
                                                }
                                | CHAR_VAL      { 
                                                    string tmp_name = CreateTempVar($1, i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    $$ = tmp_name;
                                                }
                                | BOOL_VAL      { 
                                                    string tmp_name = CreateTempVar($1, i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    $$ = tmp_name;
                                                }
                                | ID            { 
                                                    $$ = CloneToTemp($1, i);
                                                }
                                ;

types:                          INT             { $$ = $1; }
                                | FLOAT         { $$ = $1; }
                                | DOUBLE        { $$ = $1; }
                                | BOOL          { $$ = $1; }
                                | CHAR          { $$ = $1; }
                                | STRING        { $$ = $1; }
                                ;

any_ws:                         MULTI_WS | SINGLE_WS;

opt_ws:                         any_ws | %empty;

assign:                         ID ':' opt_ws types opt_ws '=' opt_ws expr {
                                    if (Assign($1, $8, $4, i).empty()) {
                                        return 1;
                                    }
                                }
                                | ID opt_ws '=' opt_ws expr {
                                    if(Reassign($1, $5, i).empty()) {
                                        return 1;
                                    }
                                }
                                ;


expr_list:                      expr {
                                    if(!$1.GetFinalResult().empty()) { 
                                        $1.AddPending($1); 
                                    }
                                    $$ = $1; 
                                } 
                                | expr_list any_ws expr {  
                                    if(!$1.GetFinalResult().empty()) { 
                                        $1.AddPending($3); 
                                    }
                                    for(unsigned int i = 0; i < $3.PendingDataSize(); i++) {
                                        $1.AddPending($3[i]);
                                    }
                                    $$ = $1;
                                }
                                ;



statement:                      assign newline
                                | PRINT opt_ws '|' opt_ws expr_list opt_ws '|' newline { 
                                    for(unsigned int index = 0; index < $5.PendingDataSize(); index++) {
                                        Print($5[index], ' ', i);
                                    }
                                    
                                    cout << "\n"; 
                                }
                                | EXIT {
                                    return 0;
                                }
                                | newline
                                ;

expr:                           term {
                                    $$ = $1;
                                }
                                | '(' '+' any_ws expr any_ws expr_list opt_ws')' {
                                    string tmp = Add($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '+' any_ws expr opt_ws ')' {
                                    string tmp = Add($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '-' any_ws expr any_ws expr_list ')' {
                                    string tmp = Subtract($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '-' any_ws expr opt_ws ')' {
                                    string tmp = Subtract($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '*' any_ws expr any_ws expr_list ')' {
                                    string tmp = Multiply($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '*' any_ws expr opt_ws ')' {
                                    string tmp = Multiply($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '/' any_ws expr any_ws expr_list ')' {
                                    string tmp = Divide($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '/' any_ws expr opt_ws ')' {
                                    string tmp = Divide($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' '^' any_ws expr any_ws expr opt_ws ')' {
                                    if (i.Pow($4, $6) == 1) {
                                        return 1;
                                    }
                                    $$ = $4;
                                }
                                | '(' CAST any_ws expr_list any_ws types ')' {
                                    string tmp = Cast($$, $4, $6, i);
                                    if (tmp.empty()) {
                                        cout << "Error: couldn't cast\n";
                                        return 1;
                                    }
                                }
                                | '(' LESS any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = Less($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' GREATER any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = Greater($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' LESS_EQUAL any_ws expr any_ws expr opt_ws ')'{
                                    string tmp = LessEqual($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' GREATER_EQUAL any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = GreaterEqual($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '('EQUAL any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = Equal($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' NOT_EQUAL any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = NotEqual($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' AND any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = And($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' NOT any_ws expr opt_ws ')' {
                                    string tmp = Not($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' OR any_ws expr any_ws expr opt_ws ')' {
                                    string tmp = Or($4, $6, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                ;

prog:                           expr | statement | error { i.GarbageCollect(); return 1; };

line:                           prog {i.GarbageCollect();} | line prog {i.GarbageCollect();};
%%


void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
}

int main() {
    int x = yyparse();
    while(x != 0) {
        x = yyparse();
    }
    return x;
}