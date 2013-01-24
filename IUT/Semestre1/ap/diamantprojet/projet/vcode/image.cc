#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

#include "image.hh"
#include "init.hh"

using namespace std;

/*******************************************************************
 * Copier coller d'une image vers une surface donné
*******************************************************************/

void 
pastesurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip)
{
  	SDL_Rect offset;
  	offset.x = x;
  	offset.y = y;
  	SDL_BlitSurface( source, clip, destination, &offset );
 }


/*******************************************************************
 * Chargement image
*******************************************************************/

SDL_Surface 
*loadimage (string filename)
{
	return SDL_DisplayFormat (IMG_Load( filename.c_str()));
}

/******************************************************************
 * Chargement image avec Color Key
*******************************************************************/

SDL_Surface 
*loadimagecolorkey (string filename, int r, int g, int b)
{
  SDL_Surface *optimg;
optimg = SDL_DisplayFormat(IMG_Load( filename.c_str()));
 SDL_SetColorKey(optimg, SDL_SRCCOLORKEY, SDL_MapRGB(optimg->format,r,g,b));
 return optimg;
}
