/*
########################################################################
#                                                                      #
#   Regroupe les fonctions qui permettent de gerer l'interface du jeu  #
# 	et des actions réalisées pendant et aprés l'intervention du        #
# 	joueur.                 									       #
#                                                                      #
########################################################################
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<fstream>
#include<sstream>

using namespace std;

#include "game.hh"
#include "image.hh"
#include "init.hh"
#include "change.hh"
#include "verif.hh"
#include "struct.hh" 
#include "action.hh"


bool maingame ( SDL_Surface *screen, SDL_Event event, saveconfig &save )
{
	
///************** Texte en tête de fenêtre ********************///	
	SDL_Surface *icon = loadimage ("ressources/icon.bmp");
	SDL_WM_SetCaption("DIAMANT  (jeu)", NULL);  
	SDL_WM_SetIcon(icon, NULL);

///******************* Variables ***********************///
  
	board tab;		// Plateau de jeu.
	bool quit=0;	// Booléen partie terminée.
	string scoree="0";		// String score.
	string timee="0";  // String temps.
	int tmpfi=0, tmpfj=0, tmpli=0, tmplj=0;		// Coordonnées des diamants TEMPORAIRES. 
	int mx, my; 	// Coordonnées de la souris.
	bool combo=0;  // Booléen qui indique si le joueur vient de marquer des points.
	int tmpscore;  // Enregistre le score précédent => pour calculer combo.
	int tmptime;   // Enregistrement du temps précédent
	int cpttime;   // Compteur des 10 secondes avant solution.
	
	// ecriture 
  	TTF_Font *pirate = TTF_OpenFont("ressources/pirate.ttf", 45);
  	SDL_Color black={255,255,255};
 
///****************** Initialisation ******************///

// Sauvegarde.
	initsaveconfig(tab,save);	
// Images.
	initpicture(tab); 
	
// Texte.
	tab.scorus = TTF_RenderText_Blended(pirate, scoree.c_str(), black);
	tab.time = TTF_RenderText_Blended(pirate, timee.c_str(), black);
	tab.temps = TTF_RenderText_Blended(pirate, "Time :", black);
	tab.point = TTF_RenderText_Blended(pirate, "Score :", black);
	
	do	
	initgrille(tab); // Grille.		
	while ( !verifgenerale(tab) );
	tab.score=0;  //  Score.
	tab.combinaison=0; // Etat combo de la grille et qu'un combo est possible.
	tmptime=10+((SDL_GetTicks())/1000);
				
  
/********************************************************************
 *  DEBUT DU JEU
*********************************************************************/
  
	while (!quit)
	{
		SDL_Delay(32);
		mx=event.button.x;  // Coordonnée X du pointeur souris.
		my=event.button.y;	// Coordonnée Y du pointeur souris.
		cpttime=tmptime-(SDL_GetTicks())/1000;
 		
 ///******************** Mise a jour texte ************///
 // Les entiers sont convertis en chaînes de caractère puis on met a jour les SDL_Surface.
 		scoree=converter(tab.score);
 		timee=converter(tab.TIMEGAME-((SDL_GetTicks())/1000));
 		tab.scorus = TTF_RenderText_Blended(pirate, scoree.c_str(), black);
		tab.time = TTF_RenderText_Blended(pirate, timee.c_str(), black);


///******************** Affichage des images **************///    
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
      	

///************** Lorsque la souris passe au dessus d'une case ********///
      	if ( event.type == SDL_MOUSEMOTION)
		{		
			if ( mx>tab.midleadd && mx<(tab.G_SIZE)*60+tab.midleadd && my>tab.midleadd && my<(tab.G_SIZE)*60+tab.midleadd )
			{
				tmpfi=(my-tab.midleadd)/60;
				tmpfj=(mx-tab.midleadd)/60;
				tab.matrice[tmpfi][tmpfj].blue=1;
			}
		}	

///************ Affichage graphique de la grille diamant ***************///			           
      affichergrille(tab,screen); 
      tab.matrice[tmpfi][tmpfj].blue=0;  // Déselectionne ce qui a été pointé.
      
   
///*********** Compteur de 10 seconde puis donne une solution *********///     
      if ( cpttime <= 0)
      {
		  verifgenerale(tab);
		  tab.matrice[tab.li][tab.lj].sele=1;
		  tmptime=10+(SDL_GetTicks()/1000);
		  tmpli=tab.li;
		  tmplj=tab.lj;
	  }

/// *********** Les évenements ****************************************///
      while(SDL_PollEvent(&event))
		{
	//*********** Appuie sur la barre d'espace = PAUSE ******************/		
			if( event.type == SDL_KEYDOWN )
				if ( event.key.keysym.sym == SDLK_SPACE )
				{
					gamepause(tab, screen);
					tmptime=10+(SDL_GetTicks()/1000);
				}
					
			
	//*********** Quitte la fenêtre = fin (abandon) *********************/		
			if(event.type==SDL_QUIT)
			{
				quit=1;
				SDL_FreeSurface(screen);
				return 0;
			}
								
	//*********** Sélection du premier diamant. *********************/		

			else if( event.type == SDL_MOUSEBUTTONDOWN && goodmouse(tab,mx,my) )
			{
				tab.fi=(my-tab.midleadd)/60;  // Enregistrement des coordonnées.
				tab.fj=(mx-tab.midleadd)/60;
				if (mx>tab.midleadd && mx<tab.G_SIZE*60+tab.midleadd 
					&&	my>tab.midleadd && my<tab.G_SIZE*60+tab.midleadd )
				{			
				tab.matrice[tab.fi][tab.fj].sele=1;  // La case selectionnée devient rouge.
				tmptime=10+((SDL_GetTicks())/1000);  // Compteur de temps solution remis a 10.
				tab.matrice[tmpli][tmplj].sele=0;	
				}			
			}
	  //*********** Sélection du deuxième diamant *******************/		
			else if( event.type == SDL_MOUSEBUTTONUP && goodmouse(tab,mx,my) )
			{
				tab.matrice[tab.fi][tab.fj].sele=0;			
				tab.li=(my-tab.midleadd)/60;
				tab.lj=(mx-tab.midleadd)/60;
	      
	//************ Si l'echange est correct **************************/	      
				if ( changeposition(tab) )
				{
					affichergrille(tab,screen);	
					SDL_Delay(220);
					combo=1;	
				}
				
		// Enregistrement temporaire des coordonnées pour refaire l'echange s'il n'y a pas de diamants alignés.
				tmpfi=tab.fi; tmpfj=tab.fj; tmpli=tab.li; tmplj=tab.lj;					

		//  Verification de  l'efficacité de l'échange et génère les animations. 																
				if ( verifchangement(tab,screen) )
					combo=1;
					
		// Sinon afficher des croix sur les cases et reéffectue l'echange.	
				else
				{
					if ( acote(tab) )
					{
					tab.fi=tmpfi; tab.fj=tmpfj; tab.li=tmpli; tab.lj=tmplj; 	
					tab.matrice[tab.fi][tab.fj].cross=1;
					tab.matrice[tab.li][tab.lj].cross=1;
					affichergrille(tab,screen);
					SDL_Delay(1000);
					}
					changeposition(tab ); 
					tab.matrice[tab.fi][tab.fj].cross=0;
					tab.matrice[tab.li][tab.lj].cross=0;					
					combo=0;
				}	
			}
				
		}  // Fin du while eventpoll.
	
      

      
      
///****************** COMBO *************************///
      		if ( combo > 0 )
      		{
      			tab.combinaison=1;
				tmpscore=tab.score;
      			while ( combo!=0 )
      			{
      				if ( verifcombo(tab,screen) )
      				{    					
						tab.score+=(tab.score-tmpscore)*(tab.combinaison);  // Bonus de score.
						tmpscore=tab.score;  // Enregistrement temporaire de l'ancien score.
						tab.combinaison*=2;  // Mutiplication du coéfficient combo. 
					}
      				else
      				{
      					combo=0;
      					tab.combinaison=0;
					}
					tmptime=10+((SDL_GetTicks())/1000); // Remise a 10 du compteur solution.
				}	
			}

      /**************************************************/	
      
      if ( !verifgenerale(tab) )
      {
		SDL_Delay(250);
		affichersanssoluce(tab,screen);
		SDL_Delay(1000);
		initgrille(tab);
		cout << "grille initialisé" << endl;
	}

      
      /***************************************** Verif si solution en plein jeu ********/
      

		if ( tab.TIMEGAME-((SDL_GetTicks())/1000)==0 )
		{
			cout << endl << endl
				<< "temps écoulé" << endl;
			quit=1; 
			return 1;
		}

	}
    
}	



string converter ( int a )
{
	ostringstream s;
	s << a;
	return s.str();
}






