%x PAR

%option yylineno

%{
	int cpt;
%}
	
%%

"(" { BEGIN(PAR); }
<PAR>
{
	"(" { ++cpt; }
	")" { BEGIN(INITIAL); printf("\n"); if( cpt>0 ) printf("  ERROR PARENTHEZE LINE %i ", yylineno); cpt=0; }
	[.\)] {  }
}

")" { --cpt; if( cpt<0 ) printf("  ERROR PARENTHEZE LINE %i ", yylineno); }

. {  }
\n { }

<<EOF>> { if( cpt>0 ) printf("  ERROR PARENTHEZE LINE %i ", yylineno); return 0; }
