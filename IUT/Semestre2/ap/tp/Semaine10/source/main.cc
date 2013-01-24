///////////////////////////////////////////////////////////////////////////////
// main.cc
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <string>
#include "Pile.h"
#include "token.h"
#include "main.h"

using namespace std;

// ----------------------------------------------------------------------------
// Quelques fonctions utiles.


//- Affiche le message [msg] sur la sortie standard et force l'arret du programme.
//- @param msg le message a afficher.
void erreur( const string & msg )
{
  cout << msg << endl;
  exit(1);
}

//- @return 'true' si l'expression [expr] est un operateur: /+-*
bool estUnOperateur( const string & expr )
{
  bool op = false;
  switch ( expr[ 0 ] ) // teste juste le premier caractere.
    {
    case '*': 
    case '/':
    case '+':
    case '-':
      op = true;
    }
  return op;
}

//- @return 'true' si l'expression [expr] est un nombre flottant.
bool estUnNombre( const string & expr )
{
  return isdigit( expr[ 0 ] ); // teste juste le premier caractere.
}

//- @return la valeur de l'expression numerique [expr_num].
//- NB: vous devez verifier avant avec la fonction 'estUnNombre' si vous
//- manipulez bien une expression numerique.
float valeur( const string & expr_num )
{
  return atof( expr_num.c_str() );
}

//- Retourne la priorite d'un operateur. Plus le nombre retourne est grand, 
//- plus l'operateur est prioritaire.
//- @param op un operateur.
//- @return la priorite de l'operateur [op].
int priorite( char op )
{
  int prio = 0;
  switch ( op )
    {
    case '*': 
    case '/':
      prio = 2;
      break;
    case '+':
    case '-':
      prio = 1;
    }
  return prio;
}

// ----------------------------------------------------------------------------
//- Exemple.
//- Decompose l'expression [expr_complete] en nombres, operateurs, et autres
//- (genre parentheses).
//- @param expr_complete une expression arithmetique.
void analyseExpr( string expr_complete )
{
  int indice = 0;
  string expr;
  
  // Prend la premiere expression.
  // NB: indice est incremente dans 'nextArg'.
  expr = nextArg( expr_complete, indice );
  while ( expr != "" )
  {
    if ( estUnNombre( expr ) )
      cout << "nombre : " << valeur( expr ) << endl;
    else if ( estUnOperateur( expr ) )
      cout << "operateur : " << expr << endl;
    else
      cout << "autres : " << expr << endl;

    // Prend l'expression suivante.
    // NB: indice est incremente dans 'nextArg'.
    expr = nextArg( expr_complete, indice );
  }
}


// ----------------------------------------------------------------------------
//- Exercice 1.
//- Objectif: Evaluer l'expression postfixee [expression].
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalExprPost( string expression )
{
	int i=0;
	Pile< float > p;
	char op;
	float valD, valG, r;
	
	while ( i < expression.length() )
	{
		if ( estUnNombre(&expression[i]) )
		{
			p.empiler( valeur(&expression[i]) );
		}
		
		else if ( estUnOperateur(&expression[i]) )
		{
			op = expression[i];
			valD = p.valeurSommet();
			p.depiler();
			valG = p.valeurSommet();
			p.depiler();
			p.empiler( oper2(valD, op, valG) );
		}
		i++;
	}
	return p.valeurSommet();
}

//- Effectue l'operation [op] avec comme operande gauche [valg] et operande
//- droite [vald], puis retourne le resultat.
//- @param valg l'operande gauche.
//- @param op l'operateur ( '+', '-', '*', ou '/' ).
//- @param vald l'operande droite.
float oper2( float valg, char op, float vald )
{
	if ( &op == "+" ) return valg + vald;
	if ( &op == "-" ) return valg - vald;
	if ( &op == "*" ) return valg * vald;
	if ( &op == "/" ) return valg / vald;
	else cout << "operateur inconnue !" << endl;
}

// ----------------------------------------------------------------------------
//- Exercice 2.
//- Objectif: identique a l'exercice 1, sauf qu'il est demande de verifier 
//- l'integrite de l'expression [expression] donnee en entree.
//- Vous testerez entre autres que l'expression contient le bon nombre d'operateurs
//- pour le nombre d'operandes (et vice-versa). Vous pourrez aussi tester que
//- l'expression ne contient pas de symboles inconnus.
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalSecuriseeExprPost( string expression )
{
	int i=0;
	int cpt_ex = 0, cpt_op = 0;
	bool bon = true;
	
	while ( i < expression.length() && bon )
	{
		if ( estUnNombre(&expression[i]) ) cpt_ex++;
		else if ( estUnOperateur(&expression[i]) ) cpt_op++;
		else bon = false; // si il y a un element inconnue
		i++;
	}
	if ( bon && cpt_ex == cpt_op + 1 )	evalExprPost( expression );
	 
}

// ----------------------------------------------------------------------------
//- Exercice 3.
//- Objectif: transformer l'expression infixee [expression] en une expression 
//- postfixee. Dans cet exercice, [expression] ne contient pas de parentheses.
//- @param expression une expression infixee.
//- @return l'expression postfixee correspondante.
string exprInfVersExprPost( string expression )
{
	int i = 2;
	string post;
	
	post += expression[0];
	while ( i < expression.length() )
	{
		post += expression[i-1];
		post += expression[i];
		i += 2;
	}
	
	return post;
}

// ----------------------------------------------------------------------------
//- Exercice 4.
//- Objectif: transformer l'expression infixee [expression] en une expression 
//- postfixee. Dans cet exercice, [expression] peut contenir des parentheses.
//- @param expression une expression infixee.
//- @return l'expression postfixee correspondante.
string exprInfVersExprPost2( string expression )
{
	int i = 0;
	string tmp_op = "n";
	string post;
	
	while ( i < expression.length() )
	{
		if( &expression[i] == "(" ) 
		{
			i++;
		}
		else if( estUnNombre(&expression[i]) && estUnNombre(&expression[i+2]) )
		{
			post += &expression[i];
			post += &expression[i+2];
			post += &expression[i+1];
			i += 3;
		}
		else if( &expression[i] == ")" )
		{
			if( estUnOperateur( tmp_op) ) 
			{
				post += tmp_op;
				tmp_op = "n";
			}
			i++;
		}
		else if( estUnOperateur(&expression[i]) )
		{
			if( estUnNombre(&expression[i+1]) )
			{
				post += &expression[i+1];
				post += &expression[i];
			}
			else tmp_op = &expression[i];
			i += 2;
		}
	}
}

//- Programme principal.
int main()
{
  string expression;
  
  // Demande a l'utilisateur d'entrer une expression sur une ligne.
  getline( cin, expression );
  
  cout << "expression : " << expression << endl;
 
 // Decompose l'expression.
  //~ analyseExpr( expression );

  // Evaluation, ... => A faire.
   cout << evalSecuriseeExprPost( expression ) << endl;

  return 0;
}
