
#include "Element.h"

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Element::Element(const float & x, const float & y, const float & w, const float & h )
: _x(x), _y(y), _w(w), _h(h){}

Element::Element(){}

Element::~Element ( )
{}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS LECTURE                                              #
/#                                                                            #
##############################################################################*/

float Element::getX ( ) const
{ return _x; }

float Element::getY ( ) const
{ return _y; }

float Element::getW ( ) const
{ return _w; }

float Element::getH( ) const
{ return _h; }


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS ECRITURE                                             #
/#                                                                            #
##############################################################################*/

void Element::setX (const float & x )
{ _x = x; }

void Element::setY (const float & y )
{ _y = y; }

void Element::setW (const float & w )
{ _w = w; }

void Element::setH (const float & h )
{ _h = h; }

