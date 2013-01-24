#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <fstream>

#include "menu.hh"
#include "const.hh"

void 
menugame ( SDL_Surface *screen, SDL_Event event )
{
	
	#include "ressources.hh"
	#include "image.hh"
	
	bool quit=0;
	
	
	while ( !quit )
	{
			pastesurface (0,0,wallpapermenu,screen,NULL);
		
		SDL_Flip(screen);
	
		while(SDL_PollEvent(&event))
		if(event.type==SDL_QUIT)
	  		quit=1;
		
	}	
	
	
}

