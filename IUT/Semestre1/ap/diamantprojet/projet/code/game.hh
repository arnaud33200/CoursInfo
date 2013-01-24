#ifndef GAME_HH
#define GAME_HH

#include "struct.hh"

/************ jeu principale ***********************/
bool maingame ( SDL_Surface *screen, SDL_Event event, saveconfig &save );

/*********** convertisseur entier vers caractéres *****************/
string converter ( int a );

#endif
