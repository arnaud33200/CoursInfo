%{
#include <ctype.h>
%}

%%

^[a-z] { printf("%c", toupper(yytext[0])); }
<<EOF>> { printf("\n"); return 0; }


