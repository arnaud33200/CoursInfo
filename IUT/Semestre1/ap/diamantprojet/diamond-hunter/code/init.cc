/*
########################################################################
#                                                                      #
#   Regroupe les fonctions permettant les diverses initialisations     #
# 	utilisées pour la grille du jeu, les images du jeu, et les         #
# 	paramètres du jeu.											       #
#                                                                      #
########################################################################
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"

#include "init.hh"
#include "struct.hh"
#include "image.hh"

using namespace std;


/************************************************************
 * Nom fonction : initgrille
 * Nom / Date : aladouce , 16/11/2010 , v3
 * Description : initialise la grille du jeu
 * 				 (update1: precision des cases à initialiser)
 * 				 (update2: verifie si la grille est bien initialisée)
 * Entrées : une grille tab, 4 entier : fi fj li lj
 * Sorties : la grille tab
************************************************************/
void initgrille ( board & tab)
{	
	srand(time(NULL));
	for ( int i=0; i < tab.G_SIZE; i++ ) 
	{
		for ( int j=0; j < tab.G_SIZE; j++ )
		{
			tab.matrice[i][j].color=rand()%(tab.NB_SIZE)+1;
			
			// Verification s'il n'y a pas 3 diamants ou plus alignés.	
			if ( j>1 )
				while ( tab.matrice[i][j].color == tab.matrice[i][j-2].color )
					tab.matrice[i][j].color=rand()%(tab.NB_SIZE)+1;
			if ( i>1)
				while (tab.matrice[i][j].color == tab.matrice[i-2][j].color)
					tab.matrice[i][j].color=rand()%(tab.NB_SIZE)+1;	
			
			tab.matrice[i][j].position.x=j*60+tab.midleadd;			
			tab.matrice[i][j].position.y=i*60+tab.midleadd;	
			tab.matrice[i][j].lecture.h=61;
			tab.matrice[i][j].lecture.w=61;
			tab.matrice[i][j].sele=0;	
			tab.matrice[i][j].cross=0;
			tab.matrice[i][j].blue=0;
		}		
	}
}



/************************************************************
 * Nom fonction : initialisation image
 * Nom / Date : aladouce, 12/12/2010, v1
 * Description : initialise toutes les images utilisées dans le jeu
 * Entrées : structure board
 * Sorties : structure board
************************************************************/
void initpicture (board &tab)
{
	tab.diamsprite = loadimagecolorkey ("ressources/pieces.bmp",0,255,255);
	tab.diamspritenocolor = loadimage ("ressources/pieces.bmp");
	tab.explosion = loadimagecolorkey ("ressources/explosion.bmp",255,255,255); 
	tab.bonustexte = loadimage ("ressources/bonus.bmp"); 
	tab.bonus = loadimagecolorkey ("ressources/fondBonus.bmp",22,25,73); 
	tab.stoppause = loadimagecolorkey ("ressources/pause.bmp",22,25,73); 
	tab.bonusinfo = loadimagecolorkey ("ressources/points.bmp",22,25,73); 
	tab.le.w=61; tab.le.h=61; tab.le.y=0;
	tab.lb.w=166; tab.lb.h=113; tab.lb.x=2806; tab.lb.y=0;
}


/************************************************************
 * Nom fonction : initialisation save configuration
 * Nom / Date : aladouce, 12/12/2010, v1
 * Description : initialise les paramètres du jeu en fonction du choix du joueur:
 * 				 - taille grille, nombre de diamants, temps de jeu
 * 				 -> on definit les paramétres des trois niveaux différents
 * Entrées : structure board
 * Sorties : structure board
************************************************************/
void initsaveconfig (board &tab, saveconfig &save)
{
	switch (save.level)
	{
		case 1 : 
			tab.G_SIZE=8; 
			tab.NB_SIZE=6; 
			tab.TIMEGAME=90+(SDL_GetTicks()/1000); 
			tab.midleadd=8;
			tab.wallpapergame = loadimage ("ressources/fond3.bmp");
		break;
			
		case 2 : 
			tab.G_SIZE=7; 
			tab.NB_SIZE=7; 
			tab.TIMEGAME=60+(SDL_GetTicks()/1000); 
			tab.midleadd=27;
			tab.wallpapergame = loadimage ("ressources/fond2.bmp");
		break;
		
		case 3 : 
		tab.G_SIZE=6;
		tab.NB_SIZE=8; 
		tab.TIMEGAME=30+(SDL_GetTicks()/1000); 
		tab.midleadd=56;
		tab.wallpapergame = loadimage ("ressources/fond1.bmp");
		break;
	}
}


