%{
	#include <stdlib.h>
	#include <unistd.h>

	int symbolAv;
	int lastNum;
	int resultat;

	int regle0(); int regle1(); int regle2(); int regle3(); int regle4(); int regle5(); int regle6(); int regle7(); int regle8();
 	int S(void); int E(void); int Ep(void); int T(void); int Tp(void); int F(void);
%}

%%

"$" { return '$'; }
"+" { return '+'; }
"(" { return '('; }
")" { return ')'; }
"*" { return '*'; }
[[:digit:]]+ { lastNum = atoi(yytext); return 'n'; }

%%

void syntaxErr()
{
	printf("%c : ERROR !!! \n", symbolAv);
	exit(1);
}

int consom(int c)
{
	if(c == symbolAv)
	{
		symbolAv = yylex();
		printf("symbole avancé : %c", symbolAv);
		if ( symbolAv == 'n')
			printf(" : %d", lastNum);
		printf("\n");
	}
	else
		syntaxErr();
}

int regle0()
{
	int n = E(); 
	consom('$');
	return n;
}

int regle1()
{
	int n = T();
	Ep();
	return n;
}

int regle2()
{
	int l = lastNum;
	consom('+');
	int n = T();
	Ep();
	printf("adition : %d + %d\n", l, lastNum);
	return (l+lastNum);
}

int regle3(){ return 0; }

int regle4()
{
	int n = F();
	Tp();
	return n;
}

int regle5()
{
	consom('n');
	return lastNum;
}

int regle6()
{
	consom('(');
	int n = E();
	consom(')');
	return n;
}

int regle7()
{
	int l = lastNum;
	consom('*');
	int n = F();
	Tp();
	return l*n;
}

int regle8(){ return 1; }

int S(void)
{
	switch(symbolAv)
	{
		case '(':
			return regle0();
			break;
		case 'n':
			return regle0();
			break;
		default:
			syntaxErr();
	}
}

int E(void)
{
	switch(symbolAv)
	{
		case '(':
			return regle1();
			break;
		case 'n':
			return regle1();
			break;
		default:
			syntaxErr();
	}
}

int Ep(void)
{
	switch(symbolAv)
	{
		case '$':
			return regle3();
			break;
		case '+':
			return regle2();
			break;
		case ')':
			return regle3();
			break;
		default:
			syntaxErr();
	}
}

int T(void)
{
	switch(symbolAv)
	{
		case '(':
			return regle4();
			break;
		case 'n':
			return regle4();
			break;
		default:
			syntaxErr();
	}
}

int Tp(void)
{
	switch(symbolAv)
	{
		case '$':
			return regle8();
			break;
		case '+':
			return regle8();
			break;
		case ')':
			return regle8();
			break;
		case '*':
			return regle7();
			break;
		default:
			syntaxErr();
	}
}

int F(void)
{
	switch(symbolAv)
	{
		case '(':
			return regle6();
			break;
		case 'n':
			return regle5();
			break;
		default:
			syntaxErr();
	}
}

int main()
{
	resultat = 0;
	symbolAv = yylex();
	printf("symbole avancé : %c\n", symbolAv);
	int resultat = S();
	printf("\nRESULTAT FINAL = %d\n", resultat);
}
