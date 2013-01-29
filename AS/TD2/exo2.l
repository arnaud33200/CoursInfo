%x CHAR

ALL (.|\n)

%%

\" { BEGIN(CHAR); }
<CHAR>
{
	\" { BEGIN(INITIAL); printf("\n"); }
	[\.] { printf(yytext); }
	. { ECHO; }
}

{ALL} {}
