#include <iostream>
#include "morpion.h"  // Inclusion des d�finitions sur le morpion

using namespace std;

int main()
{
  TGrille grille; // D�claration de ma gille de morpion
  initGrille(grille);
  afficherGrille(grille);
}
