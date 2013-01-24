#ifndef _GAMEMODEL_
#define _GAMEMODEL_

#include "tile.h"

using namespace std;

class GameModel
{
	private:
///################ ATRIBUTS ####################
		int my_d, my_e, my_f;
		int my_w, my_h;
		std::vector<Tile> my_plateau;

	public:
///################ CONSTRUCTEURS & DESTRUCTEURS ####################
		GameModel();
		GameModel(const int &w, const int &h);
		~GameModel();

///################ ACTIONS SUR LE PLATEAU ####################
		void addTile(const int &i, const int &j);
		void delTile(const int &i, const int &j);
		void maxCoucheVoisins(const int &i, const int &j);
		int indiceAjout(const int &i, const int &j);
		void saveLevel(string name);
    	void loadLevel(string name);
		void clearPlateau();
		
///################ ACCESSEURS PLATEAU ####################
		std::vector<Tile>* getPlateau();
		int getNbTile() const;
		int getMaxEtage() const;
		int getD() const;
		int getE() const;
		int getF() const;

		void setD( const int a );
		void setE( const int a );
		void setF( const int a );
};

#endif


