// Fichier main.cc

#include <iostream>
#include "Point.h"

using namespace std;

int
main()
{
  Point p0 ;
  cout << p0 << endl ;

  Point p1 (4, 5) ;
  cout << p1 << endl ;

  Point p2 = p1 ;
  cout << p2 << endl ;

  Point p3 ;
  p3 = p2 ;
  cout << p3 << endl ;

  Point tab[2];
  cout << tab[0] << " " << tab[1] << endl ;
}

/*
Point::Constructeur par defaut
(0,0)
Point::Constructeur : 4 , 5
(4,5)
Point::Constructeur par copie
(4,5)
Point::Constructeur par defaut
Point::Operateur affectation
(4,5)
Point::Constructeur par defaut
Point::Constructeur par defaut
(0,0) (0,0)
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
*/