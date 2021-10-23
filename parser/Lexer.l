%{
#include "Parser.hpp"
%}

%%
[\n\t]      { ; }
.           { return UNKNOWN; }
%%


int yywrap() {return 1;}