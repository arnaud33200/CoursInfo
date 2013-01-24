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

  // Sauvegarde et lecture depuis fichier
  p.ecritFichier("sauvePoly.txt");
  cout << "==> Definition pfic" << endl;
  Polygone pfic;
  pfic.litFichier("sauvePoly.txt");

  cout << "p ecrit :" << endl << p << endl;
  cout << "pfic lu   :" << endl << pfic << endl;

  return 0;
}
