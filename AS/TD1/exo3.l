%{
#include <ctype.h>
%}

%%

[a-z] { printf("%c", toupper(yytext[0])); }

