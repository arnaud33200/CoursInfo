/*
##########################################################################
#                                                                        #
#   regroupe toutes les fonctions qui permet de faire des echanges et    #
#  	decalage dans dans la matrice du jeu							     #
#                                                                        #
##########################################################################
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
 * 				(update1: verifi si les 2 diamants sont à coté)
 * 				(update2: verifi si les 2 dimants ne sont pas en diaguonale)
 * 				(update3: les verifs sont mises dans une fonction apart -> verif.cc)
 * 				(update4: revoie un booléen: si l'echange a eu lieu ou pas)
 * 				(update5: adaption a matrice de structure)
 * Description : fait un echange entre deux case du tableau
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
 * Description : fait descendre tout les diamants lorsqu'une case est vide
 * 				 et creer un diamant aleatoire en haut de la grille
 * 				 s'execute : 
 * 								- aprés une verification de colone
 * 								- aprés suppression des diamants : initialiser a 0
 * Entrées : tab[][], les coordonnée de la premiere case : fi et fj, et de la deuxieme case : si et sj
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
 * Description : fait descendre tout les diamants lorsqu'une case est vide
 * 				 et creer un diamant aleatoire en haut de la grille
 * 				 s'execute : 
 * 								- aprés une verification de ligne
 * 								- aprés suppression des diamants : initialiser a 0
 * Entrées : tab[][], les coordonnée de la premiere case : fi et fj, et de la deuxieme case : si et sj
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
 * 				 (update1: verifi si 3 diamants sont pas aligné aleatoire)
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
 * Entrées : deux adresses d'entier
 * Sorties : rien
************************************************************/
void echangecoordonnee (int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
