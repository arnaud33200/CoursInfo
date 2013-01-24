#ifndef IMAGE_HH
#define IMAGE_HH

#include <string>

#include "SDL.h"
#include "SDL_image.h"

using namespace std;

/************* Copier-coller d'une image *********************/
void pastesurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip);


/************* Charge une image a partir d'un fichier ********/
SDL_Surface *loadimage (string filename);


/************* Charge une image avec le color key ************/
SDL_Surface *loadimagecolorkey (string filename, int r, int g, int b);

#endif
