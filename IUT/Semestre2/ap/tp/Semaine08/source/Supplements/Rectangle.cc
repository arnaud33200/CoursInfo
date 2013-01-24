#include "Screen.h"
#include "Point.h"
#include "Rectangle.h"


Rectangle::Rectangle( char col, const Point & a, const Point & b )
{
  my_col = col;
  search_sw_ne( a, b );
}

Rectangle::Rectangle( char col, const Point & a, int width, int height )
{
  my_col = col;
  my_sw = a;
  my_ne = Point( a.getX()+width, a.getY()+height );
}

Rectangle::~Rectangle()
{}


void
Rectangle::search_sw_ne ( const Point & a, const Point & b )
{
  if ( a.getX() <= b.getX() ) 
    if ( a.getY() <= b.getY() ) {
      my_sw = a;
      my_ne = b;
    }
    else {
      my_sw = Point( a.getX(), b.getY() );
      my_ne = Point( b.getX(), a.getY() );
    }
else 
  if ( a.getY() <= b.getY() ) {
      my_sw = Point( b.getX(), a.getY() );
      my_ne = Point( a.getX(), b.getY() );
    }
    else {
      my_sw = b;
      my_ne = a;
    }
}

void 
Rectangle::move( int dx, int dy )
{ 
  my_sw.deplace( dx, dy );
  my_ne.deplace( dx, dy );
}

void 
Rectangle::draw( Screen & s )
{
  char oldPen = s.getColPen();
  s.setColPen( my_col );

  Point nw( my_sw.getX(), my_ne.getY() );
  Point se( my_ne.getX(), my_sw.getY() );

  s.put_line( nw, my_ne );
  s.put_line( my_ne, se );
  s.put_line( se, my_sw );
  s.put_line( my_sw, nw );
  
  s.setColPen( oldPen );
}
