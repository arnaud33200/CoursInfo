%x CHAR

ALL (.|\n)

%%


\" { BEGIN(CHAR); printf("[beggin char]\n"); }
<CHAR>
{
	\\. { printf("%c", yytext[1]); }
	\" { BEGIN(INITIAL);printf("\n[end char]\n\n"); }
	\\ { printf("["); ECHO; printf("]"); }
	. { ECHO; }
	[\n] { printf (" /!\\ ERROR \\n /!\\ "); }
	
}

{ALL} {}
