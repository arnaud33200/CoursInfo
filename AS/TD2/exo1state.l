%x COM1
%x COM2
%x CHAR

%{
	int nbcomline;
%}

ALL (.|\n)

%%

\" { BEGIN(CHAR); printf("\n~~~~~~~~~~~\n- CHAINE : ");}
<CHAR>
{
	\" { BEGIN(INITIAL); printf("\n"); }
	[^"] { ECHO; }
}

<COM1><COM2>\n { nbcomline++; }

"/*" { BEGIN(COM1); printf("- COM1 : ");  }
<COM1>
{
	"*/" { BEGIN(INITIAL); printf("\n"); nbcomline++; }
	 . { printf("%s", yytext); }
}

"//" { BEGIN(COM2); printf("- COM2 : "); }
<COM2>
{
	\n { BEGIN(INITIAL); printf("\n"); nbcomline++; }
	.* { printf("%s", yytext); }
}

{ALL} {}
<<EOF>> { printf("\n\nLIGNE DE COM : %i\n", nbcomline); return 0; }
