#ifndef RESSOURCES_HH
#define RESSOURCES_HH

#include "struct.hh"
#include "image.hh"

#include<string>
using namespace std;

/**********************************************************************
 * definition des SDL_Surface
**********************************************************************/

	SDL_Surface *wallpapergame;
	SDL_Surface *wallpapermenu;
	
/******************************************************************
 * definition des diamants
******************************************************************/
	
	diamond blue;
	diamond red;
	diamond dgreen;
	diamond lgreen;
	diamond purple;
	diamond pink;
	diamond orange;
	diamond yellow;
	
/*******************************************************************
 * definition des lecture diamants
*******************************************************************/
 
blue.lecture.w = 61; blue.lecture.h = 61; blue.lecture.x = 240; blue.lecture.y = 0;

red.lecture.w = 61; red.lecture.h = 61; red.lecture.x = 60; red.lecture.y = 0;

dgreen.lecture.w = 61; dgreen.lecture.h = 61; dgreen.lecture.x = 180; dgreen.lecture.y = 0;  	

lgreen.lecture.w = 61; lgreen.lecture.h = 61; lgreen.lecture.x = 360; lgreen.lecture.y = 0;	
	
purple.lecture.w = 61; purple.lecture.h = 61; purple.lecture.x = 120; purple.lecture.y = 0;

pink.lecture.w = 61; pink.lecture.h = 61; pink.lecture.x = 300; pink.lecture.y = 0;

orange.lecture.w = 61; orange.lecture.h = 61; orange.lecture.x = 0; orange.lecture.y = 0;

yellow.lecture.w = 61; yellow.lecture.h = 61; yellow.lecture.x = 420; yellow.lecture.y = 0;

/******************************************************************
 * chargement des images
*******************************************************************/
	
	blue.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	red.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	dgreen.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	lgreen.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	purple.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	pink.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	orange.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	yellow.img = loadimagecolorkey ("../ressources/pieces.bmp",0,255,255);
	
	
	wallpapergame = loadimage ("../ressources/fond.bmp");
	wallpapermenu = loadimage ("../ressources/title.bmp");
	

	
	
	
	

#endif
