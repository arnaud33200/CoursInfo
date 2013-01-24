//~ fonction.hh

#ifndef INIT_HH
#define INIT_HH

#include<iostream>

#include "const.hh"


// COLLER SURFACE

void pastesurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip);


// ALEATOIRE

int randomvar();


// INITIALISER TAB

void initg ( int tab[][G_SIZE] );

void viewtab (int tab[][G_SIZE] );

#endif
