/*
##########################################################################
#                                                                        #
#   regroupe les fonctions qui permet l'affichage et l'animation du jeu  #
#                                                                        #
##########################################################################
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

#include "action.hh"
#include "image.hh"
#include "struct.hh"
#include "verif.hh"
#include "change.hh"


/************************************************************
 * Nom fonction : affichergrille
 * Nom / Date : aladouce, 04/12/2010 v2
 * Description : permet l'affichage de la matrice diamond
 * 				 (update1: ajout de SDL_Flip et wallpaper)
 * Entrées : 
 * Sorties :
************************************************************/
void 
affichergrille( board & tab, SDL_Surface *screen )
 {
/// fond d'ecran
	pastesurface (0,0,tab.wallpapergame,screen,NULL);
/// si il y a combo
	if (tab.combinaison>=1)
	{
		tab.lb.y=(tab.combinaison-1)*112;
		pastesurface (574,183,tab.bonus,screen,NULL);
		pastesurface (575,400,tab.bonusinfo,screen,&tab.lb);
	}
/// texte 		
	pastesurface (596,500,tab.bonustexte,screen,NULL);
	pastesurface (8,500,tab.point,screen,NULL);
	pastesurface (164,500,tab.scorus,screen,NULL);
	pastesurface (270,500,tab.temps,screen,NULL);
	pastesurface (416,500,tab.time,screen,NULL);

/// grille de diamant	
     for (int i=0; i<tab.G_SIZE; i++)
	{
	  for (int j=0; j<tab.G_SIZE; j++)
	    {
			if ( tab.matrice[i][j].sele==1 ) // si une case est selectionné
				tab.matrice[i][j].lecture.y=61;
			else if (tab.matrice[i][j].cross==1) // si une case est interdite
				tab.matrice[i][j].lecture.y=122;
			else if (tab.matrice[i][j].blue==1) // si une casse est traversé par le curseu
				pastesurface(tab.matrice[i][j].position.x,tab.matrice[i][j].position.y, 
			tab.diamspritenocolor, screen, &tab.matrice[i][j].lecture);	
			else if (tab.matrice[i][j].color == 0 )
			{
				tab.matrice[i][j].lecture.y=183;
				tab.matrice[i][j].lecture.x=0;
			}	
					
			else
			{
			tab.matrice[i][j].lecture.y=0;
			tab.matrice[i][j].lecture.x=((tab.matrice[i][j].color)-1)*60;
			}
			
		tab.matrice[i][j].lecture.x=((tab.matrice[i][j].color)-1)*60;
	    pastesurface(tab.matrice[i][j].position.x,tab.matrice[i][j].position.y, 
		tab.diamsprite, screen, &tab.matrice[i][j].lecture);
	      
	    }
	}
	SDL_Flip(screen); 			
}


/************************************************************
 * Nom fonction : affichesansgrille
 * Nom / Date : aladouce, 12/12/2010 v2
 * Description : permet l'affichage de tout sauf de la grille
 * Entrées : 
 * Sorties :
************************************************************/
void affichesansgrille (board &tab, SDL_Surface *screen)
{
	pastesurface (0,0,tab.wallpapergame,screen,NULL);
	if (tab.combinaison==1)
		pastesurface (574,183,tab.bonus,screen,NULL);
	pastesurface (596,500,tab.bonustexte,screen,NULL);
	pastesurface (49,110,tab.stoppause,screen,NULL);
	SDL_Flip(screen); 	
}


/************************************************************
 * Nom fonction : affichesansgrille
 * Nom / Date : aladouce, 12/12/2010 v2
 * Description : permet l'affichage de tout sauf de la grille
 * Entrées : 
 * Sorties :
************************************************************/
void affichersanssoluce (board &tab, SDL_Surface *screen)
{	
	for (int i=0; i<tab.G_SIZE; i++)
	{
	  for (int j=0; j<tab.G_SIZE; j++)
	    {
		tab.matrice[i][j].lecture.y=122;
		tab.matrice[i][j].lecture.x=((tab.matrice[i][j].color)-1)*60;
		tab.matrice[i][j].lecture.x=((tab.matrice[i][j].color)-1)*60;
	    pastesurface(tab.matrice[i][j].position.x,tab.matrice[i][j].position.y, 
		tab.diamsprite, screen, &tab.matrice[i][j].lecture);      
	    }
	}
	SDL_Flip(screen); 	
}


/************************************************************
 * Nom fonction : game pause
 * Nom / Date : aladouce, 12/12/2010 v2
 * Description : met le jeu en pause
 * 				 (update1: ajout d'un time freezer)
 * Entrées : board tab, SDL_Surface screen  
 * Sorties : board tab
************************************************************/
void gamepause ( board &tab, SDL_Surface *screen )
{
	bool go=0;
	SDL_Event event;
	int tmptime=SDL_GetTicks()/1000;
	
	 SDL_WM_SetCaption("DIAMANT  (pause)", NULL);
	 affichesansgrille(tab,screen);	    
  
	while (go!=1)
    {
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT: go=1;
		break;
		case SDL_KEYDOWN:
		if ( event.key.keysym.sym == SDLK_SPACE )
			go=1;
		break;
		}
	}
	// evite que le temps continue de s'écoulé
	SDL_WM_SetCaption("DIAMANT  (jeu)", NULL);  
	tab.TIMEGAME+=(SDL_GetTicks()/1000)-tmptime;
}


/************************************************************
 * Nom fonction : destruction colone
 * Nom / Date : aladouce, 10/12/2010, v1
 * Description : fait l'animation de destruction des diamants en colone
 * Entrées : board tab, SDL_Surface screen
 * Sorties : board tab
************************************************************/
void destructioncolone (board &tab, SDL_Surface *screen)
{
	int j;
	for (int i=tab.fi; i<=tab.li; i++) // efface les diamants alignés
	{
		tab.matrice[i][tab.fj].color=0;
		affichergrille(tab,screen);
	}
	for (int i=9; i>0; i--)   // animation de l'explosion
	{
		tab.le.x=i*60;
		j=tab.fi;
		while ( j<=tab.li && j<tab.G_SIZE )  // parcour les diamants alignés sans depasser la grille 
		{
			SDL_Delay(0);
			pastesurface(tab.fj*60+tab.midleadd,j*60+tab.midleadd,tab.explosion,screen, &tab.le);
			j++;
		}	
		SDL_Delay(70); // delay de temps entre chaque animation
		SDL_Flip(screen);
	}
}


/************************************************************
 * Nom fonction : destruction colone
 * Nom / Date : aladouce, 10/12/2010, v1
 * Description : fait l'animation de destruction des diamants en ligne
 * Entrées : board tab, SDL_Surface screen
 * Sorties : board tab
************************************************************/
void destructionligne (board &tab, SDL_Surface *screen)
{
	int j;
	for (int i=tab.fj; i<=tab.lj; i++) // efface les diamants alignés
	{						
		tab.matrice[tab.fi][i].color=0;
		affichergrille(tab,screen);
	}
	
	for (int i=9; i>0; i--) // animation de l'explosion
	{
		tab.le.x=i*60;
		j=tab.fj;
		while (j<=tab.lj && j < tab.G_SIZE)// parcour les diamants alignés sans depasser la grille 
		{
			SDL_Delay(0);
			pastesurface(j*60+tab.midleadd,tab.fi*60+tab.midleadd,tab.explosion,screen, &tab.le);
			j++;
		}	
		SDL_Delay(70);
		SDL_Flip(screen);
	}
}

/************************************************************
 * Nom fonction : verif changement
 * Nom / Date : aladouce, 10/12/2010, v1
 * Description : verifie si echange génére un alignement de 3 diamants ou plus
 * 				 et fait appel a diverse animation :
 * 				 	- explosions
 * 					- decalages
 * Entrées : board tab, SDL_Surface screen
 * Sorties : board tab
************************************************************/
bool verifchangement (board &tab, SDL_Surface *screen)
{
	if ( solutioncolone(tab) )
	{
		destructioncolone(tab, screen);
		decalebascolone(tab,screen);
		return 1;
	}			
	else if ( solutionligne(tab) )
	{
		destructionligne(tab,screen);
		decalebasligne(tab,screen);
		return 1;
	}
	else
		return 0;
}



/************************************************************
 * Nom fonction : verif changement
 * Nom / Date : aladouce, 11/12/2010, v1
 * Description : verifie si il y a des combo aprés un alignement précédent
 * 				 et fait appel a diverse animations :
 * 				 	- explosions
 * 					- decalages
 * Entrées : board tab, SDL_Surface screen
 * Sorties : board tab
************************************************************/
bool verifcombo (board &tab, SDL_Surface *screen)
{
	tab.fi=0; tab.li=tab.G_SIZE; tab.fj=0; tab.lj=tab.G_SIZE;
	if ( solutioncolone(tab) )
	{
		SDL_Delay(250);
		animcombobonus(tab,screen);
		destructioncolone(tab, screen);
		decalebascolone(tab,screen);
		return 1;
	}			
	else if ( solutionligne(tab) )
	{
		SDL_Delay(250);
		animcombobonus(tab,screen);
		destructionligne(tab,screen);
		decalebasligne(tab,screen);
		return 1;
	}
	else
		return 0;
}

void animcombobonus (board &tab, SDL_Surface *screen)
{
	tab.lb.y=(tab.combinaison-1)*112;
	for (int i=9; i<18; i++)
	{
		tab.lb.x=i*164;
		SDL_Delay(40);
		pastesurface (575,400,tab.bonusinfo,screen,&tab.lb);
		SDL_Flip(screen);
	}
}



