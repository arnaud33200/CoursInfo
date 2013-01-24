/*
##########################################################################
#                                                                        #
#   regroupe les fonctions qui permettent de gérer l'interface des       #
#	deux type de fin de jeu.    										 #
#                                                                        #
##########################################################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

#include "gameover.hh"
#include "image.hh"




/************************************************************
 * Nom fonction : finish game
 * Nom / Date : aladouce, 19/12/2010, v1
 * Description : affiche la fenetre de fin de jeu aprés abandon
 * Entrées : SDL_Surface screen et SDL_Event event
 * Sorties : rien
************************************************************/
void abandongame (SDL_Surface *screen, SDL_Event event)
{
	SDL_Surface *wallpaper = loadimage("ressources/giveupend.bmp");
	SDL_Surface *icon = loadimage("ressources/icon.bmp");
	bool quit=0;
	cout << "partie abandonné !!! " << endl;
	
	SDL_WM_SetCaption("DIAMANT  (party given up !!!)", NULL);  
	SDL_WM_SetIcon(icon, NULL);
	
	while (!quit)
	{
		SDL_Delay(32);
		pastesurface(0,0,wallpaper,screen,NULL);
		SDL_Flip(screen);
		
		while ( SDL_PollEvent(&event))
		{
			if ( event.type == SDL_QUIT )
				quit=1;
				
			else if ( event.type == SDL_MOUSEBUTTONDOWN )
				quit=1;
		}
	}
}



/************************************************************
 * Nom fonction : finish game
 * Nom / Date : aladouce, 19/12/2010, v1
 * Description : affiche la fenetre de fin de jeu
 * Entrées : SDL_Surface screen et SDL_Event event
 * Sorties : rien
************************************************************/
void finishgame (SDL_Surface *screen, SDL_Event event)
{
	SDL_Surface *wallpaper = loadimage("ressources/finishend.bmp");
	SDL_Surface *icon = loadimage("ressources/icon.bmp");
	bool quit=0;
	cout << "partie terminé !!! " << endl;
	
	SDL_WM_SetCaption("DIAMANT  (party finished !!!)", NULL);  
	SDL_WM_SetIcon(icon, NULL);
	
	while (!quit)
	{
		SDL_Delay(32);
		pastesurface(0,0,wallpaper,screen,NULL);
		SDL_Flip(screen);
		
		while ( SDL_PollEvent(&event))
		{
			if ( event.type == SDL_QUIT )
				quit=1;
				
			else if ( event.type == SDL_MOUSEBUTTONDOWN )
				quit=1;
		}
	}
}

#include "gameover.hh"
#include "image.hh"
