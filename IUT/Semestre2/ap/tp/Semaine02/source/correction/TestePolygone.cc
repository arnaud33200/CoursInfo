#include <iostream>
#include "Point.h"
#include "Polygone.h"

int
main()
{
  // Cree un polygone et le remplit
  cout << "==> Definition p" << endl;
  Polygone p;
  p.ajoutSommet( Point( 1.0, 0.0 ) );
  p.ajoutSommet( Point( 0.5, 0.8 ) );
  p.ajoutSommet( Point( -0.2, 0.6 ) );

  // Affiche un de ses points
  // ? Grace a quelle methode ?
  cout << "A l'indice 2 : " << p.getPoint(2) << endl;
  
  // Un autre polygone : création par copie
  cout << "==> Definition p2" << endl;
  Polygone p2 = p;
  
  // un autre polygone : création par défaut puis affectation
  cout << "==> Definition p3" << endl;
  Polygone p3;
  p3 = p;

  // Affiche le polygone et son translate
  // ? Grace a quelle methode ?
  cout << "p3 Orig    :" << endl << p3 << endl;
  p3.deplace( 0.3, 0.2 );
  cout << "p3 Deplace :" << endl << p3 << endl;

  // Affiche le polygone p de départ
  cout << "p  Debut   :" << endl << p << endl;

  return 0;
}

/*
==> Definition p
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Polygone::Constructeur par defaut
Point::Constructeur : 1 , 0
Point::Operateur affectation
Point::Destructeur
Point::Constructeur : 0.5 , 0.8
Point::Operateur affectation
Point::Destructeur
Point::Constructeur : -0.2 , 0.6
Point::Operateur affectation
Point::Destructeur
A l'indice 2 : (-0.2,0.6)
==> Definition p2
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Polygone::Constructeur par copie
Point::Operateur affectation
Point::Operateur affectation
Point::Operateur affectation
==> Definition p3
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Point::Constructeur par defaut
Polygone::Constructeur par defaut
Polygone::Operateur affectation
Point::Operateur affectation
Point::Operateur affectation
Point::Operateur affectation
p3 Orig    :
(1,0)
(0.5,0.8)
(-0.2,0.6)

p3 Deplace :
(1.3,0.2)
(0.8,1)
(0.1,0.8)

p  Debut   :
(1,0)
(0.5,0.8)
(-0.2,0.6)

Polygone::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Polygone::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Polygone::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
Point::Destructeur
*/
