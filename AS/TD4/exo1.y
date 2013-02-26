%{
	#include <stdio.h>
	extern int yylineno;
	int p, c, a;
%}

%token OPENP OPENC OPENA 
	CLOSEP CLOSEC CLOSEA
	IGN;

%start E

%%

E: OPENP { ++p; printf("P%d -", p); } E CLOSEP { --p; printf("P%d -", p); } E
	| OPENA { ++a; printf("A%d -", a); } E CLOSEA { --p; printf("A%d -", a); } E
	| OPENC { ++c; printf("C%d -", c); } E CLOSEC { --p; printf("C%d -", c); } E
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
	p = c = a = 0;
	yyparse();
	puts("SYNTHAXE CORRECT :)");
}