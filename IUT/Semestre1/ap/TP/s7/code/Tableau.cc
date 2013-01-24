// Tableau.cc

#include<iostream>
#include "Tableau.h"

using namespace std;


/**********************************************
 FONCTIONS DE SAISIES ET AFFICHAGES
 **********************************************/

// Fonction "locale" utilisée pour les saisies
// Force la saisie d'un entier entre 1 et n
int
nombreValide(int n)
{
  int i;

  do {
    cin >> i;
  }while (i < 1 || i > n);

  return i;
}

// Permet de saisir un tableau quelconque (taille et éléments)
void
saisirTableau(int tab[], int & taille, int max)
{
  int i;

  cout << "Hey mec ! entres la taille (entre 1 et " << max << ") :" << endl;
  taille = nombreValide(max);

  cout << "Entrez les éléments :" << endl;
  for( i = 0 ; i < taille ; i++ )
    cin >> tab[i];
}

// Permet de saisir un tableau (taille et éléments) en le triant
void
saisirTableauTrie(int tab[], int & taille, int max)
{
  int i=0, val;

  cout << "Entrez la taille (entre 1 et " << max << ") :" << endl;
  taille = nombreValide(max);

  cout << "Entrez les éléments :" << endl;
  while( i < taille )
  {
    cin >> val;
    ajouterTrie(tab, i, val);
   // taille++;
  }
}

// Permet d'afficher les éléments d'un tableau
void
afficherTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++)
    cout << tab[i] << " ";
  cout << endl;
}


/**********************************************
 FONCTIONS DE RECHERCHE (POSITION ELEM)
 **********************************************/

// NON TRIE
// Recherche séquentielle
// Retourne la position de elem dans tab, -1 si elem est absent
int
cherchePosSeq(int tab[], int taille, int elem)
{
  int pos = 0;
  bool trouve = false;
  
  while (!trouve && pos < taille)
    if (elem == tab[pos])
      trouve = true;
    else
      pos++;
  
  if (!trouve)
    pos = -1;
 
  return pos;
}

// TRIE
// Recherche dichotomique
// Retourne la position de elem dans tab, -1 si elem est absent
int
cherchePosDicho(int tab[], int taille, int elem)
{
  int gauche, droite, milieu;
  bool trouve;
  
  gauche = 0;
  droite = taille-1;
  trouve = false;

  while (!trouve && gauche <= droite)
    {
      milieu = (gauche + droite) / 2;
      if (elem == tab[milieu])
	trouve = true;
      else
       	if (elem < tab[milieu])
	  droite = milieu + 1;
	else
	  gauche = milieu - 1;
    }
    
  if (!trouve)
    milieu = -1;
  
  return milieu;
}


int
cherchePosSeqTrie (int tab[], int taille, int a)
{
	bool find=0, end=0;
	int i=0;
	while (end!=1 && find!=1 )
	{
		if (tab[i] == a)
			find = 1;
		else if ( tab[i] > a )
			end = 1;
		else
			i++;
	}
	if ( find!=1 )
		return -1;
	else 
		return i;
	
}

/**********************************************
 FONCTIONS DE SUPPRESSION
 **********************************************/

void
supprnontrie(int tab[], int &taille)
{
	int element;
	int i;
	cout << "quel element voulez vous supprimé ?" << endl;
	cin >> element;
	i=cherchePosSeq(tab,taille,element);
	if (i != -1)
	{
		tab[i]=tab[taille-1];
		taille-=1;
	}
	else
		cout << "non trouvé" << endl;
}	

/**********************************************
 FONCTIONS D'AJOUT
 **********************************************/

// NON TRIE
// Ajout d'un élément dans un tableau non trié
// suppose que le tableau n'est pas plein
void
ajouterNonTrie(int tab[], int & taille, int elem)
{
  tab[taille] = elem;
  taille++;
}


// Fonction "locale" utilisée par ajouterTrie
// Retourne la position à laquelle Elem peut être ajouté dans tab
// (basée sur une recherche séquentielle)
int
cherchePosAjout(int tab[], int taille, int elem)
{
  int pos = 0;
  bool trouve = false;

  while (!trouve && pos < taille)
    if (elem <= tab[pos])
      trouve = true;
 	  else
      pos++;
  
  return pos;
}

// Fonction "locale" utilisée par ajouterTrie
// Décale vers la droite tous les éléments de tab à partir de la position indice
void
decalageDroite(int tab[], int & taille, int indice)
{
  int i;

  for (i = taille ; i >= indice ; i--)
    tab[i] = tab[i-1];
      
  taille++;
}


// TRIE
// Ajout d'un élément dans un tableau trié
// suppose que le tableau n'est pas plein
void
ajouterTrie(int tab[], int & taille, int elem)
{
  int pos;
  pos = cherchePosAjout(tab, taille, elem);
  decalageDroite(tab, taille, pos);
  tab[pos] = elem;
}


		
	
	
	
	
