#ifndef ENUM_H
#define ENUM_H

/**
 * \file enum.h
 * \brief énumérations
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include <string>

using namespace std;

/******************************************************/
///         DEFINIT L'ETAT D'UNE CELLULE
/******************************************************/

/**
 * \enum state
 * \brief Etat Cellule.
 *
 * state definit les trois etats possibles d'une cellule.
 * De plus chaque etat est associé à un entier.
 */
enum state { alive=1, dead=0, infest=-1 };

/******************************************************/
///		DEFINIT LA RESISTANCE D'UNE CELLULE
/******************************************************/

/**
 * \enum health
 * \brief sante Cellule.
 *
 * health definit si une cellule est resistante au attaque des virus
 * ou si il s'agit d'une cellule normale. 
 * health est aussi associé à un entier.
 */
enum health { resist=1, normal=0 };


/******************************************************/
/// 	DEFINIT LES ONGLETS DE LA FENETRE PARAMETRE
/******************************************************/

/**
 * \enum tab
 * \brief Onglet du Menu.
 *
 * tab definit si l'onglet présent dans MenuView concerne les cellules
 * ou concerne les virus;
 */
enum tab { cellule, virus };


/******************************************************/
///         ACCESSEURS SUR LES ENUMS
/******************************************************/

state getState( const int & n );
health getHealth( const int & n );

#endif
