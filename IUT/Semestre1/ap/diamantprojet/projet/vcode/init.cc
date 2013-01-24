#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"

#include "init.hh"
#include "const.hh"

using namespace std;


/************************************************************
 * Nom fonction :
 * Nom / Date : ( + version)
 * Description : (que fait la fonct)
 * Entrées :
 * Sorties :
************************************************************/





/************************************************************
 * Nom fonction : initg
 * Nom / Date : aladouce , 16/11/2010 , v1
 * Description : initialise la grille du jeu
 * Entrées : int tab[][G_SIZE]
 * Sorties : rien
************************************************************/
void initg ( int tab[][G_SIZE] )
{
	srand(time(NULL));
	for ( int i=0; i < G_SIZE; i++ ) 
		for ( int j=0; j < G_SIZE; j++ )
			tab[i][j]=rand()%(G_SIZE) + 1;  // fonction base aleatoire	
}


/************************************************************
 * Nom fonction : viewtab
 * Nom / Date : aladouce , 16/11/2010 , v1
 * Description : affiche la grille sur la console
 * Entrées : int tab[][G_SIZE]
 * Sorties : rien
************************************************************/
void viewtab ( int tab[][G_SIZE] )
{
	for ( int i=0; i<G_SIZE; i++ )
	{
		for (int j=0; j<G_SIZE; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

