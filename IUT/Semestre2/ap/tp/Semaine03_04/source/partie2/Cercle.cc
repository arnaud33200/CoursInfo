// Fichier Cercle.cc

#include <iostream>
#include <sstream>
#include <string>
#include "Cercle.h"
#include "Point.h"

using namespace std;

ostream& operator<<(ostream& out, const Cercle& c) {
  out << c.toString();
  return out;
}

Cercle::Cercle()
// ici, appel Point::constructeur par defaut
{
  cout << "Cercle::Constructeur par defaut" << endl;
  my_centre = new Point();
  my_rayon = 0;
}

Cercle::~Cercle()
{
  cout << "Cercle::Destructeur" << endl;
  delete my_centre;
}

Cercle::Cercle( float r )
{  
	cout << "Cercle::Constructeur rayon " << endl;
	my_centre = new Point();
  	my_rayon = r;
}

/// #
Cercle::Cercle( float r, float x, float y )
{
  cout << "Cercle::Constructeur rayon + x + y " << endl;
  my_centre = new Point(x,y);
  my_rayon = r;
}

/// #
Cercle::Cercle( float r, const Point & p )
{
  cout << "Cercle::Constructeur rayon + point " << endl;
  my_centre = new Point(p);
  my_rayon = r;
}

Cercle::Cercle( const Cercle & c )
{
	cout << "Cercle::Constructeur par copie" << endl;
	my_centre = new Point( c.my_centre->getX(), c.my_centre->getY() );
	my_rayon = c.my_rayon;
}

Cercle & Cercle::operator=( const Cercle & c )
{
	cout << "Cercle::Operateur affectation" << endl;
	if ( this != &c )
	{
		my_centre = c.my_centre;
		my_rayon = c.my_rayon;
	}
	return *this;
}

string
Cercle::toString() const
{
  ostringstream ostr;

  ostr << "centre : " << my_centre->toString() << endl;
  ostr << "rayon :  " << my_rayon;
  return ostr.str();
}
