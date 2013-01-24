
#ifndef GAMEMODEL_H
#define GAMEMODEL_H



#include <cstdlib>
#include <string>
#include <vector>

#include "GameSave.h"
#include "Button.h"
#include "Unite.h"
#include "GrilleCellule.h"
#include "GroupeVirus.h"
#include "enum.h"

using namespace std;

/** 
 * \class GameModel
 * \brief classe qui gère la partie model
*/
class GameModel
{	
	private:
		float _w;
		float _h;
		bool _stateGame, _clickL, _clickR;
		GrilleCellule * _gCellule;
		GroupeVirus * _gVirus;
		float _vitesseExe;
		GameSave * _save;
		Clock _timeVitesse;
			
	public:
	
/// ##################### CONSTRUCTEUR & DESTRUCTEUR ##################

		GameModel(const float & w, const float & h );
		~GameModel();
		
/// ##################### ACTION SUR LE JEU ###########################

		void nextStep();
		void play_pause(const bool & p);
		void virusVsCellule();
		void loadSave( const bool & b );
		void saveSave( const bool & b );
		
/// ##################### ACTION SUR CELLULES #########################	
		
		void add_column( const bool & add, Button* button);
		void add_line(const bool & add, Button* button);
		void remove_column(const bool & del, Button* button);
		void remove_line(const bool & del, Button* button);
		void alive_cellule( Event* event, const int & mx, const int & my );
		void dead_cellule( Event* event, const int & mx, const int & my );
		void update_all_Cellule(const bool & b);
		
/// ##################### ACTION SUR VIRUS ############################
		
		void add_virus ( const bool & add );
		void del_virus ( const bool & del );
		void removeAllVirus ( const bool & all );
		void updateVirus(const int & w, const int & h);
		void removeVirus( const int & i, const bool & d );
	
		
/// ##################### ACCESSEUR DU GROUPE VIRUS ####################

		int getSizeGroupeVirus() const;
		void getCoordonneVirus( const int & i, float & x, float & y, float & w, float & h ) const;
		void setNbEfantVirus( const int & e );
		void setDureVieVirus( const float & d );
		void setDureIncubVirus( const float & d );

/// ###################### ACCESSEUR DU GRILLE CELLULES ################		
		
		state getEtatCellule(const int & i, const int & j) const;
		health getSanteCellule(const int & i, const int & j) const;
		void getCoordonneCellule( const int & i, const int & j, Unite & e) const;
		void getSizePictureCellule( float & w, float & h ) const;
		void getTailleGrilleCellule( int & ti, int & tj ) const;
		void setMinAliveCellule( const int & a );
		void setMaxAliveCellule( const int & a );
		void setMinDeadCellule( const int & a );
		void setMaxDeadCellule( const int & a );
		void setAleaCelluleGrille( const float & a );
		void setAleaResistGrille( const float & a );
		
/// ###################### ACCESSEUR DU MODEL ##########################

		bool getStateGame() const;
		int getVitesse() const;
		void setW(const int & w );
		void setH(const int & h );
		void setVitesse( const int & v);
		
};

#endif // GAMEMODEL_H
