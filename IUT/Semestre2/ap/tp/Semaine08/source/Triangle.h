#ifndef __MYTRIANGLE__
#define __MYTRIANGLE__

#include "Shape.h"
#include "Screen.h"
#include "Point.h"

class Triangle : public Shape
{
	private:
		Point _fp, _sp, _tp;
		
	public:
		Triangle(char col, Point f, Point s, Point t);
		~Triangle();
		void draw(Screen & s);
		void move( int dx, int dy);
};

#endif
