/**
 * \file Unite.cc
 * \brief unité du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include "Unite.h"

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Unite::Unite(const float & x, const float & y )
: _x(x), _y(y)
{}

Unite::Unite()
{}

Unite::~Unite ( )
{}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS LECTURE                                              #
/#                                                                            #
##############################################################################*/

float Unite::getX ( ) const
{ return _x; }

float Unite::getY ( ) const
{ return _y; }


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS ECRITURE                                             #
/#                                                                            #
##############################################################################*/

void Unite::setX (const float & x )
{ _x = x; }

void Unite::setY (const float & y )
{ _y = y; }
