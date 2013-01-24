#ifndef ACTION_HH
#define ACTION_HH

#include "action.hh"
#include "image.hh"
#include "struct.hh"

/*************** Affiche la grille ***************************/
	// Entiére.
void affichergrille( board & tab, SDL_Surface *screen );
	// Sans grille.
void affichesansgrille (board &tab, SDL_Surface *screen);
	// Sans solution.
void affichersanssoluce (board &tab, SDL_Surface *screen);

/*************** Met le jeu en pause ************************/
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
