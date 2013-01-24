#ifndef GAMESAVE_H
#define GAMESAVE_H

/**
 * \file GameSave.h
 * \brief gestion de sauvegarde
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <string>

#include "GrilleCellule.h"
#include "GroupeVirus.h"

using namespace std;

/** 
 * \class GameSave
 * \brief classe qui sauvegarde une partie
*/
class GameSave
{
	private:
		int _numSave;
		
	public:
		GameSave ( );
		~GameSave ( );
		
		void open(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, bool & s );
		void save(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, const bool & s );
};

#endif // GAMESAVE_H
