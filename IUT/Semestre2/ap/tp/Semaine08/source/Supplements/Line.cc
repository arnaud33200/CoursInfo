#include "Screen.h"
#include "Point.h"
#include "Line.h"


Line::Line( char col, const Point & a, const Point & b )
{
  my_col = col; 
  my_w = a;
  my_e = b;
}

Line::Line( char col, const Point & a, int l )
{ 
  my_col = col; 
  my_w = a;
  my_e = Point( a.getX()+l-1, a.getY() );
}

Line::~Line()
{}

void 
Line::move( int dx, int dy ) 
{ 
  my_w.deplace( dx, dy );
  my_e.deplace( dx, dy );
}

void 
Line::draw( Screen & s ) 
{
  char oldPen = s.getColPen();
  s.setColPen( my_col );

  s.put_line( my_w, my_e );

  s.setColPen( oldPen );  
}
