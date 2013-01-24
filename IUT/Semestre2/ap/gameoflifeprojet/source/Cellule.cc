/**
 * \file Cellule.cc
 * \brief Cellule du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include "Cellule.h"
#include "util.h"

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Cellule::Cellule( const int & x, const int & y, const float & aleac, const float & alear )
: Unite(x, y)
{
	_etatCellule = aleastate(aleac);
	_santeCellule = aleahealth(alear);
}

Cellule::Cellule( const int & x, const int & y, const state & e, const health & s )
: Unite(x, y)
{
	_etatCellule = e;
	_santeCellule = s;
}

Cellule::~Cellule()
{}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/

state Cellule::getEtat( ) const
{ return _etatCellule; }

health Cellule::getSante() const
{ return _santeCellule; }

void Cellule::setEtat (const state & e )
{ _etatCellule = e; }

void Cellule::setSante( const health & h )
{ _santeCellule = h; }


