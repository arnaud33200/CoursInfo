/**
 * \file GrilleCellule.cc
 * \brief regroupement de Cellule
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>
#include <cstdlib>

#include "GrilleCellule.h"
#include "enum.h"
#include "util.h"

using namespace std;

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn GrilleCellule ( const int & mia, const int & maa, const int & mid, const int & mad )
 * \brief Constructeur par parametre de GrilleCellule
 * \param miaa, maa, mid, mad entiers pour definit max et min voisin vivante des Cellules
 */
GrilleCellule::GrilleCellule ( const int & mia, const int & maa, const int & mid, const int & mad )
: _min_alive(mia), _max_alive(maa), _min_dead(mid), _max_dead(mad)
{
	_tmpAleaCellule = _aleaCellule = 0.55; 
	_tmpAleaResist = _aleaResist = 0.90;
	vector<Cellule> tmp;
	_wC = 40; _hC = 30;
	for ( int i=0; i < 16; i++ )
	{
		for ( int j=0; j < 12; j++ )
		{
			tmp.push_back(Cellule(i*40,j*30+30, _aleaCellule, _aleaResist));
		}
		_grilleCellule.push_back(tmp);
		tmp.clear();
	}
}		

GrilleCellule::~GrilleCellule ( )
{
}


/*#############################################################################
/#                                                                            #
/#            MODIFICATION MATRICE CELLULE                                     #
/#                                                                            #
##############################################################################*/

/**
 * \fn GrilleCellule::add_column (const float & w, const float & h )
 * \brief ajoute une colonne de Cellule
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
void GrilleCellule::add_column (const float & w, const float & h )
{
	int ti, tj;
	getTailleGrille(ti, tj);
	
	vector<Cellule> tmp;	
	for ( int j=0; j<tj; j++ )
		tmp.push_back(Cellule(20,30, _aleaCellule, _aleaResist));	
	_grilleCellule.push_back(tmp);
	update(w,h);
	
	getTailleGrille(ti, tj);
}

/**
 * \fn GrilleCellule::add_line (const float & w, const float & h )
 * \brief ajoute une ligne de Cellule
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
void GrilleCellule::add_line (const float & w, const float & h )
{
	int ti, tj;
	getTailleGrille(ti, tj);
	
	for ( int i=0; i < ti; i++ )
		_grilleCellule[i].push_back(Cellule(20,30, _aleaCellule, _aleaResist));
	update(w,h);
	getTailleGrille(ti, tj);
}

/**
 * \fn GrilleCellule::remove_column (const float & w, const float & h )
 * \brief enleve une colonne de Cellule
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
bool GrilleCellule::remove_column (const float & w, const float & h )
{
	int ti, tj;
	getTailleGrille(ti, tj);
	
	if ( ti >= 1 )
	{
		_grilleCellule.pop_back();
		update(w,h);
		return 1;
	}
	else
	{
		return 0;
		cout << "impossible !" << endl;
	}
		
	getTailleGrille(ti, tj);
}

/**
 * \fn GrilleCellule::remove_line (const float & w, const float & h )
 * \brief enleve une ligne de Cellule
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
bool GrilleCellule::remove_line (const float & w, const float & h )
{
	int ti, tj;
	getTailleGrille(ti, tj);
	
	if ( tj >= 2 )
	{
		for ( int i=0; i < ti; i++ )
			_grilleCellule[i].pop_back();
		update(w,h);	
		return 1;	
	}
	else
		return 0;

	getTailleGrille(ti, tj);
}

/**
 * \fn GrilleCellule::updateAll()
 * \brief met a jour toutes les cellules de la grille avec les nouveau parametre
 * \param rien
 * \return rien
 */
void GrilleCellule::updateAll()
{
	int ti, tj;
	getTailleGrille(ti,tj);
	
	for ( int i=0; i<ti; i++ )
		for ( int j=0; j<tj; j++ )
		{
// si l'utilisateur a fait des changement dans le pourcentage de vivant
			if ( _tmpAleaCellule != _aleaCellule ) 
			{
				_grilleCellule[i][j].setEtat( aleastate(_aleaCellule ) );
			}
// si l'utilisateur a fait des changement dans le pourcentage de resistant
			if ( _tmpAleaResist != _aleaResist )
			{		
				_grilleCellule[i][j].setSante( aleahealth(_aleaResist ) );
			}
		}
	_tmpAleaResist = _aleaResist;
	_tmpAleaCellule = _aleaCellule;
}


/*#############################################################################
/#                                                                            #
/#            VIE DES CELLULES                                                #
/#                                                                            #
##############################################################################*/

/**
 * \fn GrilleCellule::update(const float & w, const float & h)
 * \brief met a jour la position de chanque cellule aprés modification de la taille de la grille
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
void GrilleCellule::update(const float & w, const float & h)
{
	int ti, tj;
	getTailleGrille(ti, tj);
	_wC = w/ti; _hC = h/tj;
	for ( int i=0; i < ti; i++)
	{
		for ( int j=0; j < tj; j++)
		{
			_grilleCellule[i][j].setX( i * (w/ti) );
			_grilleCellule[i][j].setY( j * (h/tj) + 30 );
		}
	}
}

/**
 * \fn GrilleCellule::loi_de_vie()
 * \brief effectué les modifications de vie des Cellules
 * \param w,h réel qui donne la taille de la fenêtre
 * \return rien
 */
void GrilleCellule::loi_de_vie()
{
	int ti, tj, voisin;
	getTailleGrille(ti, tj);
	state tmp[ti][tj];
	
	for ( int i=0; i< ti; i++ )
	{
		for ( int j=0; j< tj; j++ )
		{
			voisin = nb_cellule_voisine(i,j);
			if( _grilleCellule[i][j].getEtat() == dead && voisin >= _min_dead && voisin <= _max_dead )
				tmp[i][j] = alive;
			else if( _grilleCellule[i][j].getEtat() == alive && voisin >= _min_alive && voisin <= _max_alive )
				tmp[i][j] = alive;
			else if( _grilleCellule[i][j].getEtat() == infest && voisin >= _min_dead && voisin <= _max_dead )
				tmp[i][j] = alive;
			else
				tmp[i][j] = dead;			
		}
	}
	
	for ( int i=0; i< ti; i++ )
	{
		for ( int j=0; j< tj; j++ )
			_grilleCellule[i][j].setEtat( tmp[i][j] );
	}
}

/**
 * \fn GrilleCellule::nb_cellule_voisine(const int & a, const int & b )
 * \brief donne le nombre de voisine d'une cellule vivant
 * \param a,b entiers qui donnent l'indicide de la Cellule
 * \return entier indiquant le nombre de voisin vivant
 */
int GrilleCellule::nb_cellule_voisine(const int & a, const int & b )
{
	int ti, tj;
	int cpt=0;
	getTailleGrille(ti, tj);
	
	for (int i=a-1; i<=a+1; i++)
	{
		for (int j=b-1; j<=b+1; j++)
		{
			if ( i!= a || j!= b )
				if ( i>=0 && i<ti && j>=0 && j<tj )
					if ( _grilleCellule[i][j].getEtat() == alive ) 
						cpt++;
		}
	}
	return cpt;
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS GRILLE CELLULES                                      #
/#                                                                            #
##############################################################################*/

void GrilleCellule::getCoordonne( const int & i, const int & j, Unite & e) const
{
	e.setX( _grilleCellule[i][j].getX() );
	e.setY( _grilleCellule[i][j].getY() );
}

void GrilleCellule::getSizePicture( float & w, float & h) const
{ w = _wC; h = _hC; }

state GrilleCellule::getEtatCellule(const int & i, const int & j) const
{ return _grilleCellule[i][j].getEtat(); }

health GrilleCellule::getHealthCellule( const int & i, const int & j) const
{ return _grilleCellule[i][j].getSante(); }

void GrilleCellule::getTailleGrille( int & ti, int & tj ) const
{
	ti = _grilleCellule.size();
	tj = _grilleCellule[1].size();
}

void GrilleCellule::setEtatCellule( const int & i, const int & j, const state & e)
{ _grilleCellule[i][j].setEtat( e ); }

void GrilleCellule::setMinAlive( const int & a )
{ _min_alive = a; }

void GrilleCellule::setMaxAlive( const int & a )
{ _max_alive = a; }

void GrilleCellule::setMinDead( const int & a )
{ _min_dead = a; }

void GrilleCellule::setMaxDead( const int & a )
{ _max_dead = a; }

void GrilleCellule::setAleaCellule( const float & a)
{ _aleaCellule = (100-a)/100; }

void GrilleCellule::setAleaResist(const float & a)
{ _aleaResist = (100-a)/100; }


/*#############################################################################
/#                                                                            #
/#            FLUX GRILLE CELLULES                                            #
/#                                                                            #
##############################################################################*/

/**
 * \fn GrilleCellule::lireGrilleCellule( fstream & f )
 * \brief modifie les Cellules a partir d'un flux
 * \param f un flux qui contient les informations necessaire
 * \return rien
 */
void GrilleCellule::lireGrilleCellule( fstream & f )
{
	int ti, tj;
	float x,y;
	int val;
	state e;
	health s;
	vector<Cellule> tmp;
	
	f >> _min_alive >> _max_alive >> _min_dead >> _max_dead;
	f >> _aleaCellule >> _aleaResist;
	f >> ti >> tj;
	f >> _wC >> _hC;
	
	_grilleCellule.clear();
	for ( int i = 0; i < ti; i++ )
	{
		for (int j = 0; j < tj; j++)
		{
			f >> x >> y;
			
			f >> val;
			e = getState(val);
			f >> val;
			s = getHealth(val);
			
			tmp.push_back( Cellule(x,y,e,s) );
		}
		_grilleCellule.push_back( tmp );
		tmp.clear();
	}
}

/**
 * \fn GrilleCellule::ecrireGrilleCellule( fstream & f )
 * \brief charge les Cellules a partir d'un flux
 * \param f un flux qui contiendra les informations necessaire
 * \return rien
 */
void GrilleCellule::ecrireGrilleCellule( fstream & f )
{
	int ti, tj;
	getTailleGrille(ti, tj);
	
	f << _min_alive << " " << _max_alive << " " << _min_dead << " " << _max_dead << endl;
	f << _aleaCellule << " " << _aleaResist << endl;
	f << ti << " " << tj << endl;
	f << _wC << " " << _hC << endl;
	
	for ( int i = 0; i < ti; i++ )
		for (int j = 0; j < tj; j++)
		{
			f << _grilleCellule[i][j].getX() << " " << _grilleCellule[i][j].getY() << endl;
			f << int(_grilleCellule[i][j].getEtat()) << " " << int(_grilleCellule[i][j].getSante()) << endl;
		}
}
