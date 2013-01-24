#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <fstream>

#include "game.hh"
#include "const.hh"
#include "solution.hh"

	
	
void 
maingame ( SDL_Surface *screen, SDL_Event event )
{
	#include "ressources.hh"
	#include "image.hh"
	#include "init.hh"
	
/************************** variables ****************************************************/
	int tabg[G_SIZE][G_SIZE];
	initg(tabg);

	
			// mettre fonction qui verifi qu'il y a pas deja 3 diamant aligné
			// pour eviter de mettre un score != 0 au debut de la partie
			

	viewtab(tabg);
		
	/********************** coordonné diams ***********************************/
	
	int fi=-1;
	int fj=-1;
	int li=-1;
	int lj=-1;
	
	
	bool quit=0;


/************************** debut boucle *************************************************/
	
	while (!quit)
	{
	
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
		
		pastesurface (0,0,wallpapergame,screen,NULL);

		for (int i=0; i<G_SIZE; i++)
		{
			for (int j=0; j<G_SIZE; j++)
			{
				switch (tabg[i][j])
				{
					case 1: pastesurface(j*60+8, i*60+8, blue.img, screen, &blue.lecture);
					break; 
					case 2 : pastesurface(j*60+8, i*60+8, red.img, screen, &red.lecture);
					break;
					case 3 : pastesurface(j*60+8, i*60+8, dgreen.img, screen, &dgreen.lecture);
					break;
					case 4 : pastesurface(j*60+8, i*60+8, lgreen.img, screen, &lgreen.lecture);
					break;
					case 5 : pastesurface(j*60+8, i*60+8, purple.img, screen, &purple.lecture);
					break;
					case 6 : pastesurface(j*60+8, i*60+8, pink.img, screen, &pink.lecture);
					break;
					case 7 : pastesurface(j*60+8, i*60+8, orange.img, screen, &orange.lecture);
					break;
					case 8 : pastesurface(j*60+8, i*60+8, yellow.img, screen, &yellow.lecture);
					break;
				}

			}
		}


 
		
		SDL_Flip(screen);
	
		while(SDL_PollEvent(&event))
		if(event.type==SDL_QUIT)
			quit=1;
		else if(event.type == SDL_MOUSEBUTTONDOWN )
		{
		solutioncolone(tabg, fj, fi, lj, li);
cout << fi << " " << fj << " " << li << " " << lj << endl;
}



		}
}		
		

