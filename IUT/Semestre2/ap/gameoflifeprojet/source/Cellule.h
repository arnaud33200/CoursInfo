#ifndef CELLULE_H
#define CELLULE_H

/**
 * \file Cellule.h
 * \brief Cellule du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include "Unite.h"
#include "enum.h"

/** 
 * \class Cellule
 * \brief classe qui gère une cellule
*/
class Cellule : public Unite
{	
	private:
		state _etatCellule;
		health _santeCellule;
		
	public:
	
/// ####################### CONSTRUCTEUR DESTRUCTEUR ###################

		Cellule( const int & x, const int & y, const float & aleac, const float & alear );
		Cellule( const int & x, const int & y, const state & e, const health & s );
		~Cellule();
		
/// ####################### ACCESSEURS #################################
		
		state getEtat() const;
		health getSante() const;
		void setEtat( const state & e );
		void setSante( const health & h );
		
		
};

#endif // CELLULE_H
