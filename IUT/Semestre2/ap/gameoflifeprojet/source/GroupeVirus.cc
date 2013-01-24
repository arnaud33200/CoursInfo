/**
 * \file GroupeVirus.cc
 * \brief regroupement de Virus
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include  "GroupeVirus.h"

using namespace std;

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn GroupeVirus(const int & enfant, const float & vie, const int & incub )
 * \brief Constructeur parametre du GroupeVirus
 * \param enfant entier du nombre d'enfant à la descendance
 * \param vie réel de durée de vie des Virus
 * \param incub réel de durée d'incubation des Virus
 */
GroupeVirus::GroupeVirus(const int & enfant, const float & vie, const int & incub )
: _wVirus(20), _hVirus(20), _nbEnfant(enfant), _dureVie(vie), _dureIncub(incub)
{}

GroupeVirus::~GroupeVirus ( )
{
}


/*#############################################################################
/#                                                                            #
/#            MODIFICATION GROUPE VIRUS                                       #
/#                                                                            #
##############################################################################*/

/**
 * \fn GroupeVirus::removeVirus()
 * \brief Methode qui enleve la dernier Virus ajouter
 * \param rien
 * \return rien
 */
void GroupeVirus::removeVirus()
{
	if ( _groupeVirus.size() > 0 )
	{
		_groupeVirus.pop_back();
	}
cout << "last Virus Removed !!!!" << endl;
}

/**
 * \fn GroupeVirus::addVirus()
 * \brief Methode qui ajoute un Virus au Groupe
 * \param rien
 * \return rien
 */
void GroupeVirus::addVirus()
{ _groupeVirus.push_back( Virus() ); }

/**
 * \fn GroupeVirus::removeVirusAll()
 * \brief Methode qui enleve tous les Virus du Groupe
 * \param rien
 * \return rien
 */
void GroupeVirus::removeAll()
{ _groupeVirus.clear(); }

/**
 * \fn GroupeVirus::moveVirus()
 * \brief Methode qui enleve la dernier Virus ajouter
 * \param rien
 * \return rien
 */
void GroupeVirus::moveVirus()
{
	for ( int i=0; i< _groupeVirus.size(); i++ )
		_groupeVirus[i].move(_wVirus, _hVirus);
}

/**
 * \fn GroupeVirus::delVirus( const int & i )
 * \brief Methode qui retire un Virus et recalle correctement le groupe
 * \param i entier indiquant l'indice du virus a retiré
 * \return rien
 */
void GroupeVirus::delVirus( const int & i )
{
	int n = getSizeGroupe();
	
	if ( n > 0 && i >= 0 && i < n )
	{
		for (int a = i+1; a < n; a++ )
		{
			_groupeVirus[a-1] = _groupeVirus[a];
		}
		_groupeVirus.pop_back();
	}
	cout << "virus " << i << " deleted !!!!" << endl;
	
}

/**
 * \fn GroupeVirus::updateVirus(const int & w, const int & h, const int & ti, const int & tj)
 * \brief Methode qui met a jours la taille et la position de chaque Virus du Groupe
 * \param w, h réels qui indiquant la nouvelle taille des Virus
 * \param ti, tj, entier indiquand la taille de la nouvelle GrilleCellule
 * \return rien
 */
void GroupeVirus::updateVirus(const float & w, const float & h, const int & ti, const int & tj)
{
	int tvi = getSizeGroupe();
	float curx, cury;
	_wVirus = w;
	_hVirus = h;
	
	for ( int i=0; i < tvi; i++)
	{
		curx = _groupeVirus[i].getX();
		cury = _groupeVirus[i].getY();
		
		if ( ti != 0 ) _groupeVirus[i].setX( curx + (curx / ti ) );
		if ( tj != 0 ) _groupeVirus[i].setY( cury + (cury / tj) );	
	}
}


/*#############################################################################
/#                                                                            #
/#            ACTION TIMES VIRUS                                              #
/#                                                                            #
##############################################################################*/

/**
 * \fn GroupeVirus::lifeTimeVirus(const bool & g)
 * \brief met en place la vie des Virus dans le jeu
 * \param g booléen qui donne l'etat du jeu ( jouer ou pause )
 * \return rien
 */
void GroupeVirus::lifeTimeVirus(const bool & g)
{
	int ti = getSizeGroupe();
	float time, addtime;
	for ( int i=0; i < ti; i++ )
	{
// s'applique seulement si le virus n'a toujours pas infecté une cellule
		if ( !_groupeVirus[i].getTarget() )
		{
			time = _groupeVirus[i].getTimeLife();
			addtime = _groupeVirus[i].getTimePassed();
// si le jeu est sur pause, on incrémente le temps passé
			if ( !g )
				_groupeVirus[i].setTimePassed( time );
// sinon on vérifié si le temps s'est écoulé
			else if( (time - addtime)  >= (_dureVie + addtime)  )
			{
				delVirus(i); 
				cout << "temps de vie terminé pour Virus " << i << endl;
			}
		}
	}
}

/**
 * \fn GroupeVirus::incubTimeVirus(const bool & g, const int & i )
 * \brief met en place la durée d'incubation des Virus dans le jeu
 * \param g booléen qui donne l'etat du jeu ( jouer ou pause )
 * \param i entier qui donne l'indice du Virus
 * \return rien
 */
void GroupeVirus::incubTimeVirus(const bool & g, const int & i )
{
	float timeInc = _groupeVirus[i].getTimeIncub();
	float addInc = _groupeVirus[i].getTimePassed();
			
	if ( !g )
		_groupeVirus[i].setTimeIncPassed( timeInc );
	else if ( (timeInc - addInc) >= ( _dureIncub + addInc) )
	{		
		for ( int a = 0; a < _nbEnfant; a++ )
			_groupeVirus.push_back( Virus(_groupeVirus[i]) );
		delVirus( i );
		cout << "temps d'incub terminé pour Virus " << i << endl;
	}
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS VIRUS                                                #
/#                                                                            #
##############################################################################*/

int GroupeVirus::getSizeGroupe() const
{ return _groupeVirus.size(); }

int GroupeVirus::getDureeInc() const
{ return _dureIncub; }

void GroupeVirus::getCoordonne( const int & i, float & x, float & y, float & w, float & h ) const
{
	x = _groupeVirus[i].getX();
	y = _groupeVirus[i].getY();
	w = _wVirus;
	h = _hVirus;
}

bool GroupeVirus::getTargetVirus( const int & i) const
{ return _groupeVirus[i].getTarget(); }


void GroupeVirus::setCoordonneVirus( const int & i, const float & x, const float & y )
{
	_groupeVirus[i].setX( x );
	_groupeVirus[i].setY( y );
}

void GroupeVirus::setTargetVirus( const int & i, const bool & t )
{ _groupeVirus[i].setTarget(t); }

void GroupeVirus::setResetIncubVirus( const int & i )
{ _groupeVirus[i].setResetIncub(); }

void GroupeVirus::setNbEfant( const int & e )
{ _nbEnfant = e; }

void GroupeVirus::setDureVie( const float & d )
{ _dureVie = d; }

void GroupeVirus::setDureIncub( const float & d )
{ _dureIncub = d; }


/*#############################################################################
/#                                                                            #
/#           FLUX GROUPE VIRUS                                                #
/#                                                                            #
##############################################################################*/

/**
 * \fn GroupeVirus::lireGroupeVirus( fstream & f )
 * \brief modifie les Virus a partir d'un flux
 * \param f un flux qui contient les informations necessaire
 * \return rien
 */
void GroupeVirus::lireGroupeVirus( fstream & f )
{
	int ti;
	bool t;
	float p, ip, x, y;
	
	f >> ti;
	f >> _wVirus >> _hVirus;
	f >> _nbEnfant >> _dureVie >> _dureIncub;
	
	_groupeVirus.clear();
	
	for( int i=0; i<ti; i++ )
	{
		f >> x >> y >> t >> p >> ip;
		
		_groupeVirus.push_back( Virus(x,y) );
		_groupeVirus[i].setTarget(t);
		_groupeVirus[i].setTimePassed(p);
		_groupeVirus[i].setTimeIncPassed(ip);
	}
}

/**
 * \fn GroupeVirus::lireGroupeVirus( fstream & f )
 * \brief charge les Virus a partir d'un flux
 * \param f un flux qui contiendra les informations necessaire
 * \return rien
 */
void GroupeVirus::ecrireGroupeVirus( fstream & f )
{
	int ti = getSizeGroupe();
	f << ti << endl;
	f << _wVirus << " " << _hVirus << endl;
	f << _nbEnfant << " " << _dureVie << " " << _dureIncub << endl;
	
	for( int i=0; i<ti; i++ )
	{
		f << _groupeVirus[i].getX() << " " << _groupeVirus[i].getY() << endl;
		f << _groupeVirus[i].getTarget() << " " << _groupeVirus[i].getTimePassed() << " " << _groupeVirus[i].getTimeIncPassed() << endl;
	}
}
