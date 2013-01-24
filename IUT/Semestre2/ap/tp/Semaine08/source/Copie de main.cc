#include <iostream>
#include <cstdlib>

#include "Screen.h"
#include "Point.h"

#include "Shape.h"
#include "Line.h"
#include "LineBrok.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

#include "util.h"


int
main()
{
  Screen ecran;
  
  // construit le dessin (toutes les formes)
  Line ligne( black, Point(4,5), Point(15,22) );  
  ligne.draw( ecran );
  
  LineBrok ligneb( red, Point(20,25), Point(30,30), Point(27,15) );  
  ligneb.draw( ecran );
  
//  Rectangle rect( green, Point(10,10), Point(20,20) );  
  Rectangle rect( green, Point(20,20), Point(10,10) );  
  rect.draw( ecran );
  
  Circle cercle( blue, Point(40,30), 5 ); 
  cercle.draw( ecran );  // n'affiche pas un cercle, car manque algo de dessin dans Screen
  
//  Triangle triangle( black, Point(15,15), Point(25,25), Point(5,40) );
//  triangle.draw( ecran );
  
//  Square carre( blue, Point(35,35), 5 );  
//  carre.draw( ecran );

  // affiche le dessin  
  ecran.refresh();

  // rajout d'une forme
  // test d'une saisie de forme grâce aux fonctions dans util.*
  Point sw, ne;
  char col;
  cinRectangle( col, sw, ne );
  Rectangle rect2( col, sw, ne );  
  rect2.draw( ecran );
  
  // affiche le dessin  modifie
  ecran.refresh();

  return EXIT_SUCCESS;
}

