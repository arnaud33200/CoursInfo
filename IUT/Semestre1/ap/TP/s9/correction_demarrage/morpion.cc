#include <iostream>
#include "morpion.h" // inclusion du fichier en-tete

using namespace std;

/*****************************************/
/* Remarque : la constante TAILLE est    */
/* déclarée dans le fichier en-tête      */
/* morpion.h   Elle est donc connue dans */
/* tout le fichier                       */
/* (grâce au include "morpion.h")        */
/* c'est une constante globale           */
/*****************************************/




/****************************************/
/* Action d'initialisation de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/
void initGrille(TGrille grille)
{
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[i][j] = 0;
}



/****************************************/
/* Action d'affichage de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/
void afficherGrille(TGrille grille)
{
  cout << endl << "----+---+----" << endl;
  for (int i = 0 ; i < TAILLE ; i++)
    {
      cout << "|";
      for (int j = 0 ; j < TAILLE ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 0 : cout << "   "; break;
	    case 1 : cout << " X "; break;
	    case 2 : cout << " O "; break;
	    default : cout << "***";
	    }
	  cout << "|";
	}

      cout << endl << "----+---+----" << endl;
    }

}
