#ifndef MENU_HH
#define MENU_HH

#include "struct.hh"


/******************** menu de demarrage ************************/
bool menugame ( SDL_Surface *screen, SDL_Event event, saveconfig &save );

/******************** menu option du jeu ***********************/
void menuoption ( SDL_Surface *screen, SDL_Event event, saveconfig &save );

/******************** menu introduction du jeu *****************/
void menuintro ( SDL_Surface *screen, SDL_Event event );

#endif
