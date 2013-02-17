%{
	#include <stdlib.h>
	int symbolAv;
	void regle0(); void regle1(); void regle2(); void regle3(); void regle4(); void regle5(); void regle6(); void regle7(); void regle8();
 	int S(void); int E(void); int Ep(void); int T(void); int Tp(void); int F(void);
%}

%%

"$" { return '$'; }
"+" { return '+'; }
"(" { return '('; }
")" { return ')'; }
"*" { return '*'; }
[[:digit:]]+ { return 'n'; }

%%

void syntaxErr()
{
	printf("%c : ERROR !!! \n", symbolAv);
}

void consom(int c)
{
	if(c == symbolAv)
	{
		symbolAv = yylex();
		printf("symbole avancé : %c\n", symbolAv);
	}
	else
		syntaxErr();
}

void regle0()
{
	E(); 
	consom('$');
}

void regle1()
{
	T();
	Ep(); 
}

void regle2()
{
	consom('+');
	T();
	Ep();
}

void regle3()
{
}

void regle4()
{
	F();
	Tp();
}

void regle5()
{
	consom('n');
}

void regle6()
{
	consom('(');
	E();
	consom(')');
}

void regle7()
{
	consom('*');
	F();
	Tp();
}

void regle8()
{
}

int S(void)
{
	switch(symbolAv)
	{
		case '(':
		case 'n':
			regle0();
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
		case 'n':
			regle1();
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
			regle3();
			break;
		case '+':
			regle2();
			break;
		case ')':
			regle3();
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
			regle4();
			break;
		case 'n':
			regle4();
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
			regle8();
			break;
		case '+':
			regle8();
			break;
		case ')':
			regle8();
			break;
		case '*':
			regle7();
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
			regle6();
			break;
		case 'n':
			regle5();
			break;
		default:
			syntaxErr();
	}
}

int main()
{
	symbolAv = yylex();
	printf("symbole avancé : %c\n", symbolAv);
	S();
}
