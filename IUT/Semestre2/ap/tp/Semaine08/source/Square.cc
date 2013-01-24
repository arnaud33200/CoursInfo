#include "Screen.h"
#include "Point.h"
#include "Square.h"


Square::Square( char col, const Point & a, int taille )
: Rectangle(col,a,Point(a.getX()+taille,a.getY()+taille) )
{}
