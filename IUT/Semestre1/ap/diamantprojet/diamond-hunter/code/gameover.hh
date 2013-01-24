#ifndef GAMEOVER_HH
#define GAMEOVER_HH

#include "struct.hh"

/********* La partie est abandonnée *************************/
void abandongame (SDL_Surface *screen, SDL_Event event);

/********* Le temps est écoulé ******************************/
void finishgame (SDL_Surface *screen, SDL_Event event);

#endif
