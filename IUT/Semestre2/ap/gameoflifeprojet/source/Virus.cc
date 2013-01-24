/**
 * \file Virus.cc
 * \brief unité perturbateur du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include "Virus.h"
#include "util.h"

using namespace std;
using namespace sf;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Virus::Virus()
: Unite( aleaint(10,790) , aleaint(40, 590)),
 _target(false), _dx(aleaint(-2,2)), _dy(aleaint(-2,2))
{ 
	_timeInc = _timePassed = 0;
	_timeDir = 0;
	_timeLife.Reset();
}

/**
 * \fn Virus( const int & x, const int & y )
 * \brief Constructeur par parametre de Virus
 * \param x,y réels definissant la position d'un Virus
 */
Virus::Virus( const float & x, const float & y )
: Unite( x, y), _target(false)
{ 
	_timeInc = _timePassed = 0;
	_timeDir = 0;
	_timeLife.Reset();
}

/**
 * \fn Virus( const Virus & v )
 * \brief Constructeur par copie de Virus
 * \param v Virus à copier
 */
Virus::Virus( const Virus & v )
: Unite(v.getX(),v.getY())
{
	_timePassed = 0;
	_timeDir = 0;
	_timeLife.Reset();	
}

Virus::~Virus( )
{ }


/*#############################################################################
/#                                                                            #
/#            MOUVEMENTS VIRUS                                                #
/#                                                                            #
##############################################################################*/

/**
 * \fn Virus::move(const int & w, const int & h )
 * \brief Methode qui definit le mouvement d'une cellule à la prochaine etape
 * \param w, h réels qui donnent la taille du virus qui permettra le deplacement
 * \return rien
 */
void Virus::move(const float & w, const float & h )
{
	if ( !_target  )
	{
		_timeDir++;
		if ( _timeDir >= 5 )
		{
			_dx = aleafloat(-1, 1);
			_dy = aleafloat(-1, 1);
			_timeDir = 0;
		}
	
		_x = _x + ( _dx*w );
		_y = _y + ( _dy*h  );
	}
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS VIRUS                                                #
/#                                                                            #
##############################################################################*/

bool Virus::getTarget() const
{ return _target; }

float Virus::getTimeLife() const
{ return _timeLife.GetElapsedTime(); }

float Virus::getTimeIncub() const
{ return _timeIncub.GetElapsedTime(); }

float Virus::getTimePassed() const
{ return _timePassed; }

float Virus::getTimeIncPassed() const
{ return _timeInc; }


void Virus::setTimePassed( const float & t )
{ _timePassed = t; }

void Virus::setTimeIncPassed( const float & t )
{ _timeInc = t; }

void Virus::setResetIncub()
{ _timeIncub.Reset(); }

void Virus::setResetLife()
{ _timeLife.Reset(); }

void Virus::setTarget( const bool & t )
{ _target = t; }
