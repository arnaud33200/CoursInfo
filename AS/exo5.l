%{
#include <stdlib.h>
%}

%%

[[:digit:]]+ { printf(" convertie:%i: ", atoi(yytext)); }
<<EOF>> { printf("\n"); return 0; }
