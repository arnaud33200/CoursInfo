#ifndef CHANGE_HH
#define CHANGE_HH

#include "struct.hh"



/********* changement entre 2 diamants ****************************/
bool changeposition ( board &tab);

/********* decalage diamant vers le bas ***************************/
void decalebas ( board &tab, int i, int j);

/********* decalage lorsque diamants sont supprimés en colone *****/
void decalebascolone ( board &tab, SDL_Surface *screen );

/********* decalage lorsque diamants sont supprimés en ligne ******/
void decalebasligne ( board &tab, SDL_Surface *screen );

/********* echange de valeur entre deux coordonnées ******/
void echangecoordonnee (int *a, int *b);

#endif
