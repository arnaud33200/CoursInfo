#ifndef GRILLECELLULE_H
#define GRILLECELLULE_H

/**
 * \file GrilleCellule.h
 * \brief regroupement de Cellule
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <vector>
#include <string>
#include <fstream>

#include "Cellule.h"
#include "Unite.h"
#include "enum.h"

using namespace std;

/** 
 * \class GrilleCellule
 * \brief classe qui regroupe tous les Cellules
*/
class GrilleCellule
{
	private:
		vector< vector<Cellule> > _grilleCellule;
		
		int _min_alive, _max_alive;
		int _min_dead, _max_dead;
		float _wC, _hC;
		float _aleaCellule, _aleaResist, _tmpAleaCellule, _tmpAleaResist;
		
	public:
	
/// ###################### CONSTRUCTOR & DESTRUCTOR ####################

		GrilleCellule( const int & mia, const int & maa, const int & mid, const int & mad );
		~GrilleCellule( );
		
/// ###################### MODIFICATION MATRICE CELLULE ################

		void add_column (const float & w, const float & h );
		void add_line (const float & w, const float & h );
		bool remove_column (const float & w, const float & h );
		bool remove_line (const float & w, const float & h );
		void updateAll();
		
/// ###################### VIE DES CELLULES ############################
		
		void update(const float & w, const float & h);
		void loi_de_vie ( );
		int nb_cellule_voisine(const int & a, const int & b );
		
/// ###################### ACCESSEUR GRILLE CELLULES ####################
		
		void getCoordonne( const int & i, const int & j, Unite & e) const;
		void getSizePicture( float & w, float & h) const;
		state getEtatCellule(const int & i, const int & j) const;
		health getHealthCellule( const int & i, const int & j) const;
		void getTailleGrille( int & ti, int & tj ) const;
		
		void setEtatCellule( const int & i, const int & j, const state & e);
		void setMinAlive( const int & a );
		void setMaxAlive( const int & a );
		void setMinDead( const int & a );
		void setMaxDead( const int & a );
		void setAleaCellule( const float & a);
		void setAleaResist(const float & a);
		
/// #################### FLUX GRILLE CELLULE #####################

		void lireGrilleCellule( fstream & f );
		void ecrireGrilleCellule( fstream & f );
};

#endif // GRILLECELLULE_H
