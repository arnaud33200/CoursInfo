// fichier "main.cc"

#include <iostream>
#include "Peinture.h"
#include "Oeuvre.h"

int
main()
{
  Peinture radeau("Theodore Gericault", "Le Radeau de la Meduse", "Romantisme",
		  26, 5, 1819, 10,
		  "Musee du Louvre", 23, 5, 2001);
  // utilise la fonction membre de Peinture
  cout << radeau.toString();
  cout << endl;

  Oeuvre oradeau("Theodore Gericault", "Le Radeau de la Meduse", "Romantisme",
		 26, 5, 1819, 10);
  // utilise la fonction membre de Oeuvre
  cout << oradeau.toString();
  cout << endl;

  Oeuvre *poeuvre;

  // utilise la fonction membre de Oeuvre
  poeuvre = &oradeau;
  cout << poeuvre->toString();
  cout << endl;

  // si pas virtual dans Oeuvre.h,
  // utilise la fonction membre de Oeuvre et non de Peinture
  poeuvre = &radeau;
  cout << poeuvre->toString();
  cout << endl;

  // parcours d'un tableau
  cout << endl << "Parcours d'un tableau de pointeurs" << endl;
  Oeuvre* tab[2];
  tab[0] = &oradeau;
  tab[1] = &radeau;
  for (int i=0 ; i<2 ; i++)
    cout << tab[i]->toString();
  cout << endl;
}

