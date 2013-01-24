#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<fstream>

#include "image.hh"
#include "game.hh"
#include "menu.hh"
#include "struct.hh"
#include "gameover.hh"

using namespace std;


 
/************************************************************
 * ACTION PRINCIPALE
************************************************************/

int main(int argc, char* argv[])
{
			/***************** Variables SDL de base *********************/
						
	SDL_Event event;
	SDL_Surface *screen;
	
	saveconfig save;
	save.level=2;
	
			/************** Initialisation **************/
	
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
 	screen=SDL_SetVideoMode(842,550,32,SDL_SWSURFACE);
 	
				
	
/*******************************************************************
 * BOUCLE PRINCIPALE
*******************************************************************/
	bool menu=1;

		/***************** MENU DIAMANT **************************/
// La fonction "menu" retourne un booléen. 
	do
	{
		menu=menugame(screen, event, save);

		/***************** JEU DIAMANT ***************************/
		
		if ( menu ) // Lancement du menu principal. 
		{
			SDL_FreeSurface(screen); 
			if ( !maingame(screen, event, save) )   // Lancement du jeu. 
				abandongame(screen, event); // La partie est abandonnée.
				
			else 
				finishgame(screen, event); // Le temps est écoulé.		
		}

	}
	while (menu);


	TTF_Quit();	
  	SDL_FreeSurface(screen);
  	SDL_Quit();
	return 0;
}
