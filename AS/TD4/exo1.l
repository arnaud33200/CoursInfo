%{
	#include "exo1.tab.h"
%}

%x COM
%x TEXT

%option yylineno

%%

"(" { return OPENP; }
"[" { return OPENC; }
"{" { return OPENA; }

")" { return CLOSEP; }
"]" { return CLOSEC; }
"}" { return CLOSEA; }

\" {BEGIN(TEXT);}
<TEXT>
{
	\" { BEGIN(INITIAL); }
	. { return IGN; }
}

"\*" {BEGIN(COM);}
<COM>
{
	"*/" { BEGIN(INITIAL); }
	. { return IGN; }
}

.|\n { return IGN; }

%%