
%{
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "Utils/UnionStruct.hpp"
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;
%}

%define parse.error verbose

// variable types
%token <types> INT FLOAT DOUBLE BOOL CHAR STRING LIST

// keywords
%token CAST LESS GREATER LESS_EQUAL GREATER_EQUAL EQUAL NOT_EQUAL PRINT AND OR NOT EXIT 
%token NEWLINE SEMICOLON EOPU REF ADD SUB MUL DIV POW PUT SET GET

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
%type <tmp_id> term expr exprList math_expr compare_expr boolExpr unionTypes

%token UNKNOWN

%start line

%%

newline:                        NEWLINE | SEMICOLON;

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
                                                    string tmp = CloneToTemp($1, i);
                                                    if (tmp.empty()) {
                                                        return 1;
                                                    }
                                                    $$ = tmp;
                                                }
                                ;

types:                          INT             { $$ = $1; }
                                | FLOAT         { $$ = $1; }
                                | DOUBLE        { $$ = $1; }
                                | BOOL          { $$ = $1; }
                                | CHAR          { $$ = $1; }
                                | STRING        { $$ = $1; }
                                ;


unionTypes:                     types opt_ws '|' opt_ws types{
                                    $1.AddPending($1);
                                    $1.AddPending($5);
                                    $$ = $1;
                                }
                                | unionTypes opt_ws '|' opt_ws types {
                                    $1.AddPending($5);
                                    $$ = $1;
                                }
                                ;

any_ws:                         MULTI_WS | SINGLE_WS;

opt_ws:                         any_ws | %empty;

assign:                         ID ':' opt_ws types opt_ws '=' opt_ws expr {
                                    if (Assign($1, $8, $4, i).empty()) {
                                        return 1;
                                    }
                                }
                                | ID ':' opt_ws UNKNOWN opt_ws '=' opt_ws expr {
                                    bool made_union = !MakeUnknown($ID, $expr, i).empty();
                                    if(!made_union) {
                                        return 1;
                                    }
                                }
                                | ID ':' opt_ws unionTypes opt_ws '=' opt_ws expr {
                                    auto union_name = MakeUnion($ID, $unionTypes, $expr, i);
                                    if (union_name.empty()) {
                                        return 1;
                                    }
                                }
                                | ID opt_ws '=' opt_ws expr {
                                    if(Reassign($1, $5, i).empty()) {
                                        return 1;
                                    }
                                }
                                | ID ':' opt_ws types '<' REF '>' opt_ws '=' opt_ws expr {
                                    if (i.RefBind($ID, $expr, $types).empty()) {
                                        return 1;
                                    }
                                }
                                | ID ':' opt_ws LIST '<' types '>' opt_ws '=' opt_ws '[' ']' {
                                    if(i.MakeList($ID, $types).empty()) {
                                        return 1;
                                    }
                                }
                                | ID ':' opt_ws LIST '<' types '>' opt_ws '=' opt_ws expr {
                                    string id = i.MakeList($ID, $types);
                                    if(i.ReassignList(id, $expr).empty()) {
                                        return 1;
                                    }
                                }
                                | ID opt_ws '=' opt_ws expr '<' REF '>' {
                                    if (i.RefBind($ID, $expr).empty()) {
                                        return 1;
                                    }
                                }
                                ;


exprList:                      opt_ws expr {
                                    if(!$expr.GetFinalResult().empty()) { 
                                        $expr.AddPending($expr); 
                                    }
                                    $$ = $expr; 
                                } 
                                | opt_ws NEWLINE opt_ws expr {
                                    if(!$expr.GetFinalResult().empty()) {
                                        $expr.AddPending($expr);
                                    }
                                    $$ = $expr;
                                }
                                | exprList[prev] any_ws expr {  
                                    if(!$prev.GetFinalResult().empty()) { 
                                        $prev.AddPending($expr); 
                                    }
                                    for(unsigned int i = 0; i < $expr.PendingDataSize(); i++) {
                                        $prev.AddPending($expr[i]);
                                    }
                                    $$ = $prev;
                                }
                                | exprList[prev] opt_ws NEWLINE opt_ws expr {
                                    auto list = $prev;
                                    if(!list.GetFinalResult().empty()) { 
                                        list.AddPending($expr); 
                                    }
                                    for(unsigned int i = 0; i < $expr.PendingDataSize(); i++) {
                                        list.AddPending($expr[i]);
                                    }
                                    $$ = list;
                                }
                                ;

opt_newline:                    opt_ws NEWLINE opt_ws;
opt_ws_or_nl:                opt_ws | opt_newline;
ws_or_nl:                    any_ws | opt_newline;

statement:                      assign
                                | PRINT opt_ws '|' exprList opt_ws_or_nl '|' { 
                                    int err = Print($exprList, ' ', i);
                                    
                                    if (err == 1) {
                                        cout << "Error: print error\n";
                                        return 1;
                                    }
                                    else if ($exprList.PendingDataSize() > 0) {
                                        cout << '\n';
                                    }
                                }
                                | EXIT '|' opt_ws '|'{ return 0; }
                                ;


//MATH OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
math_expr:                      '(' ADD any_ws expr[left] any_ws exprList[right] opt_ws')' {
                                    string tmp = Add($left, $right, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' ADD any_ws expr opt_ws ')' {
                                    string tmp = Add($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' SUB any_ws expr any_ws exprList ')' {
                                    string tmp = Subtract($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' SUB any_ws expr opt_ws ')' {
                                    string tmp = Subtract($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' MUL any_ws expr any_ws exprList ')' {
                                    string tmp = Multiply($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' MUL any_ws expr opt_ws ')' {
                                    string tmp = Multiply($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' DIV any_ws expr any_ws exprList opt_ws_or_nl ')' {
                                    string tmp = Divide($4, $6, i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' DIV any_ws expr opt_ws ')' {
                                    string tmp = Divide($4, i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' POW any_ws expr any_ws expr opt_ws ')' {
                                    string var_1 = $4;
                                    string var_2 = $6;

                                    if (var_1.empty()) {
                                        var_1 = $4[0];
                                    }
                                    if (var_2.empty()) {
                                        var_2 = $6[0];
                                    }
                                    
                                    if (i.Pow(var_1, var_2) == 1) {
                                        return 1;
                                    }
                                    $4.ClearPending();
                                    $$ = var_1;
                                }
                                ;
//MATH OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------------

//COMPARE OPERS BELOW --------------------------------------------------------------------------------------------------------------------------------------------------

compare_expr:                   '(' LESS any_ws expr any_ws expr opt_ws ')' {
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
                                ;
//COMPARE OPER ABOVE ------------------------------------------------------------------------------------------------------------------------------------------------

//BOOL OPERS BELOW ---------------------------------------------------------------------------------------------------------------------------------------------------
boolExpr:                      '(' AND any_ws expr any_ws expr opt_ws ')' {
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
//BOOL OPER ABOVE -----------------------------------------------------------------------------------------------------------------------------------------------------

expr:                           term {
                                    $$ = $1;
                                }
                                | math_expr {
                                    $$ = $1;
                                }
                                | '(' CAST any_ws exprList ws_or_nl types opt_ws_or_nl ')' {
                                    string tmp = Cast($$, $4, $types, i);
                                    if (tmp.empty()) {
                                        cout << "Error: couldn't cast\n";
                                        return 1;
                                    }
                                }
                                | compare_expr {
                                    $$ = $1;
                                }
                                | boolExpr {
                                    $$ = $1;
                                }
                                | '(' PUT any_ws ID[list] any_ws exprList[item] opt_ws ')' {
                                    for(size_t index = 0; index < $item.PendingDataSize(); index++) {
                                        i.PutInList($list, $item[index]);
                                    }
                                    string tmp = "h";
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | ID[list] '[' expr[index] ']' {
                                    string tmp = i.GetFromList($list, $index);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                | '(' SET any_ws ID[list] any_ws expr[index] any_ws expr[new_val] opt_ws ')' {
                                    string tmp = i.SetInList($list, $index, $new_val);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    $$ = tmp;
                                }
                                ;

prog:                           expr newline 
                                | expr EOPU
                                | statement newline
                                | statement EOPU
                                | newline 
                                | EOPU { 
                                    return 0 ;
                                }
                                | any_ws  
                                | error { i.GarbageCollect(); return 1; };

line:                           prog {i.GarbageCollect();} | line prog {i.GarbageCollect();};
%%


void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
    cout << yytext << '\n';
}

int main(int argc, char *argv[]) {
    bool in_file_mode = false;
    FILE *file = nullptr;
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        
        if (file != nullptr) {
            yyin = file;
            in_file_mode = true;
        }
        else {
            cout << "Error: file doesn't exist\n";
            return 1;
        }
    }
    int x = yyparse();
    while(x != 0 && !in_file_mode) {
        // makes sure to clear the token buffer
        // so that when a parser or interpreter error
        // happens, tokens aren't trying to be read again
        yyrestart(yyin);
        
        x = yyparse();
    }

    if (file != nullptr) {
        fclose(file);
    }
    return x;
}