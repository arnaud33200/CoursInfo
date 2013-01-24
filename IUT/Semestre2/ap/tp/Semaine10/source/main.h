#ifndef _MAIN_H_
#define _MAIN_H_

#include <string>

//- Affiche le message [msg] sur la sortie standard et force l'arret du programme.
//- @param msg le message a afficher.
void erreur( const string & msg );

//- @return 'true' si l'expression [expr] est un operateur: /+-*
bool estUnOperateur( const string & expr );

//- @return 'true' si l'expression [expr] est un nombre flottant.
bool estUnNombre( const string & expr );

//- @return la valeur de l'expression numerique [expr_num].
//- NB: vous devez verifier avant avec la fonction 'estUnNombre' si vous
//- manipuler bien une expression numerique.
float valeur( const string & expr_num );

//- Retourne la priorite d'un operateur. Plus le nombre retourne est grand, 
//- plus l'operateur est prioritaire.
//- @param op un operateur.
//- @return la priorite de l'operateur [op].
int priorite( char op );

//- Programme principal.
int main();

// ----------------------------------------------------------------------------
//- Exercice 1.
//- Objectif: Evaluer l'expression postfixee [expression].
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalExprPost( string expression );

//- Effectue l'operation [op] avec comme operande gauche [valg] et operande
//- droite [vald], puis retourne le resultat.
//- @param valg l'operande gauche.
//- @param op l'operateur ( '+', '-', '*', ou '/' ).
//- @param vald l'operande droite.
float oper2( float valg, char op, float vald );

// ----------------------------------------------------------------------------
//- Exercice 2.
//- Objectif: identique a l'exercice 1, sauf qu'il est demande de verifier 
//- l'integrite de l'expression [expression] donnee en entree.
//- Vous testerez entre autres que l'expression contient le bon nombre d'operateurs
//- pour le nombre d'operandes (et vice-versa). Vous pourrez aussi tester que
//- l'expression ne contient pas de symboles inconnus.
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalSecuriseeExprPost( string expression );

// ----------------------------------------------------------------------------
//- Exercice 3.
//- Objectif: transformer l'expression infixee [expression] en une expression 
//- postfixee. Dans cet exercice, [expression] ne contient pas de parentheses.
//- @param expression une expression infixee.
//- @return l'expression postfixee correspondante.
string exprInfVersExprPost( string expression );

// ----------------------------------------------------------------------------
//- Exercice 4.
//- Objectif: transformer l'expression infixee [expression] en une expression 
//- postfixee. Dans cet exercice, [expression] peut contenir des parentheses.
//- @param expression une expression infixee.
//- @return l'expression postfixee correspondante.
string exprInfVersExprPost2( string expression );


#endif // #ifndef _MAIN_H_

