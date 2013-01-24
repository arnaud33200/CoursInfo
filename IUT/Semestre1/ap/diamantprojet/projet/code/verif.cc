/*
##########################################################################
#                                                                        #
#   regroupe les fonctions utilisées pour effectuer les diverses         #
#   vérification de la grille du jeu et des actions effectuées par       #
#   le joueur.                                                           #
#                                                                        #
##########################################################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <fstream>

#include "verif.hh"
#include "change.hh"
#include "struct.hh"

using namespace std;


/************************************************************
 * Nom fonction : Solution Colonne.
 * Nom / Date : YGORRA Virgile 2.0 	/ 23/11/2010
 * Description : La fonction vérifie si trois diamants succesif ou plus sont alignés verticalement
 * 				 si oui: modification des coordonnées du premier et du dernier diamant alignés et retourne 1
 * 				 sinon retourne 0.
 * Entrées : board tab
 * Sorties : board tab
 ************************************************************/
bool solutionligne(board &tab)
{
	int i,cpt, tmp=0;	
	bool generale=0;
  
  // verifie l'ordre des coordonnées reçut des cases echangées
  // de maniére que que la lecture de la grille se fasse dans le bon ordre
	if ( tab.fi > tab.li )
		echangecoordonnee(&tab.fi, &tab.li);
  
	i=tab.fi;	
  
	while(i<=tab.li && !generale && i<tab.G_SIZE) // parcour seulement les lignes concerné
    {
		cpt=1;
		for(int j=0; j<tab.G_SIZE-1; j++) // parcour toutes les colones
		{
			if(tab.matrice[i][j].color == tab.matrice[i][j+1].color)
			{
				cpt++;
				if(cpt==3)  // si 3 diamants alignés
				{
					tab.fj=j-1;
					tab.fi=i;
					tab.li=i;
					tab.lj=j+cpt-2;
					generale=1;
					tmp=3;
				}
				else if (cpt>3)  // si plus de 3 diamants alignés
				{
				tab.lj=tab.lj+1;
				tmp++;
				}
			}
			else
				cpt=1;  
		}
		
		i++;
    }
	tab.score+=tmp;
// gestion des gains de temps en fonction du niveau
	if (tab.G_SIZE == 7)
		tab.TIMEGAME+=1;
	else if (tab.G_SIZE == 6 )
		tab.TIMEGAME+=tmp;
  return generale;
  
  
}

/************************************************************
 * Nom fonction : Solution Colonne.
 * Nom / Date : YGORRA Virgile 2.0 	/ 23/11/2010
 * Description : La fonction vérifie si trois diamants succesif ou plus sont alignés horizontallement
 * 				 si oui: modification des coordonnées du premier et du dernier diamant alignés et retourne 1
 * 				 sinon retourne 0.
 * Entrées : board tab
 * Sorties : board tab
 ************************************************************/

bool solutioncolone(board &tab)
{
  
	int j,cpt, tmp=0;
	bool generale=0;
  
  // verifie l'ordre des coordonnées reçut des cases echangées
  // de maniére que que la lecture de la grille se fasse dans le bon ordre
	if ( tab.fj > tab.lj )
		echangecoordonnee(&tab.fj, &tab.lj);
  
	j=tab.fj;
  
	while(j<=tab.lj && !generale && j<tab.G_SIZE) // parcours seulement les deux colones concernées
    {
		cpt=1;
		for(int i=0; i<tab.G_SIZE-1; i++)
		{
			if(tab.matrice[i][j].color == tab.matrice[i+1][j].color)
			{
				cpt++;
				if(cpt==3) // si trois diamant sont alignés
				{
					tab.fj=j;
					tab.fi=i-1;
					tab.li=i+cpt-2;
					tab.lj=j;
					generale=1;
					tmp=3;
				}
				else if (cpt>3) // si plus de 3 diamants sont alignés
				{
					tab.li=tab.li+1;
					tmp++;
				}
			}
			else
			{
				cpt=1;
			}
		} 
		j++;
    } 
	tab.score+=tmp;
	if (tab.G_SIZE == 7)
		tab.TIMEGAME+=1;
	else if (tab.G_SIZE == 6 )
		tab.TIMEGAME+=tmp;
	return generale;
}


/************************************************************
 * Nom fonction : acote
 * Nom / Date : aladouce, 26/11/2010, V3
 * Description : verifie si deux diamants sont cote à cote
 * 				 mais non par la diaguonale
 * 				 si oui : returné 1
 * 				 sinon : retourné 0
 * 				(update1: les deux diamants ont la même position: retourner 0)
 * 				(update2: verifie si un diamant n'est pas hors de la grille )
 * Entrées : premier i : fi; premier j: fi; second i: si; second j: sj
 * Sorties : un booléen
 ************************************************************/
bool acote (board &tab)
{
  //**************** diamants hors grille? *******************/
	if (tab.fi<0 || tab.fj<0 || tab.li<0 || tab.li<0 || tab.lj<0 )
		return 0;	
	if (tab.fi>tab.G_SIZE-1 || tab.fj>tab.G_SIZE-1 || tab.li>tab.G_SIZE-1 || tab.lj>tab.G_SIZE-1 )
		return 0;
   
  //**************** diamantd cote a cote ? ******************/
	if ( (tab.li==tab.fi-1 &&  tab.lj==tab.fj) || (tab.li==tab.fi+1 && tab.lj==tab.fj) || (tab.lj==tab.fj-1 && tab.li==tab.fi) || (tab.lj==tab.fj+1 && tab.li==tab.fi) )
		return 1;
	else if ( tab.li==tab.fi && tab.lj==tab.fj )
		return 0;
	else
      return 0;
}



/************************************************************
 * Nom fonction : verifgenerale.
 * Nom / Date : Virgile YGORRA, 14/12/2010 1.5.
 * Description : verifie si il existe encore des solutions pour aligner trois
 * 				 diamants verticalement ou horizontalement. Cette fonction retourne 0 s'il
 * 				 n'y a pas de solution, et 1 s'il y a une ou plusieurs solutions. De plus,
 * 				 elle envoie les coordonnées du diamant à changer dans li et lj.
 * Entrées : board & tab.
 * Sorties : Un booléen: solution.
 ************************************************************/
bool verifgenerale(board & tab) 
{
	int l, c, cpt;
	bool solution = false;
  
	l = 0;
	cpt = 1;
  
	while (!solution && l < tab.G_SIZE) 
    {
		for (c = 0; c < tab.G_SIZE; c++) 
		{
			// Test si deux diamants sont alignés horyzontalement.
			if (tab.matrice[l][c].color == tab.matrice[l][c + 1].color) 
            { 
				if (tab.matrice[l][c].color == tab.matrice[l][c + 3].color && c < tab.G_SIZE - 3) 
                {
					// Diamant situé à droite.
					tab.lj = c + 3;
					tab.li = l;
					solution = true;	  
				}
				else if (tab.matrice[l][c].color == tab.matrice[l + 1][c + 2].color && l < tab.G_SIZE - 1 && c < tab.G_SIZE - 2) 
                {
					// Diamant situé en bas à droite.
					tab.lj = c + 2;
					tab.li = l + 1;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l - 1][c + 2].color && l > 0 && c < tab.G_SIZE - 2) 
                {
					// Diamant situé en haut à droite.
					tab.lj = c + 2;
					tab.li = l - 1;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l - 1][c - 1].color && c < tab.G_SIZE - 1 && l > 0 && c > 0) 
                {
					// Diamant situé en haut à gauche.
					tab.lj = c - 1;
					tab.li = l - 1;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l][c - 2].color && l > 0 && c < tab.G_SIZE - 1 && c > 1) 
                {
					// Diamant situé à gauche.
					tab.lj = c - 2;
					tab.li = l;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l + 1][c - 1].color && c < tab.G_SIZE - 1 && l < tab.G_SIZE - 1)
                {
					tab.lj = c - 1;
					tab.li = l + 1;
					solution = true;
					// Diamant situé en bas à gauche.
                }
            } // Fin du premier if (Test).
        } // Fin de la boucle for.
      l++;
    } // Fin de la boucle while.

 /// Le code précedent cherchait les solutions si deux diamants de même couleur étaient alignés
 /// Maintenant, il faut chercher les solutions si deux diamants de même couleur sont espacés par
 /// un diamant d'une couleur différente.
  
	while (!solution && l < tab.G_SIZE) 
    {
		for (c = 0; c < tab.G_SIZE; c++) 
        {
			if (tab.matrice[l][c].color == tab.matrice[l][c + 2].color)
			{
				if (tab.matrice[l][c].color == tab.matrice[l - 1][c + 1].color && l > 0 && c < tab.G_SIZE - 2 && c >= 0 && l < tab.G_SIZE) 
                {
					// Diamant situé milieu haut.
					tab.lj = c + 1;
					tab.li = l - 1;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l + 1][c + 1].color && l < tab.G_SIZE - 2 && c < tab.G_SIZE - 2 && c >= 0 && l >= 0) 
                {
					// Diamant situé milieu bas.
					tab.lj = c + 1;
					tab.li = l + 1;
					solution = true;  
                }
            } // Fin du if (Test).
        } // Fin de la boucle for.
      l++;
    } // Fin de la boucle while.
  
/// On a donc vérifié toutes les solutions horyzontales possibles. Si une solution horyzontale
/// n'est pas trouvée, il faut alors chercher les solutions verticales. */
  
  c = 0; // On réinitialise c à 0, étant donné qu'il a gardé la valeur de la solution précédente.
  
	while (!solution && c < tab.G_SIZE) 
    {
      
		for (l = 0; l < tab.G_SIZE; l++) 
        {
			if (tab.matrice[l][c].color == tab.matrice[l + 1][c].color) 
            { 
				// Test si deux diamants sont alignés verticalement.
				if (tab.matrice[l][c].color == tab.matrice[l + 3][c].color && l < tab.G_SIZE - 3) 
                {
					// Diamant situé en bas.
					tab.lj = c;
					tab.li = l + 3;
					solution = true;
                }
				else if (tab.matrice[l][c].color == tab.matrice[l + 2][c + 1].color && c < tab.G_SIZE - 1 && l < tab.G_SIZE - 2)
                {
					// Diamant situé  en bas à droite.
					tab.lj = c + 1;
					tab.li = l + 2;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l + 2][c - 1].color && c > 0 && l < tab.G_SIZE - 1) 
                {
					// Diamant situé en bas à gauche.
					tab.lj = c - 1;
					tab.li = l + 2;
					solution = true;
                }
				else if (tab.matrice[l][c].color == tab.matrice[l - 1][c - 1].color && c > 0 && l > 0)
                {
					// Diamant situé en haut à gauche.
					tab.lj = c - 1;
					tab.li = l - 1;
					solution = true;
                } 
				else if (l > 1 && tab.matrice[l][c].color == tab.matrice[l - 2][c].color)
                {
					// Diamant situé en haut.
					tab.lj = c;
					tab.li = l - 2;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l - 1][c + 1].color && c < tab.G_SIZE - 1 && l > 0) 
                {
					// Diamant situé en haut à droite.
					tab.lj = c + 1;
					tab.li = l - 1;
					solution = true;
                }
            } // Fin du if (Test).
        } // Fin de la boucle for.
      c++;
    } // Fin de la boucle while.


/// Le code précédent cherchait les solutions horyzontales lorsque deux diamants de même couleur
/// étaient alignés. S'il n'y pas de solution, il faut vérifier s'il existe une solution telle que
/// deux diamants de même couleurs soient espacés d'un diamant d'une couleur différente. 
  
	while (!solution && c < tab.G_SIZE) 
    {
		for (l = 0; l < tab.G_SIZE; l++) 
        {
			if (tab.matrice[l][c].color == tab.matrice[l + 2][c].color) 
            {
				if (tab.matrice[l][c].color == tab.matrice[l + 1][c - 1].color && c > 0 && l < tab.G_SIZE - 2)
                {
					// Diamant situé milieu gauche.
					tab.lj = c - 1;
					tab.li = l + 1;
					solution = true;
                } 
				else if (tab.matrice[l][c].color == tab.matrice[l + 1][c + 1].color && l < tab.G_SIZE - 1 && c < tab.G_SIZE - 1) 
                {
					// Diamant situé milieu droit.
					tab.lj = c + 1;
					tab.li = l + 1;
					solution = true;
                }
            } // Fin du if (Test).
        } // Fin de la boucle for.
      c++;
    } // Fin de la boucle while.
  
  return solution;
}


/************************************************************
 * Nom fonction : good mouse
 * Nom / Date : aladouce, 2/03/2011, v1
 * Description : vérifie que la sourie ne soit pas hors de la grille 
 * 				 quand le joueur effectue une action
 * Entrées : board tab + deux entier x et y
 * Sorties : un booléen
************************************************************/
bool goodmouse (board tab, int x, int y)
{
	int size = ( 60 * tab.G_SIZE + tab.midleadd );

	if ( x < size && x > tab.midleadd )
	{
		if ( y < size && y > tab.midleadd )
			return 1;
	}
	
	else
		return 0;
}



