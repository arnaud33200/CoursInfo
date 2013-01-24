#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<fstream>

#include "init.hh"
#include "image.hh"
#include "const.hh"
#include "game.hh"
#include "menu.hh"

using namespace std;


 
/************************************************************
 * ACTION PRINCIPAL
************************************************************/

int main(int argc, char* argv[])
{
			/***************** variable *********************/
						
	bool quit=false;
	SDL_Event event;
	SDL_Surface *screen;
	
	//~ SDL_Surface *wallpaper;
	
	//~ int tabg[G_SIZE][G_SIZE];
	//~ 
	//~ initg(tabg);
	//~ viewtab(tabg);
	
			/************** initialisation **************/
	
	SDL_Init(SDL_INIT_EVERYTHING);

 	screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
 	
	
			/************** chargement des images diamants *****************/
	
	//~ blue.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	//~ wallpaper = loadimage ("../ressources/fond.bmp");
	
	
/*******************************************************************
 * BOUCLE PRINCIPALE
*******************************************************************/

		/***************** MENU DIAMANT **************************/
//~ menugame(screen, event);

		/***************** JEU DIAMANT ***************************/
maingame(screen, event);



	
  	SDL_FreeSurface(screen);
  	SDL_Quit();
	return 0;
}
