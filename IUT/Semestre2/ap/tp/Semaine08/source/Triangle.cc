#include "Screen.h"
#include "Point.h"
#include "Triangle.h"

Triangle::Triangle(char col, Point f, Point s, Point t)
: _fp(f), _sp(s), _tp(t)
{
	my_col = col;
}

Triangle::~Triangle()
{ }

void Triangle::draw(Screen & s)
{
	char oldPen = s.getColPen();
  	s.setColPen( my_col );

  	s.put_line( _fp, _sp );
  	s.put_line( _sp, _tp );
  	s.put_line( _tp, _fp );
  
  	s.setColPen( oldPen );
}

void Triangle::move( int dx, int dy)
{
	_fp.deplace(dx, dy);
	_sp.deplace(dx, dy);
	_tp.deplace(dx, dy);
}
