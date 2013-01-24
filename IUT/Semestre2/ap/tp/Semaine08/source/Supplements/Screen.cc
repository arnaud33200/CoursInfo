#include <iostream>
#include "Screen.h"
#include "Point.h"

using namespace std;

Screen::Screen()
{
  my_colPen = ' ';  //white;
  clear();
}

void
Screen::clear()
{
  for (int y=0; y<YMAX; y++)
    for (int x=0; x<XMAX; x++)
      my_screen[x][y] = ' ';  //white;

  my_screen[0][0] = '0';
  for (int x=1; x<XMAX; x++)
    my_screen[x][0] = '-';
  for (int y=1; y<YMAX; y++)
    my_screen[0][y] = '|';
}

void 
Screen::refresh()
{  
  for (int y=YMAX-1; 0<=y; y--)
  {
    for (int x=0; x<XMAX; x++)
      cout << my_screen[x][y];
    cout << endl;
  }
}

void 
Screen::setColPen( char col )
{
  my_colPen = col;
}

char 
Screen::getColPen() const
{
  return my_colPen;
}

bool
Screen::on_screen( const Point & p ) const
{
  return on_screen( p.getX(), p.getY() );
}

bool
Screen::on_screen( int a, int b ) const
{
  return 0<=a && a<XMAX && 0<=b && b<YMAX;
}

void 
Screen::put_point( const Point & p )
{
  put_point( p.getX(), p.getY() );
}

void 
Screen::put_point( int a, int b )
{
  if( on_screen(a,b) )
    my_screen[a][b] = my_colPen;
}

void 
Screen::put_line( const Point & p1, const Point & p2 )
{
  put_line( p1.getX(), p1.getY(), p2.getX(), p2.getY() );
}

void
Screen::put_line ( int x1, int y1, int x2, int y2 )
{
  int dx = 1;
  int dy = 1;
  int eps = 0;

  int  a = x2 - x1;
  int  b = y2 - y1;
  int  two_a;
  int  two_b;
  int  xcrit;

  if (a < 0) { dx = -1; a = -a; }
  if (b < 0) { dy = -1; b = -b; }

  two_a = 2 * a;
  two_b = 2 * b;
  xcrit = -b + two_a;

  put_point( x1, y1 );
  while( x1 != x2 || y1 != y2 )
  {
    if (eps <= xcrit)       { x1 += dx;  eps += two_b; }
	if (eps >= a || a <= b) { y1 += dy;  eps -= two_a; }
	put_point( x1, y1 );
  }
}


// draw a circle using Bresenham's algorithm
// as described by Foley and Van Dam, 1982
void
Screen::put_circle( const Point & center, int radius ) 
{
  // A ECRIRE PLUS TARD
  // affiche un point (center) tout seul en attendant...
  put_point( center );
}
