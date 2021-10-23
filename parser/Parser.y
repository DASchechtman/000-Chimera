
%{
#include <iostream>

using namespace std;

int lineno = 0;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
%}

%token UNKNOWN

%start line

%%
line: UNKNOWN { PrintLineNo(); }| line UNKNOWN { PrintLineNo(); };
%%


void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
}

int main() {
    return yyparse();
}