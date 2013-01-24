#include <iostream>
#include "Point.h"
#include "util.h"

using namespace std;

void
cinColour( char & col )
{
  cout << "Couleur ? b(lack) r(ed) g(reen) B(lue)" << endl;
  cin >> col;
  while( col!='b' && col!='r' && col!='g' && col!='B' )
  {
    cout << "Pas definie, recommencez" << endl;
	cin >> col;
  }
  switch( col )
  {
    case 'b': col = black; break;
    case 'r': col = red;   break;
    case 'g': col = green; break;
    case 'B': col = blue;  break;
  }
}

void
cinPoint( Point & a )
{
  int x, y;
  cout << "abs puis ord" << endl;
  cin >> x >> y;
  a.setX( x );
  a.setY( y );
}

void
cinLine( char & col, Point & sw, Point & ne )
{
  cout << "Saisie de Line" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
}

void
cinLineHoriz( char & col, Point & sw, int & w )
{
  cout << "Saisie de Line horizontale" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "length ?" << endl;
  cin >> w;
}

void
cinLineBrok( char & col, Point & sw, Point & ne, Point & m )
{
  cout << "Saisie de Line cassee" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
  cout << "Point m ?  ";
  cinPoint( m );
}

void 
cinRectangle( char & col, Point & sw, Point & ne )
{
  cout << "Saisie de Rectangle" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
}

void 
cinCircle( char & col, Point & c, int & r )
{
  cout << "Saisie de Circle" << endl;
  cinColour( col );
  cout << "Point center ?  ";
  cinPoint( c );
  cout << "radius ?" << endl;
  cin >> r;
}

void cinTriangle( char & col, Point & f, Point & s, Point & t)
{
	cout << "saisie de Triangle" << endl;
	cinColour( col );
	cout << "premier Points ?  ";
	cinPoint( f );
	cout << "deuxieme Points ?  ";
	cinPoint( s );
	cout << "troisieme Points ?  ";
	cinPoint( t );
	cinPoint( t );
}


void cinSquare( char & col, Point & p, int & c )
{
	cout << "saisie de Square" << endl;
	cinColour( col );
	cout << "Point ?  ";
	cinPoint( p );
	cout << "coté du Square ?  ";
	cin >> c;	
}
