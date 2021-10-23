%{
#include "Parser.hpp"
%}

%%
.           { return UNKNOWN; }
%%


int yywrap() {return 1;}