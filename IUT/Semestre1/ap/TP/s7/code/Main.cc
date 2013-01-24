
#include <iostream>
#include <cstdlib>
#include "Tableau.h"

using namespace std;


void
afficherMenu()
{
  cout << endl
       << " 0. Sortir" << endl
       << " 1. Saisie d'un tableau quelconque" << endl
       << " 2. Saisie d'un tableau en le triant" << endl
       << "11. Recherche séquentielle d'un élément" << endl
       << "12. Supression d'un élément" << endl
       << "13. Ajout d'un élément" << endl
       << "21. Recherche séquentielle d'un élément dans un tableau trié" << endl
       << "22. Recherche dichotomique d'un élément" << endl
       << "23. Suppression d'un élément dans un tableau trié" << endl
       << "24. Ajout d'un élément dans un tableau trié" << endl
       << endl
       << "Votre choix : ";
}

void
traiterRechercheSeqTrie(int tab[], int taille)
{
	int element, pos;
	
	cout << endl << "Element a rechercher dans le tableau : ";
	cin >> element;
	pos = cherchePosSeqTrie(tab, taille, element);
	if (pos != -1)
		cout << "l'element cherché se trouve a la position : " << pos << endl;
	else
		cout << "element non trouve :( " << endl;
}
	

void
traiterRechercheSeq(int tab[], int taille)
{
  int element, pos;

  cout << endl << "Element a rechercher dans le tableau : ";
  cin >> element;
  pos = cherchePosSeq(tab, taille, element);
  if (pos != -1)
    cout << "L'element " << element << " est à la position " << pos << endl;
  else
    cout << "L'element " << element << " n'est pas present" << endl;
}

void
traiterAjoutNonTrie(int tab[], int & taille, int max)
{
  int element;

  if (taille == max)
    cout << "Impossible : tableau plein" << endl;
  else
    {
      cout << endl << "Element à ajouter dans le tableau : ";
      cin >> element;
      ajouterNonTrie(tab, taille, element);
    }
}

void
traiterRechercheDicho(int tab[], int taille)
{
  int element, pos;

  cout << endl << "Element a rechercher dans le tableau : ";
  cin >> element;
  pos = cherchePosDicho(tab, taille, element);
  if (pos != -1)
    cout << "L'element " << element << " est à la position " << pos << endl;
  else
    cout << "L'element " << element << " n'est pas present" << endl;
}

void
traiterAjoutTrie(int tab[], int & taille, int max)
{
  int element;

  if (taille == max)
    cout << "Impossible : tableau plein" << endl;
  else
    {
      cout << endl << "Element à ajouter dans le tableau trié : ";
      cin >> element;
      ajouterTrie(tab, taille, element);
    }
}

int
main()
{
  const int TAILLEMAX = 100;
  int tabl[TAILLEMAX];
  int taille, choix;

  // Le tableau est vide au début
  taille = 0; 

  do 
    {
      cout << endl << "Contenu du tableau :" << endl;
      afficherTableau(tabl, taille);

      afficherMenu();
      cin >> choix;
      switch (choix)
	{
	case  0 : // sortir
	  break;
	case  1 : // saisie tableau quelconque
	  saisirTableau(tabl, taille, TAILLEMAX);
	  break;
	case  2 : // saisie tableau en le triant
	  saisirTableauTrie(tabl, taille, TAILLEMAX);
	  break;
	case 11 : // recherche seq
	  traiterRechercheSeq(tabl, taille);
	  break;
	case 12 : // suppression
	  supprnontrie(tabl, taille);
	  break;
	case 13 : // ajout
	  traiterAjoutNonTrie(tabl, taille, TAILLEMAX);
	  break;
	case 21 : // recherche seq trié
	  traiterRechercheSeqTrie(tabl, taille);
	  break;
	case 22 : // recherche dicho
	  traiterRechercheDicho(tabl, taille);
	  break;
	case 23 : // suppression trié
	  cout << "A FAIRE" << endl;
	  break;
	case 24 : // ajout trié
	  traiterAjoutTrie(tabl, taille, TAILLEMAX);
	  break;
	default :
	  cout << "Erreur de saisie" << endl;
	  break;
	}
      
    } while (choix != 0);
 
  cout << "Fin de programme" << endl; 

  return EXIT_SUCCESS;
}
