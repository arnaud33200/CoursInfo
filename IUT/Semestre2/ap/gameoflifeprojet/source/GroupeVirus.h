#ifndef GROUPEVIRUS_H
#define GROUPEVIRUS_H

/**
 * \file GroupeVirus.h
 * \brief regroupement de Virus
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <string>
#include <vector>
#include <fstream>

#include "Virus.h"

using namespace std;

/** 
 * \class GroupeVirus
 * \brief classe qui regroupe tous les Virus
*/
class GroupeVirus
{
	private:
		float _wVirus;
		float _hVirus;
		int _nbEnfant;
		float _dureVie, _dureIncub;
		vector<Virus> _groupeVirus;
		
	public:
	
/// ###################### CONSTRUCTOR & DESTRUCTOR ####################

		GroupeVirus(const int & enfant, const float & vie, const int & incub );
		~GroupeVirus ( );
		
/// ###################### MODIFICATION GROUPE VIRUS ####################
		
		void removeVirus ( );
		void addVirus ( );
		void removeAll();
		void moveVirus();
		void delVirus( const int & i );
		void updateVirus(const float & w, const float & h, const int & ti, const int & tj);
		
/// ###################### ACTION TIMES VIRUS ####################
		
		void lifeTimeVirus(const bool & g);
		void incubTimeVirus(const bool & g, const int & i );
		
/// ###################### ACCESSEURS VIRUS ####################
		
		int getSizeGroupe() const;
		int getDureeInc() const;
		bool getTargetVirus( const int & i) const;
		void getCoordonne( const int & i, float & x, float & y, float & w, float & h ) const;
		
		void setCoordonneVirus( const int & i, const float & x, const float & y );
		void setTargetVirus( const int & i, const bool & t );
		void setResetIncubVirus( const int & i );
		void setNbEfant( const int & e );
		void setDureVie( const float & d );
		void setDureIncub( const float & d );
		
/// ###################### ACCESSEURS VIRUS ####################
		
		void lireGroupeVirus( fstream & f );
		void ecrireGroupeVirus( fstream & f );
		
		
};

#endif // GROUPEVIRUS_H
