#ifndef ACTION_HH
#define ACTION_HH

#include "action.hh"
#include "image.hh"
#include "struct.hh"

/*************** afficher la grille ***************************/
	// entiére
void affichergrille( board & tab, SDL_Surface *screen );
	// sans grille
void affichesansgrille (board &tab, SDL_Surface *screen);
	// sans solution
void affichersanssoluce (board &tab, SDL_Surface *screen);

/*************** met le jeu en pause ************************/
void gamepause ( board &tab, SDL_Surface *screen );

/*************** animation de la destruction des diamants *****************/
void destructioncolone (board &tab, SDL_Surface *screen);
void destructionligne (board &tab, SDL_Surface *screen);

/*************** verifie et anime un changement ***********************/
bool verifchangement (board &tab, SDL_Surface *screen);

/*************** verifie et anime un combo ***********************/
bool verifcombo (board &tab, SDL_Surface *screen);
void animcombobonus (board &tab, SDL_Surface *screen);


#endif
