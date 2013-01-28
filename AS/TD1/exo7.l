%{
	int cptword;
	int cptline;
	int cptchar;
%}

%%

\n { ECHO; cptline++; }
. {ECHO; cptchar++; }
[ |\t]*./[ |\t|\n]+ { ECHO; cptword++; }

<<EOF>> { 
			printf("\n\n - LINE : %i\n", cptline); 
			printf(" - CHAR : %i\n", cptchar); 
			printf(" - WORD : %i\n", cptword); 
			return 0; 
		}

