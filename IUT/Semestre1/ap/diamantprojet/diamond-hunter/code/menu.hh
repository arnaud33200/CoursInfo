#ifndef MENU_HH
#define MENU_HH

#include "struct.hh"


/******************** Menu de démarrage ************************/
bool menugame ( SDL_Surface *screen, SDL_Event event, saveconfig &save );

/******************** Menu options de jeu ***********************/
void menuoption ( SDL_Surface *screen, SDL_Event event, saveconfig &save );

/******************** Menu introduction du jeu *****************/
void menuintro ( SDL_Surface *screen, SDL_Event event );

#endif
