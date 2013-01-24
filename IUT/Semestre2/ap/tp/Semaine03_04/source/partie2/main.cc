// Fichier main.cc

#include <iostream>
#include "Cercle.h"
#include "Point.h"

using namespace std;

int
main()
{
  // test de tous les constructeurs
  Cercle c0 ;
  	/// construit le Point pui
  cout << c0 << endl ;
  
	cout << endl;
  Cercle c1( 4 ) ;
  cout << c1 << endl ;

	cout << endl;
  Cercle c2( 2, 3.5, 8.2 ) ;
  cout << c2 << endl ;

	cout << endl;
  Point p( 6, 7.5 );
  Cercle c3( 2, p ) ;
  cout << c3 << endl ;

  // test du constructeur par copie fourni par defaut (que remarquez-vous ??)
  // puis du votre quand vous l'aurez ecrit...
  cout << endl;
  Cercle c4 = c3;
  	
  cout << c4 << endl ;
  
  // tout est desalloue ! verifiez les affichages...
}

/*
Point::Constructeur par defaut
Cercle::Constructeur par defaut
centre : (0,0)
rayon :  0
Point::Constructeur par defaut
Cercle::Constructeur rayon 
centre : (0,0)
rayon :  4
Point::Constructeur par defaut
Cercle::Constructeur rayon + x + y 
centre : (3.5,8.2)
rayon :  2
Point::Constructeur : 6 , 7.5
Point::Constructeur par defaut
Cercle::Constructeur rayon + point 
Point::Operateur affectation
centre : (6,7.5)
rayon :  2
Point::Constructeur par copie
centre : (6,7.5)
rayon :  2
Cercle::Destructeur
Point::Destructeur
Cercle::Destructeur
Point::Destructeur
Point::Destructeur
Cercle::Destructeur
Point::Destructeur
Cercle::Destructeur
Point::Destructeur
Cercle::Destructeur
Point::Destructeur
*/
