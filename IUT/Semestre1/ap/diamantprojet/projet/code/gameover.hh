#ifndef GAMEOVER_HH
#define GAMEOVER_HH

#include "struct.hh"

/********* la partie est abandonnée *************************/
void abandongame (SDL_Surface *screen, SDL_Event event);

/********* le temps est écoulé ******************************/
void finishgame (SDL_Surface *screen, SDL_Event event);

#endif
