%{
	#include <stdlib.h>
	#include "exo2.tab.h"
%}

%option yylineno

%%

[[:digit:]]* { yylval.entier = atoi(yytext); return S; }
"+" { return '+';}
"-" { return '-';}
"*" { return '*';}
"/" { return '/';}
"(" { return '(';}
")" { return ')';}
"<" { return '<';}
">" { return '>';}
"=" { return '=';}

\n { return '$'; }

%%