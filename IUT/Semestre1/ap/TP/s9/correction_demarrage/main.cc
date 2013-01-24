#include <iostream>
#include "morpion.h"  // Inclusion des définitions sur le morpion

using namespace std;

int main()
{
  TGrille grille; // Déclaration de ma gille de morpion
  initGrille(grille);
  afficherGrille(grille);
}
