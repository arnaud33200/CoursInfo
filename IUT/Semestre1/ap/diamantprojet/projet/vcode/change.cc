#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"

#include "change.hh"
#include "const.hh"

using namespace std;


/************************************************************
 * Nom fonction : changeposition
 * Nom / Date : aladouce, 20/11/2010
 * Description : fait un echange entre deux case du tableau
 * Entrées : tab[][], les coordonnée de la premiere case : fi et fj, et de la deuxieme case : si et sj
 * Sorties : tab [][]
************************************************************/
void 
changeposition ( int tab[G_SIZE][G_SIZE], int fi, int fj, int si, int sj )
{
	tab[fi][fj]=tab[fi][fj]+tab[si][sj];
	tab[si][sj]=tab[fi][fj]-tab[si][sj];
	tab[fi][fj]=tab[fi][fj]-tab[si][sj];
}


