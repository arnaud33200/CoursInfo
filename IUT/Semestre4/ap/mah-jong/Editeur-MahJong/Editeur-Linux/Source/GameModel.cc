#include "GameModel.h"

using namespace std;

int maxCouche = -1;
int indiceMaxCouche = 0;
bool libre = true;
int tabMaxCouche[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

/*#############################################################################
/#                                                                            #
/#            STRUCTURE POUR DEFINIR UN TRI                                   #
/#                                                                            #
##############################################################################*/

struct TriX
{
   inline bool operator() (const Tile & tile1, const Tile & tile2) const
   {return tile1.getXTile() < tile2.getXTile();}
};

struct TriY
{
   inline bool operator() (const Tile & tile1, const Tile & tile2) const
   { return tile1.getYTile() < tile2.getYTile(); }
};

struct TriZ
{
   inline bool operator() (const Tile & tile1, const Tile & tile2) const
   {
      return tile1.getZTile() < tile2.getZTile();
   }
};

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

GameModel::GameModel(const int &w, const int &h)
: my_d(2), my_e(2), my_f(2)
{
    my_w = w;
    my_h = h;
}

GameModel::~GameModel()
{

}

/*#############################################################################
/#                                                                            #
/#            ACTIONS SUR PLATEAU                                             #
/#                                                                            #
##############################################################################*/

// ~~~~~~~~~~~~~~~~~~~~~ AJOUT D'UNE TUILE ~~~~~~~~~~~~~~~~~~~~~~~~~~

void GameModel::addTile(const int &i, const int &j)
{
    maxCoucheVoisins(i, j);
    int indice_ajout = indiceAjout(i, j);

    if(my_plateau.size() == 0)
    {
        my_plateau.push_back(Tile(i, j, 0));
    }
    else
    {
        if(indice_ajout+1 < NB_COUCHE_MAX)
        {
			if(indice_ajout > -2)
				my_plateau.push_back(Tile(i, j, indice_ajout+1));
        }
    }

    std::sort (my_plateau.begin(), my_plateau.end(), TriZ());
}

// ~~~~~~~~~~~~~~~~~~~~~ SUPPRESSION D'UNE TUILE ~~~~~~~~~~~~~~~~~~~~~~~~~~

void GameModel::delTile(const int &i, const int &j)
{
    maxCoucheVoisins(i, j);

	if(maxCouche > -1)
		if(libre)
			my_plateau.erase(my_plateau.begin() + indiceMaxCouche);
}

// ~~~~~~~~~~~~~~~~~~~~~ MAX COUCHE VOISIN ~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~ on 

void GameModel::maxCoucheVoisins(const int &i, const int &j)
{
	libre = true;
    maxCouche = -1;

	for(int k=0 ; k<8 ; k++)
		tabMaxCouche[k] = -1;

    for(unsigned int k=0 ; k < my_plateau.size() ; k++)
    {
        if(my_plateau[k].getXTile() == i && my_plateau[k].getYTile() == j)
        {
            if(my_plateau[k].getZTile() > maxCouche)
            {
                maxCouche = my_plateau[k].getZTile();
                indiceMaxCouche = k;
			}
        }

        else if(my_plateau[k].getXTile() == i-1 && my_plateau[k].getYTile() == j)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[0])
                tabMaxCouche[0] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i+1 && my_plateau[k].getYTile() == j)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[1])
                tabMaxCouche[1] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i && my_plateau[k].getYTile() == j-1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[2])
                tabMaxCouche[2] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i && my_plateau[k].getYTile() == j+1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[3])
                tabMaxCouche[3] = my_plateau[k].getZTile();
        }


        else if(my_plateau[k].getXTile() == i-1 && my_plateau[k].getYTile() == j-1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[4])
                tabMaxCouche[4] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i-1 && my_plateau[k].getYTile() == j+1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[5])
                tabMaxCouche[5] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i+1 && my_plateau[k].getYTile() == j-1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[6])
                tabMaxCouche[6] = my_plateau[k].getZTile();
        }

        else if(my_plateau[k].getXTile() == i+1 && my_plateau[k].getYTile() == j+1)
        {
            if(my_plateau[k].getZTile() > tabMaxCouche[7])
                tabMaxCouche[7] = my_plateau[k].getZTile();
        }
    }

	for(int l=0 ; l<8 ; l++)
		if(tabMaxCouche[l] != -1)
			if(tabMaxCouche[l] > maxCouche)
				libre = false;
}



int GameModel::indiceAjout(const int &i, const int &j)
{
    if(libre)
		return maxCouche;

	if(tabMaxCouche[0] == tabMaxCouche[1] && maxCouche <= tabMaxCouche[0] && tabMaxCouche[0] > -1 &&
       tabMaxCouche[0] > tabMaxCouche[2] && tabMaxCouche[0] > tabMaxCouche[3] && tabMaxCouche[0] > tabMaxCouche[4] &&
       tabMaxCouche[0] > tabMaxCouche[5] && tabMaxCouche[0] > tabMaxCouche[6] && tabMaxCouche[0] > tabMaxCouche[7])
	{
			return tabMaxCouche[0];
	}

	else if(tabMaxCouche[2] == tabMaxCouche[3] && maxCouche <= tabMaxCouche[2] && tabMaxCouche[2] > -1 &&
            tabMaxCouche[2] > tabMaxCouche[0] && tabMaxCouche[2] > tabMaxCouche[1] && tabMaxCouche[2] > tabMaxCouche[4] &&
		    tabMaxCouche[2] > tabMaxCouche[5] && tabMaxCouche[2] > tabMaxCouche[6] && tabMaxCouche[2] > tabMaxCouche[7])
	{
			return tabMaxCouche[2];
	}

	else if(tabMaxCouche[4] == tabMaxCouche[5] && tabMaxCouche[4] == tabMaxCouche[6] && tabMaxCouche[4] == tabMaxCouche[7] && maxCouche <= tabMaxCouche[4] && tabMaxCouche[4] > -1 &&
            tabMaxCouche[4] > tabMaxCouche[0] && tabMaxCouche[4] > tabMaxCouche[1] && tabMaxCouche[4] > tabMaxCouche[2] && tabMaxCouche[4] > tabMaxCouche[3])
	{
			return tabMaxCouche[4];
	}

	else if(tabMaxCouche[0] == tabMaxCouche[6] && tabMaxCouche[0] == tabMaxCouche[7] && maxCouche <= tabMaxCouche[0] && tabMaxCouche[0] > -1 &&
            tabMaxCouche[0] > tabMaxCouche[1] && tabMaxCouche[0] > tabMaxCouche[2] && tabMaxCouche[0] > tabMaxCouche[3] &&
		    tabMaxCouche[0] > tabMaxCouche[4] && tabMaxCouche[0] > tabMaxCouche[5])
	{
			return tabMaxCouche[0];
	}

	else if(tabMaxCouche[1] == tabMaxCouche[4] && tabMaxCouche[1] == tabMaxCouche[5] && maxCouche <= tabMaxCouche[1] && tabMaxCouche[1] > -1 &&
            tabMaxCouche[1] > tabMaxCouche[0] && tabMaxCouche[1] > tabMaxCouche[2] && tabMaxCouche[1] > tabMaxCouche[3] &&
		    tabMaxCouche[1] > tabMaxCouche[6] && tabMaxCouche[1] > tabMaxCouche[7])
	{
			return tabMaxCouche[1];
	}

	else if(tabMaxCouche[3] == tabMaxCouche[4] && tabMaxCouche[3] == tabMaxCouche[6] && tabMaxCouche[3] > -1 &&
            tabMaxCouche[3] > tabMaxCouche[0] && tabMaxCouche[3] > tabMaxCouche[1] && tabMaxCouche[3] > tabMaxCouche[2] &&
		    tabMaxCouche[3] > tabMaxCouche[5] && tabMaxCouche[3] > tabMaxCouche[7])
	{
			return tabMaxCouche[3];
	}

	else if(tabMaxCouche[2] == tabMaxCouche[5] && tabMaxCouche[2] == tabMaxCouche[7] && tabMaxCouche[2] > -1 &&
            tabMaxCouche[2] > tabMaxCouche[0] && tabMaxCouche[2] > tabMaxCouche[1] && tabMaxCouche[2] > tabMaxCouche[3] &&
		    tabMaxCouche[2] > tabMaxCouche[4] && tabMaxCouche[2] > tabMaxCouche[6])
	{
			return tabMaxCouche[2];
	}


	return -2;
}

// ~~~~~~~~~~~~~~~~ ENREGISTRER UN PLATEAU ~~~~~~~~~~~~~~~~~~~~~~~~

void GameModel::saveLevel(string name)
{
	fstream fichier;
	fichier.open(name.c_str(), fstream::out);
	if( fichier.is_open() )
	{
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriY());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriZ());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriX());

		fichier << my_d << " " << my_e << " " <<  my_f << endl << endl;
		for( unsigned int i=0; i< my_plateau.size(); i++)
		{
			fichier << my_plateau[i].getXTile() << " " << my_plateau[i].getYTile() << " " << my_plateau[i].getZTile() << endl;
		}
		fichier << "-1" << endl;

		fichier.close();
		cout << "Sauvegarde du plateau dans : " << name << endl;

		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriX());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriY());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriZ());
	}
	else
		cout << "Impossible de sauvegarder dans : " << name << endl;
}

// ~~~~~~~~~~~~~~~~ CHARGER UN PLATEAU ~~~~~~~~~~~~~~~~~~~~~~~~

void GameModel::loadLevel(string name)
{
	int x, y, z;
	fstream fichier;
    fichier.open(name.c_str(), fstream::in);
    if( fichier.is_open() )
	{
		fichier >> my_d >> my_e >> my_f;

		my_plateau.clear();
		fichier >> x >> y >> z;
		while ( x != -1 )
		{
			my_plateau.push_back(Tile(x,y,z));
			fichier >> x >> y >> z;
		}

		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriX());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriY());
		std::stable_sort (my_plateau.begin(), my_plateau.end(), TriZ());

		fichier.close();
		cout << "chargement plateau du plateau dans : " << name << endl;
	}
	else
		cout << "impossible de charger : " << name << endl;
}

void GameModel::clearPlateau()
{
	my_plateau.clear();
}

/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/


std::vector<Tile>* GameModel::getPlateau()
{
    return &my_plateau;
}

int GameModel::getNbTile() const
{
	return my_plateau.size();
}

int GameModel::getMaxEtage() const
{
	int max=0;
	for( unsigned int i=0; i< my_plateau.size(); i++)
		if ( my_plateau[i].getZTile() > max )
			max = my_plateau[i].getZTile();
	return max;
}

int GameModel::getD() const
{ return my_d; }

int GameModel::getE() const
{ return my_e; }

int GameModel::getF() const
{ return my_f; }

void GameModel::setD( const int a )
{ my_d = a; }

void GameModel::setE( const int a )
{ my_e = a; }

void GameModel::setF( const int a )
{ my_f = a; }

