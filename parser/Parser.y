
%{
#include <iostream>

using namespace std;

void yyerror(const char* err);
extern int yylex();
%}

%token UNKNOWN

%start line

%%
line: UNKNOWN | line UNKNOWN;
%%


void yyerror(const char* err) {
    cout << err << '\n';
}

int main() {
    return yyparse();
}