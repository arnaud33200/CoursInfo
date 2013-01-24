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

Point::Point( int x, int y ) {
//  cout << "Point::Constructeur : " << x << " , " << y << endl;
  my_abs = x;
  my_ord = y;
}

Point::Point() {
//  cout << "Point::Constructeur par defaut" << endl;
  my_abs = 0;
  my_ord = 0;
}

Point::~Point() {
//  cout << "Point::Destructeur" << endl;
}

Point::Point( const Point & p ) {
//  cout << "Point::Constructeur par copie" << endl;
  my_abs = p.my_abs;
  my_ord = p.my_ord;
}

Point &
Point::operator=( const Point & p ) {
//  cout << "Point::Operateur affectation" << endl;
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

int
Point::getX() const {
  return my_abs;
}

int
Point::getY() const {
  return my_ord;
}

void
Point::setX( int new_x ) {
  my_abs = new_x;
}

void
Point::setY( int new_y ) {
  my_ord = new_y;
}

void
Point::deplace( int d_x, int d_y ) {
  my_abs += d_x;
  my_ord += d_y;
}


bool
Point::operator==( const Point & p ) const {
   return my_abs==p.my_abs && my_ord==p.my_ord;
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

