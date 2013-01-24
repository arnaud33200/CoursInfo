#ifndef __MYSQUARE__
#define __MYSQUARE__

#include "Screen.h"
#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"

class Square : public Rectangle
{
	public:
		Square( char col, const Point & a, int taille );
};

#endif
