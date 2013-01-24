/*
##########################################################################
#                                                                        #
#   regroupe les fonctions qui permettent gerer l'interface du jeu       #
# 	et des actions réalisées pendant et aprés l'intervention du          #
# 	joueur.                 											 #
#                                                                        #
##########################################################################
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
	
///************** texte en tête de fenêtre ********************///	
	SDL_Surface *icon = loadimage ("ressources/icon.bmp");
	SDL_WM_SetCaption("DIAMANT  (jeu)", NULL);  
	SDL_WM_SetIcon(icon, NULL);

///******************* variables ***********************///
  
	board tab;		// plateau de jeu
	bool quit=0;	// booléen partie terminé
	string scoree="0";		// string score
	string timee="0";  // string temps
	int tmpfi=0, tmpfj=0, tmpli=0, tmplj=0;		//coordonné des diamants TEMPORAIRE 
	int mx, my; 	// coordonnée de la sourie
	bool combo=0;  // booléen quand indique si le joueur vient de marqué
	int tmpscore;  // enregistre score précédant => pour calculer combo
	int tmptime;   // enregistrement temps précédent
	int cpttime;   // compteur des 10 secondes avant solution
	
	// ecriture 
  	TTF_Font *pirate = TTF_OpenFont("ressources/pirate.ttf", 45);
  	SDL_Color black={255,255,255};
 
///****************** initialisation ******************///

// sauvegarde
	initsaveconfig(tab,save);	
// images
	initpicture(tab); 
	
// texte
	tab.scorus = TTF_RenderText_Blended(pirate, scoree.c_str(), black);
	tab.time = TTF_RenderText_Blended(pirate, timee.c_str(), black);
	tab.temps = TTF_RenderText_Blended(pirate, "Temps :", black);
	tab.point = TTF_RenderText_Blended(pirate, "Points :", black);
	
	do	
	initgrille(tab); // grille		
	while ( !verifgenerale(tab) );
	tab.score=0;  //  score
	tab.combinaison=0; // etat combo de la grille et compeut combo
	tmptime=10+((SDL_GetTicks())/1000);
				
  
/********************************************************************
 *  DEBUT DU JEU
*********************************************************************/
  
	while (!quit)
	{
		SDL_Delay(32);
		mx=event.button.x;  // coordonnée X du pointeur sourie
		my=event.button.y;	// coordonnée Y du pointeur sourie
		cpttime=tmptime-(SDL_GetTicks())/1000;
 		
 ///******************** mise a jour texte ************///
 // les entiers sont converties en chaine de caractère puis on met a jour les SDL_Surface
 		scoree=converter(tab.score);
 		timee=converter(tab.TIMEGAME-((SDL_GetTicks())/1000));
 		tab.scorus = TTF_RenderText_Blended(pirate, scoree.c_str(), black);
		tab.time = TTF_RenderText_Blended(pirate, timee.c_str(), black);


///******************** affichage images **************///    
		SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,0,0,0));
      	

///************** lorsque la sourie passe au dessus d'une case ********///
      	if ( event.type == SDL_MOUSEMOTION)
		{		
			if ( mx>tab.midleadd && mx<(tab.G_SIZE)*60+tab.midleadd && my>tab.midleadd && my<(tab.G_SIZE)*60+tab.midleadd )
			{
				tmpfi=(my-tab.midleadd)/60;
				tmpfj=(mx-tab.midleadd)/60;
				tab.matrice[tmpfi][tmpfj].blue=1;
			}
		}	

///************ affichage graphique de la grille diamant ***************///			           
      affichergrille(tab,screen); 
      tab.matrice[tmpfi][tmpfj].blue=0;  // deselectionne ce qui a été pointé
      
   
///*********** compteur de 10 seconde puis donne une solution *********///     
      if ( cpttime <= 0)
      {
		  verifgenerale(tab);
		  tab.matrice[tab.li][tab.lj].sele=1;
		  tmptime=10+(SDL_GetTicks()/1000);
		  tmpli=tab.li;
		  tmplj=tab.lj;
	  }

/// *********** les évenements ****************************************///
      while(SDL_PollEvent(&event))
		{
	//*********** appuie sur bar d'espace = PAUSE ******************/		
			if( event.type == SDL_KEYDOWN )
				if ( event.key.keysym.sym == SDLK_SPACE )
				{
					gamepause(tab, screen);
					tmptime=10+(SDL_GetTicks()/1000);
				}
					
			
	//*********** quitte la fenetre = finabandon *********************/		
			if(event.type==SDL_QUIT)
			{
				quit=1;
				return 0;
			}
								
	//*********** selection du premier diamant *********************/		

			else if( event.type == SDL_MOUSEBUTTONDOWN && goodmouse(tab,mx,my) )
			{
				tab.fi=(my-tab.midleadd)/60;  // enregristrement coordonnée
				tab.fj=(mx-tab.midleadd)/60;
				if (mx>tab.midleadd && mx<tab.G_SIZE*60+tab.midleadd 
					&&	my>tab.midleadd && my<tab.G_SIZE*60+tab.midleadd )
				{			
				tab.matrice[tab.fi][tab.fj].sele=1;  // la case selectionné devient rouge
				tmptime=10+((SDL_GetTicks())/1000);  // compteur de temps solution remis a 10
				tab.matrice[tmpli][tmplj].sele=0;	
				}			
			}
	  //*********** selection du deuxième diamant *******************/		
			else if( event.type == SDL_MOUSEBUTTONUP && goodmouse(tab,mx,my) )
			{
				tab.matrice[tab.fi][tab.fj].sele=0;			
				tab.li=(my-tab.midleadd)/60;
				tab.lj=(mx-tab.midleadd)/60;
	      
	//************ si l'echange est correct **************************/	      
				if ( changeposition(tab) )
				{
					affichergrille(tab,screen);	
					SDL_Delay(220);
					combo=1;	
				}
				
		// enregistrement temporaire des coordonnées pour refaire l'echange si il y a pas diamants alignés
				tmpfi=tab.fi; tmpfj=tab.fj; tmpli=tab.li; tmplj=tab.lj;					

		//  verif l'efficacité de l'échange et fait les animations 																
				if ( verifchangement(tab,screen) )
					combo=1;
					
		// sinon afficher des croix sur les cases et reéffectue l'echange	
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
				
		}  // fin du while eventpoll
	
      

      
      
///****************** COMBO *************************///
      		if ( combo > 0 )
      		{
      			tab.combinaison=1;
				tmpscore=tab.score;
      			while ( combo!=0 )
      			{
      				if ( verifcombo(tab,screen) )
      				{    					
						tab.score+=(tab.score-tmpscore)*(tab.combinaison);  // bonnus de score
						tmpscore=tab.score;  // enregistrement temporaire de l'ancien score
						tab.combinaison*=2;  // mutiplication du coéfficiant combo 
					}
      				else
      				{
      					combo=0;
      					tab.combinaison=0;
					}
					tmptime=10+((SDL_GetTicks())/1000); // remise a 10 du compteur soluce
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

      
      /***************************************** verif si soluce en plein jeu ********/
      

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






