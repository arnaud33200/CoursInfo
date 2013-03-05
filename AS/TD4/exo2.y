%{
	#include <stdio.h>
	extern int yylineno;
	int cpt;
%}

%union
{
	int entier;
}

%token <entier>S;
%left '-' '+' '*' '/' ;
%type <entier>C

%%

B : C { printf("Resultat%d = %d\n", cpt, $1 ); cpt++; } '$' B
B : C { printf("Resultat%d = %d\n", cpt, $1 ); cpt++; }
	|
	;

C : C '+' C 	{ $$ = $1 + $3; }
	| C '-' C 	{ $$ = $1 - $3; }
	| C '*' C 	{ $$ = $1 * $3; }
	| C '/' C 	{ $$ = $1 / $3; }
	| '(' C ')'	{ $$ = $2; }
	| S { $$ = $1; }
	;

%%

int yyerror( char * s)
{
	printf("Erreur de synthaxe : %s\n", s);
	exit(1);
}

int main(int argc, char const *argv[])
{
	cpt = 1;
	yyparse();
	printf("\nSynthaxe Correcte :D\n");
	return 0;
}