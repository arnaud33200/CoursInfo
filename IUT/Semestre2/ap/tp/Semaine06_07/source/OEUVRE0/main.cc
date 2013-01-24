// fichier "main.cc"

#include <iostream>
#include "Peinture.h"

using namespace std;

int
main()
{
  Peinture radeau("Theodore Gericault", "Le Radeau de la Meduse", "Romantisme",
		  26, 5, 1819, 10,
		  "Musee du Louvre", 23, 5, 2001);
  cout << endl;
  // utilise la fonction membre de Peinture
  cout << radeau.info();
  cout << endl;

  // utilise la fonction membre heritee de Oeuvre
  cout << radeau.toString();
  cout << endl;
}

