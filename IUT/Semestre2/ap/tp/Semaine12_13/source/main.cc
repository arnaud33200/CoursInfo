///////////////////////////////////////////////////////////////////////////////
// main.cc
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;


int main()
{
  Liste<Etudiant> liste;
  fic2liste("liste1", liste);
	liste2fic("listenew", liste);
  
  return EXIT_SUCCESS;
}

