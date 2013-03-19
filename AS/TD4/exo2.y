%{
	#include <stdio.h>
	#include <unistd.h>

	extern int yylineno;

	/*struct opTest
	{
		int left;
		char * op;
		int right;
		int result;
	};*/
%}

%union
{
	int entier;
	/*struct opTest bool;*/
	int bool;
}

%token <entier>S;
%left '-' '+' '*' '/' ;
%right '<' '>' '=' ;
%type <entier>C
%type <bool>T

%%

B : C { printf("%d : Resultat = %d\n", yylineno, $1 ); } '$' B
	| C { printf("%d : Resultat = %d\n", yylineno, $1 ); }
	| T '$' B
	| T
	|
	;

/* Operation de Test */
T : C '<' C { $$ = $1 < $3; 
		printf("%d : Test %s : %d %s %d\n", yylineno, ($$? "true" : "false"), $1, "<", $3 );}
	| C '>' C { $$ = $1 > $3; 
		printf("%d : Test %s : %d %s %d\n", yylineno, ($$? "true" : "false"), $1, ">", $3 );}
	| C '=' C { $$ = $1 == $3; 
		printf("%d : Test %s : %d %s %d\n", yylineno, ($$? "true" : "false"), $1, "=", $3 );}
	| C '<' '=' C { $$ = $1 <= $4;
		printf("%d : Test %s : %d %s %d\n", yylineno, ($$? "true" : "false"), $1, "<=", $4 );}
	| C '>' '=' C { $$ = $1 >= $4;
		 printf("%d : Test %s : %d %s %d\n", yylineno, ($$? "true" : "false"), $1, ">=", $4 );}
	;

/* Operation de Calcul */
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
	yyparse();
	printf("\nSynthaxe Correcte :D\n");
	return 0;
}