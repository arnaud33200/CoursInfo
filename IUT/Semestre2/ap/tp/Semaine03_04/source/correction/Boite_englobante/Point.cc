// Fichier Point.cc

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "Point.h"

using namespace std;

ostream& operator<<(ostream& out, const Point& p) {
  out << p.toString();
  return out;
}

const float Point::EPSILON=0.00000001; // calcul

Point::Point( float x, float y ) {
  cout << "Point::Constructeur : " << x << " , " << y << endl;
  my_abs = x;
  my_ord = y;
}

Point::Point() {
  cout << "Point::Constructeur par defaut" << endl;
  my_abs = 0;
  my_ord = 0;
}

Point::~Point() {
  cout << "Point::Destructeur" << endl;
}

Point::Point( const Point & p ) {
  cout << "Point::Constructeur par copie" << endl;
  my_abs = p.my_abs;
  my_ord = p.my_ord;
}

Point &
Point::operator=( const Point & p ) {
  cout << "Point::Operateur affectation" << endl;
  if ( this != &p ) {
    my_abs = p.my_abs;
    my_ord = p.my_ord;
  }
  return *this;
}

string
Point::toString() const
{
  ostringstream ostr;

  ostr << "(" << my_abs << "," << my_ord << ")";
  return ostr.str();
}

float
Point::getX() const {
  return my_abs;
}

float
Point::getY() const {
  return my_ord;
}

void
Point::setX( float new_x ) {
  my_abs = new_x;
}

void
Point::setY( float new_y ) {
  my_ord = new_y;
}

void
Point::deplace( float d_x, float d_y ) {
  my_abs += d_x;
  my_ord += d_y;
}

float
Point::distance() const {
  // distance à l'origine
  return sqrt(my_abs*my_abs + my_ord*my_ord);
}

float
Point::distance( const Point & p ) const {
  float d_x = p.my_abs-my_abs;
  float d_y = p.my_ord-my_ord;
  return sqrt(d_x*d_x + d_y*d_y);
}

bool
Point::operator==( const Point & p ) const {
   return distance(p) < EPSILON ;
}

bool
Point::operator<( const Point & p) const {
  // si points egaux : retourner faux
  if ( *this == p )
    return false ;
  // points pas egaux
  if ( my_abs < p.my_abs )
    return true ;
  if ( my_abs > p.my_abs )
    return false ;
  // abscisses egales
  return  my_ord < p.my_ord ;
}

