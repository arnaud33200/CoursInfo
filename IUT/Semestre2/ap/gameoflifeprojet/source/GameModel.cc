/**
 * \file GameModel.cc
 * \brief model du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include <iostream>

#include "GameModel.h"
#include "enum.h"
#include "event.h"

using namespace std;
//~ using namespace sf;

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn GameModel::GameModel (int w, int h )
 * \brief constructeur par paramétre du GameModel
 * \param w,h des réels pour indiqué la taille de la fenêtre
 */
GameModel::GameModel(const float & w, const float & h )
: _w(w), _h(h), _stateGame( false), _clickL(false), _clickR(false)
{
	_gVirus = new GroupeVirus( 2, 6.0, 1);
	_gCellule = new GrilleCellule(2,3,3,3);
	_gCellule->update(_w,_h);
	_vitesseExe = 0;
	_timeVitesse.Reset();
	_save = new GameSave();
}

GameModel::~GameModel ( )
{
	delete _save; 
	delete _gVirus; 
	delete _gCellule; 
}

/*#############################################################################
/#                                                                            #
/#            ACTION SUR LE JEU                                               #
/#                                                                            #
##############################################################################*/

/**
 * \fn GameModel::nextStep()
 * \brief applique les changements à l'étape suivante
 * \param rien
 * \return rien
 */
void GameModel::nextStep()
{
	_gVirus->lifeTimeVirus(_stateGame);
	
	if ( _timeVitesse.GetElapsedTime() >= _vitesseExe )
	{
		_timeVitesse.Reset();
		if ( _stateGame )
		{
			_gVirus->moveVirus();
			_gCellule->loi_de_vie();
			virusVsCellule();
		}
	}
}

/**
 * \fn GameModel::play_pause(const bool & p)
 * \brief méthode qui met le jeu en pause ou en lecture
 * \param p booléen qui précise si le bouton play pause à été préssé
 * \return rien
 */
void GameModel::play_pause(const bool & p)
{
	if ( p )
	{
		if ( _stateGame ) _stateGame = false;
		else _stateGame = true;
	}
}

/**
 * \fn GameModel::virusVsCellule()
 * \brief fait la confrontation des Virus sur les Cellules
 * \param rien
 * \return rien
 */
void GameModel::virusVsCellule()
{
	int ti = _gVirus->getSizeGroupe();
	int tci, tcj, ci, cj;
	_gCellule->getTailleGrille(tci, tcj);
	float vx, vy, vw, vh;
	
	for (int i=0; i<ti; i++)
	{
		_gVirus->getCoordonne(i, vx, vy, vw, vh);
		ci = ( vx * tci ) / _w;
		cj = ((vy * tcj ) / _h)-1;

		if (  !_gVirus->getTargetVirus(i) )
		{

// si la position du virus est bien situé dans la fenêtre de jeu 			
			if ( ci >= 0 && ci < tci && cj >= 0 && cj < tcj ) 
			{
				if ( _gCellule->getEtatCellule(ci, cj) == alive && _gCellule->getHealthCellule(ci, cj) == normal 
					&& _stateGame)
				{
					_gCellule->setEtatCellule(ci, cj, infest);
					_gVirus->setCoordonneVirus(i, ci*(_w/tci)+((_w/tci)/2)-(vw/2), cj*(_h/tcj)+((_h/tcj)/2)-(vh/2) );
					_gVirus->setTargetVirus(i, true);
					_gVirus->setResetIncubVirus( i );
				}
			}
// si le virus sort de la fenetre
			else 
			{
				//~ _gVirus->delVirus( i );
			}
		}
			
// si le virus a deja une cible, il applique son temps d'incubation
		else
		{
			//~ if ( ci >= 0 && ci < tci && cj >= 0 && cj < tcj )
				//~ _gCellule->setEtatCellule(ci, cj, infest);
			_gVirus->incubTimeVirus( _stateGame, i );			
		}
	}
}

/**
 * \fn GameModel::loadSave( const bool & b )
 * \brief charge la derniere sauvegarde
 * \param b booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::loadSave( const bool & b )
{ if ( b ) _save->open("save/game.sav", _gCellule, _gVirus, _stateGame);  }

/**
 * \fn GameModel::saveSave( const bool & b )
 * \brief sauvegarde la partie en cours
 * \param b booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::saveSave( const bool & b )
{ if ( b ) _save->save("save/game.sav", _gCellule, _gVirus, _stateGame); }


/*#############################################################################
/#                                                                            #
/#            ACTION SUR CELLULES                                             #
/#                                                                            #
##############################################################################*/

/**
 * \fn GameModel::add_column (const bool & add )
 * \brief ajoute une colonne de Cellule
 * \param add booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::add_column( const bool & add, Button* button)
{
	if ( add || (button->getPress() && button->getKeep()) )
	{
		int ti, tj;
		_gCellule->add_column(_w, _h);
		
		getTailleGrilleCellule(ti, tj);
		_gVirus->updateVirus((_w/ti)/3, (_h/tj)/3, -ti, 0 );
	}
		
}

/**
 * \fn GameModel::add_line(const bool & add)
 * \brief ajoute une ligne de Cellule
 * \param add booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::add_line(const bool & add, Button* button)
{
	if ( add || (button->getPress() && button->getKeep())  )
	{		
		_gCellule->add_line(_w, _h);
		
		int ti, tj;
		getTailleGrilleCellule(ti, tj);
		_gVirus->updateVirus((_w/ti)/3, (_h/tj)/3, 0, -tj );
	}
}

/**
 * \fn GameModel::remove_column(const bool & del)
 * \brief enleve une colonne de Cellule
 * \param del booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::remove_column(const bool & del, Button* button)
{	
	if ( del || (button->getPress() && button->getKeep()) )
	{
		bool up;
		int ti, tj;
		
		up = _gCellule->remove_column(_w, _h);
		getTailleGrilleCellule(ti, tj); 
		 if ( up )
			_gVirus->updateVirus((_w/ti)/3, (_h/tj)/3, ti, 0 );
	}
}

/**
 * \fn GameModel::remove_line(const bool & del)
 * \brief enleve une ligne de Cellule
 * \param del booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::remove_line(const bool & del, Button* button)
{
	if ( del || (button->getPress() && button->getKeep()) )
	{
		int ti, tj;
		bool up;
		
		up = _gCellule->remove_line(_w, _h);
		getTailleGrilleCellule(ti, tj);
		if ( up )
			_gVirus->updateVirus((_w/ti)/3, (_h/tj)/3, 0, tj );
	}
}

/**
 * \fn GameModel::alive_cellule( Event* event, const int & mx, const int & my )
 * \brief rend une cellule vivante
 * \param event Event contenant l'evenement sourie du jeu
 * \param mx, my entier qui définissent les coordonnée de la sourie
 * \return rien
 */
void GameModel::alive_cellule( Event* event, const int & mx, const int & my )
{
	if ( clickDownLeft(event)) 
		_clickL = true;
	if ( clickUpLeft(event) )
		_clickL = false;
	if ( _clickL && mx > 0 && mx < _w && my > 30 && my < _h+30)
	{
		int ti, tj, i, j;
		_gCellule->getTailleGrille(ti, tj);
		i = ( mx * ti ) / _w;
		j = ((my-30) * tj) / _h ;
		_gCellule->setEtatCellule(i, j, alive); 
	}
}

/**
 * \fn GameModel::dead_cellule( Event* event, const int & mx, const int & my )
 * \brief rend une cellule morte
 * \param event Event contenant l'evenement sourie du jeu
 * \param mx, my entier qui définissent les coordonnée de la sourie
 * \return rien
 */
void GameModel::dead_cellule( Event* event, const int & mx, const int & my )
{
	if ( clickDownRight(event) )
		_clickR = true;
	if ( clickUpRight(event) )
		_clickR = false;
	if ( _clickR && mx > 1 && mx < _w && my > 30 && my < _h+30 )
	{
		int ti, tj, i, j;
		_gCellule->getTailleGrille(ti, tj);
		i = ( mx * ti ) / _w;
		j = ((my-30) * tj) / _h ;
		_gCellule->setEtatCellule(i, j, dead); 
	}
}

/**
 * \fn GameModel::update_all_Cellule(const bool & b)
 * \brief fait appel à la mise a jours des Cellules
 * \param b booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::update_all_Cellule(const bool & b)
{
	if ( b )
		_gCellule->updateAll();
}


/*#############################################################################
/#                                                                            #
/#            ACTION SUR VIRUS                                                #
/#                                                                            #
##############################################################################*/		

/**
 * \fn GameModel::add_virus ( const bool & add )
 * \brief ajoute un virus dans le jeu
 * \param add booléen qui indique si le bouton a été préssé
 * \return rien
 */	
void GameModel::add_virus ( const bool & add )
{ if ( add ) _gVirus->addVirus(); }

/**
 * \fn GameModel::del_virus ( const bool & del )
 * \brief enleve le dernier virus ajouter dans le jeu
 * \param del booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::del_virus ( const bool & del )
{ if ( del ) _gVirus->removeVirus(); }

/**
 * \fn GameModel::removeAllVirus ( const bool & all )
 * \brief enléve tous les Virus du Jeu
 * \param all booléen qui indique si le bouton a été préssé
 * \return rien
 */
void GameModel::removeAllVirus ( const bool & all )
{ if ( all ) _gVirus->removeAll(); }

/**
 * \fn GameModel::removeVirus( const int & i, const bool & d )
 * \brief enleve un Virus précis
 * \param d booléen qui indique si le bouton a été préssé
 * \param i entier qui indique l'indice du virus a supprimé
 * \return rien
 */
void GameModel::removeVirus( const int & i, const bool & d )
{ if ( d ) _gVirus->delVirus(i); }


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS SUR VIRUS                                            #
/#                                                                            #
##############################################################################*/

int GameModel::getSizeGroupeVirus() const
{ return _gVirus->getSizeGroupe(); }

void GameModel::getCoordonneVirus( const int & i, float & x, float & y, float & w, float & h ) const
{ _gVirus->getCoordonne(i, x, y, w, h); }

void GameModel::setNbEfantVirus( const int & e )
{ _gVirus->setNbEfant(e); }

void GameModel::setDureVieVirus( const float & d )
{ _gVirus->setDureVie(d); }

void GameModel::setDureIncubVirus( const float & d )
{ _gVirus->setDureIncub(d); }


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS SUR CELLULE                                          #
/#                                                                            #
##############################################################################*/

void GameModel::getCoordonneCellule( const int & i, const int & j, Unite & e) const
{ _gCellule->getCoordonne(i, j, e); }

void GameModel::getSizePictureCellule( float & w, float & h ) const
{ _gCellule->getSizePicture(w,h); }

health GameModel::getSanteCellule(const int & i, const int & j) const
{ _gCellule->getHealthCellule(i, j); }

state GameModel::getEtatCellule(const int & i, const int & j) const
{ return _gCellule->getEtatCellule(i,j); }

void GameModel::getTailleGrilleCellule( int & ti, int & tj ) const
{ _gCellule->getTailleGrille(ti, tj); }

void GameModel::setMinAliveCellule( const int & a )
{ _gCellule->setMinAlive(a); }

void GameModel::setMaxAliveCellule( const int & a )
{ _gCellule->setMaxAlive(a); }

void GameModel::setMinDeadCellule( const int & a )
{ _gCellule->setMinDead(a); }

void GameModel::setMaxDeadCellule( const int & a )
{ _gCellule->setMaxDead(a); }

void GameModel::setAleaCelluleGrille( const float & a )
{ _gCellule->setAleaCellule(a); }

void GameModel::setAleaResistGrille( const float & a )
{ _gCellule->setAleaResist(a); }


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS SUR MODEL                                            #
/#                                                                            #
##############################################################################*/

bool GameModel::getStateGame() const
{ return _stateGame; }

int GameModel::getVitesse() const
{ return (100 - _vitesseExe)*100; }

void GameModel::setW(const int & w )
{ _w = w; }


void GameModel::setH(const int & h )
{ _h = h; }

void GameModel::setVitesse( const int & v)
{ _vitesseExe = ( 100 - (v*1.0) ) / 100; }
