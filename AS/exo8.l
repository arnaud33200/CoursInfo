%{
	int mois, jours, annee;
%}
%%

 /*[[:digit:]]{4}"-"[[:digit:]]{2}"-"[[:digit:]]+/[ |\n|\t]+ 
	{
		printf("%c%c/%c%c/%c%c%c%c", yytext[8], yytext[9], 
									yytext[5], yytext[6],
									yytext[0], yytext[1], yytext[2],  yytext[3]); 
	}*/

 /*[[:digit:]]{2}"/"[[:digit:]]{2}"/"[[:digit:]]+/[ |\n|\t]+ 
	{
		printf("%c%c%c%c-%c%c-%c%c", yytext[6], yytext[7], yytext[8], yytext[9],
									yytext[3], yytext[4], 
									yytext[0],  yytext[1]); 
	}*/

[[:digit:]]{4}/"-" { annee = atoi(yytext); }
"-"[[:digit:]]{2}/"-" { mois = atoi(yytext); }
"-"[[:digit:]]{2}/"-"/[ |\n|\t]+  
	{ 
		jours = atoi(yytext); 
		printf("%i/%i/%i", jours, mois, annee);
	}


				
