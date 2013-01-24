/*
########################################################################
#                                                                      #
#   Regroupe toutes les fonctions qui permettent de faire des echanges #
#   et                                                                 #
#  	des decalages dans dans la matrice du jeu.					       #
#                                                                      #
#########################################################################
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"

#include "change.hh"
#include "verif.hh"
#include "struct.hh"
#include "action.hh"

using namespace std;



/************************************************************
 * Nom fonction : changeposition
 * Nom / Date : aladouce, 20/11/2010, v6
 * 				(update1: verifie si les 2 diamants sont à coté)
 * 				(update2: verifie si les 2 diamants ne sont pas en diagonale)
 * 				(update3: les verifs sont mises dans une fonction apart -> verif.cc)
 * 				(update4: renvoie un booléen: si l'echange a eu lieu ou non)
 * 				(update5: adaption a matrice de structure)
 * Description : fait un echange entre deux cases du tableau
 * Entrées : board tab
 * Sorties : board tab
************************************************************/
bool 
changeposition ( board & tab)
{
	if ( acote(tab) )	// verifie si deux case sont a coté
	{
		tab.matrice[tab.fi][tab.fj].color=(tab.matrice[tab.fi][tab.fj].color)+(tab.matrice[tab.li][tab.lj].color);
		tab.matrice[tab.li][tab.lj].color = (tab.matrice[tab.fi][tab.fj].color) - (tab.matrice[tab.li][tab.lj].color);
		tab.matrice[tab.fi][tab.fj].color = (tab.matrice[tab.fi][tab.fj].color) - (tab.matrice[tab.li][tab.lj].color);
		return 1;
	}
	else
	{
		return 0;
	}
}


/************************************************************
 * Nom fonction : decalebascolone
 * Nom / Date : aladouce, 23/11/2010, v1
 * Description : fait descendre tous les diamants lorsqu'une case est vide
 * 				 et créé un diamant aleatoire en haut de la grille
 * 				 s'éxécute : 
 * 								- aprés une verification de colone
 * 								- aprés une suppression de diamants : initialisé a 0
 * Entrées : tab[][], les coordonnées de la premiere case : fi et fj, et de la deuxieme case : si et sj
 * Sorties : tab [][]
************************************************************/
void 
decalebascolone ( board &tab, SDL_Surface *screen )
{
	for (int i=tab.fi; i<=tab.li; i++)
	{
		SDL_Delay(65); // delay de temps entre les animations
		decalebas(tab, i, tab.fj);
		affichergrille(tab,screen);
	}
}


/************************************************************
 * Nom fonction : decalebasligne
 * Nom / Date : aladouce, 23/11/2010, v1
 * Description : Génère la descente de tous les diamants lorsqu'une case est vide
 * 				 et créé un diamant aleatoire en haut de la grille
 * 				 s'éxécute : 
 * 								- aprés une vérification de ligne
 * 								- aprés une suppression de diamants : initialisé a 0
 * Entrées : tab[][], les coordonnées de la premiere case : fi et fj, et de la deuxieme case : si et sj
 * Sorties : tab [][]
************************************************************/
void 
decalebasligne ( board &tab, SDL_Surface *screen )
{
		for (int i=tab.fj; i<=tab.lj; i++)
		{
			decalebas(tab, tab.fi, i);	
		}
		SDL_Delay(65);  // delay de temps entre les animations
		affichergrille(tab,screen);
}


/************************************************************
 * Nom fonction : decalebas
 * Nom / Date : aladouce, 23/11/2010, v3
 * Description : fait descendre tous les diamants vers le bas
 * 				 et ajoute un diamant aleatoire en haut 
 * 				 (update1: verifie si 3 diamants sont pas alignés aleatoirement)
 * 				 (update2: prise en compte de NB_SIZE, cf const.hh)
 * Entrées : une grille : tab, un entier i et un entier j
 * Sorties : tab [][]
************************************************************/
void
decalebas ( board &tab, int i, int j)
{

	for ( i=i; i>0; i--)
		tab.matrice[i][j].color=tab.matrice[i-1][j].color;
	do
	tab.matrice[0][j].color=tab.matrice[i][j].color=rand()%(tab.NB_SIZE) + 1;
	while ( tab.matrice[0][j].color == tab.matrice[2][j].color || tab.matrice[0][j].color == tab.matrice[0][j+2].color );
	
}

/************************************************************
 * Nom fonction : echange coordonnée
 * Nom / Date : aladouce, 10/12/2010, v1
 * Description : fait un echange entre deux valeurs
 * Entrées : deux adresses d'entiers
 * Sorties : rien
************************************************************/
void echangecoordonnee (int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
