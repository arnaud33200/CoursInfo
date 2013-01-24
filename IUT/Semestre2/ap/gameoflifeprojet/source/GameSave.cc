/**
 * \file GameSave.cc
 * \brief gestion de sauvegarde
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */


#include <fstream>
#include <iostream>

#include "GameSave.h"

using namespace std;

GameSave::GameSave()
{ }

 GameSave::~GameSave()
{ }

/**
 * \fn GameSave::open(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, bool & s)
 * \brief ouvre une sauvegarde
 * \param grille GrilleCellule à modifier
 * \param groupe GroupeVirus à modifier
 * \param s booléen definissant l'etat du jeu a modifier
 * \return rien
 */
void GameSave::open(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, bool & s )
{
	fstream f;
	f.open( nom_sauvegarde.data(), ios::in );
	
	grille->lireGrilleCellule(f);
	groupe->lireGroupeVirus(f);
	f >> s;
}

/**
 * \fn GameSave::save(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, const bool & s)
 * \brief sauvegarde le jeu en cours
 * \param grille GrilleCellule à enregistrer
 * \param groupe GroupeVirus à enregistrer
 * \param s booléen definissant l'etat du jeu à enregistrer
 * \return rien
 */
void GameSave::save(string nom_sauvegarde, GrilleCellule* grille, GroupeVirus* groupe, const bool & s)
{
	fstream f;
	f.open( nom_sauvegarde.data(), ios::out );
	
	grille->ecrireGrilleCellule(f);
	groupe->ecrireGroupeVirus(f);
	f << s << endl;
	
	f.close();
}
