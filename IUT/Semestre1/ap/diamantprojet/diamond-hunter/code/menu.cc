/*
#########################################################################
#                                                                       #
#   Regroupe les fonctions permettant de gérer l'interface du menu      #
#   principal, du menu option et du menu introduction.                  #
#                                                                       #
#########################################################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include <fstream>

#include "menu.hh"
#include "image.hh"


bool menugame ( SDL_Surface *screen, SDL_Event event, saveconfig &save )
{
	int mx, my;
	
	bool quit=0;
	SDL_Surface *wallpapermenu = loadimage ("ressources/title.bmp");
	SDL_Surface *icon = loadimage ("ressources/icon.bmp");
	SDL_Surface *button = loadimagecolorkey ("ressources/button.bmp",22,25,73);
	
	SDL_Rect play; play.h=60; play.w=150; play.x=0; play.y=0;
 	SDL_Rect plays; plays.h=60; plays.w=150; plays.x=0; plays.y=60;
 	SDL_Rect quitb; quitb.h=60; quitb.w=150; quitb.x=300; quitb.y=0;
 	SDL_Rect quitbs; quitbs.h=60; quitbs.w=150; quitbs.x=300; quitbs.y=60;
  	SDL_Rect option; option.h=60; option.w=150; option.x=150; option.y=0;
 	SDL_Rect options; options.h=60; options.w=150; options.x=150; options.y=60;	
 	SDL_Rect introd; introd.h=60; introd.w=150; introd.x=450; introd.y=0;
 	SDL_Rect introds; introds.h=60; introds.w=150; introds.x=450; introds.y=60;
	
	SDL_WM_SetCaption("DIAMANT  (Menu)", NULL);  
	SDL_WM_SetIcon(icon, NULL);

	while ( !quit )
	{
		SDL_Delay(32);
		
		mx=event.button.x;
		my=event.button.y;	
		
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
		pastesurface (0,0,wallpapermenu,screen,NULL);
		pastesurface (42,454,button,screen,&play);
		pastesurface (240,454,button,screen,&introd);
		pastesurface (446,454,button,screen,&option);	
		pastesurface (642,454,button,screen,&quitb);	
		
		
		if ( event.type == SDL_MOUSEMOTION)
		{				
			if ( mx>42 && mx<192 && my>454 && my<514)
				pastesurface (42,454,button,screen,&plays);
			if ( mx>240 && mx<390 && my>454 && my<514)
				pastesurface (240,454,button,screen,&introds);
			if ( mx>446 && mx<596 && my>454 && my<514)
				pastesurface(446,454,button,screen,&options);
			if ( mx>642 && mx<792 && my>454 && my<514)
				pastesurface(642,454,button,screen,&quitbs);
		}		
	
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
			{
	  			quit=1;
	  			return 0;
			}
			else if( event.type == SDL_MOUSEBUTTONUP )
			{				
				if ( mx>42 && mx<192 && my>454 && my<514)
				{
					quit=1;
					return 1;
				}
				if ( mx>240 && mx<390 && my>454 && my<514)
				{
					menuintro(screen,event);
					SDL_WM_SetCaption("DIAMANT  (menu)", NULL);
				}				
				if ( mx>446 && mx<596 && my>454 && my<514)
				{
					menuoption(screen,event,save);
					SDL_WM_SetCaption("DIAMANT  (menu)", NULL);
				}				
				if ( mx>642 && mx<792 && my>454 && my<514)
				{
					quit=1;
					return 0;
				}

						
			}
			
		} // Fin du while pollevent.
	
		SDL_Flip(screen);
		
	} // Fin du while quit.		
}



/************************************************************
 * Nom fonction : menu option
 * Nom / Date : aladouce, 14/12/2010, v1
 * Description : permet d'entrer dans la fenêtre option du menu 
 * Entrées : SDL_Surface screen, SDL_Event event
 * Sorties : rien
************************************************************/
void menuoption ( SDL_Surface *screen, SDL_Event event, saveconfig &save )
{
	
	bool quit=0;
	
	int mx, my;
	
	SDL_Surface *wallpapermenu = loadimage ("ressources/titleoption.bmp");
	SDL_Surface *icon = loadimage ("ressources/icon.bmp");
	SDL_Surface *button = loadimagecolorkey ("ressources/button.bmp",22,25,73);
	SDL_Surface *optimg = loadimagecolorkey ("ressources/level.bmp",22,25,73);
	
 	SDL_Rect quitb; quitb.h=60; quitb.w=150; quitb.x=300; quitb.y=0;
 	SDL_Rect quitbs; quitbs.h=60; quitbs.w=150; quitbs.x=300; quitbs.y=60;
 	SDL_Rect easyopt; easyopt.h=240; easyopt.w=150; easyopt.x=0;
 	SDL_Rect medopt; medopt.h=240; medopt.w=150; medopt.x=150;
 	SDL_Rect hardopt; hardopt.h=240; hardopt.w=150; hardopt.x=300; hardopt.y=0;
	
	SDL_WM_SetCaption("DIAMANT  (options)", NULL);  
	SDL_WM_SetIcon(icon, NULL);
	
	while (!quit)
	{
		SDL_Delay(32);
		
		mx=event.button.x;
		my=event.button.y;	
		
		switch (save.level)
		{
			case 1 : easyopt.y=240; medopt.y=0; hardopt.y=0;
				break;
			case 2 : easyopt.y=0; medopt.y=240; hardopt.y=0;
				break;
			case 3 : easyopt.y=0; medopt.y=0; hardopt.y=240;
				break;
		}	
		
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
		pastesurface (0,0,wallpapermenu,screen,NULL);
		pastesurface (338,454,button,screen,&quitb);
		pastesurface (124,132,optimg,screen,&easyopt);
		pastesurface (348,132,optimg,screen,&medopt);
		pastesurface (572,132,optimg,screen,&hardopt);			
			
		
		if ( event.type == SDL_MOUSEMOTION)
		{				
			if ( mx>338 && mx<488 && my>454 && my<514)
				pastesurface(338,454,button,screen,&quitbs);
		}
		
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
	  			quit=1;				
			else if( event.type == SDL_MOUSEBUTTONUP )
			{				
				if ( mx>338 && mx<488 && my>454 && my<514)
					quit=1;	
			}
			else if( event.type == SDL_MOUSEBUTTONDOWN )
			{				
				if ( mx>124 && mx<274 && my>132 && my<472)
					save.level=1; 
				if ( mx>348 && mx<498 && my>132 && my<472)
					save.level=2;
				if ( mx>572 && mx<722 && my>132 && my<472)	
					save.level=3; 
			}
			
		} // Fin du while pollevent.	
		
		SDL_Flip(screen);

	} // Fin du while quit.
}



/************************************************************
 * Nom fonction : menu option
 * Nom / Date : aladouce, 20/12/2010, v1
 * Description : permet d'entrer dans la fenêtre introduction
 * Entrées : SDL_Surface screen, SDL_Event event
 * Sorties : rien
************************************************************/
void menuintro ( SDL_Surface *screen, SDL_Event event )
{
	
	bool quit=0;
	
	int mx, my;
	
	SDL_Surface *wallpapermenu = loadimage ("ressources/titleintro.bmp");
	SDL_Surface *icon = loadimage ("ressources/icon.bmp");
	SDL_Surface *button = loadimagecolorkey ("ressources/button.bmp",22,25,73);
	SDL_Surface *optimg = loadimagecolorkey ("ressources/level.bmp",22,25,73);
	
 	SDL_Rect quitb; quitb.h=60; quitb.w=150; quitb.x=300; quitb.y=0;
 	SDL_Rect quitbs; quitbs.h=60; quitbs.w=150; quitbs.x=300; quitbs.y=60;
	
	SDL_WM_SetCaption("DIAMANT  (introduction)", NULL);  
	SDL_WM_SetIcon(icon, NULL);
	
	while (!quit)
	{
		SDL_Delay(32);
		
		mx=event.button.x;
		my=event.button.y;		
		
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
		pastesurface (0,0,wallpapermenu,screen,NULL);
		pastesurface (338,484,button,screen,&quitb);					
		
		if ( event.type == SDL_MOUSEMOTION)
		{				
			if ( mx>338 && mx<488 && my>484 && my<544)
				pastesurface(338,484,button,screen,&quitbs);
		}
		
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
	  			quit=1;				
			else if( event.type == SDL_MOUSEBUTTONUP )
			{				
				if ( mx>338 && mx<488 && my>484 && my<544)
					quit=1;	
			}			
		} // Fin du while pollevent.	
		
		SDL_Flip(screen);

	} // Fin du while quit.
}
