#ifndef CHANGE_HH
#define CHANGE_HH

#include "struct.hh"



/********* Changement entre 2 diamants ****************************/
bool changeposition ( board &tab);

/********* Décalage diamant vers le bas ***************************/
void decalebas ( board &tab, int i, int j);

/********* Décalage lorsque des diamants sont supprimés en colonne *****/
void decalebascolone ( board &tab, SDL_Surface *screen );

/********* Décalage lorsque des diamants sont supprimés en ligne ******/
void decalebasligne ( board &tab, SDL_Surface *screen );

/********* Echange de valeurs entre deux coordonnées ******/
void echangecoordonnee (int *a, int *b);

#endif
