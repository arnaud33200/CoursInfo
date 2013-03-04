%{
	#include <stdio.h>
	extern int yylineno;
	int p, c, a, d;
%}

%token OPENP OPENC OPENA 
	CLOSEP CLOSEC CLOSEA
	IGN;

%start E

%%

E: OPENP { ++p; ++d; printf("%d ", d); } E CLOSEP { --p; --d; printf("%d ", d); } E
	| OPENA { ++a; ++d; printf("%d ", d); } E CLOSEA { --p; --d; printf("%d ", d); } E
	| OPENC { ++c; ++d; printf("%d ", d); } E CLOSEC { --p; --d; printf("%d ", d); } E
	| IGN E
	| 
	;

%%

int yyerror(char * s)
{
	fprintf(stderr, "ERROR : %d - %s\n",yylineno, s);
	exit(1);
}

int main()
{
	p = c = a = d = 0;
	yyparse();
	puts("SYNTHAXE CORRECT :)");
}