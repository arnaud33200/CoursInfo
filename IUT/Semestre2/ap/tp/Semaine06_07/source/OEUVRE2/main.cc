// fichier "main.cc"

#include <iostream>
#include "Peinture.h"
#include "Plastique.h"

using namespace std;

int
main()
{
  Peinture radeau("Theodore Gericault", "Le Radeau de la Meduse", "Romantisme",
		  			26, 5, 1819, 10,
		  			"Musee du Louvre", 23, 5, 2001, "toile", "aquarelle");
	Plastique jesus("micheal angelo", "jesus gangsta back !", "rastastyle", 12, 01, 1534, 19, 
					"jean pierre", 21, 03, 1536, "porcelaine");
		  			
  // utilise la fonction membre de Peinture
  cout << radeau.toString();
  cout << endl;
}

