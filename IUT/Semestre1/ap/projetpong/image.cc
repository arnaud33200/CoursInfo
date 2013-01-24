#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

// -- loadImage ---------------------------------
// chargement d'une image
// ----------------------------------------------

SDL_Surface *
loadImage(string filename) 
{
     return SDL_DisplayFormat(IMG_Load( filename.c_str()));
}

// -- loadImageWithColorKey ---------------------
// chargement d'une image
// * paramètres entrées :
// - "filename" : nom de l'image
// - "r,g,b"    : couleur de la ColorKey; cette 
//   couleur devient transparente !
// * paramètre de sortie : SDL_Surface contenant 
//   l'image. 
// ----------------------------------------------

SDL_Surface *
loadImageWithColorKey(string filename, int r, int g, int b) 
{
    SDL_Surface* optimizedImage;
    optimizedImage = SDL_DisplayFormat(IMG_Load( filename.c_str()));
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, 
            SDL_MapRGB(optimizedImage->format, r, g, b));
    return optimizedImage;
}

// -- applySurface ------------------------------
// c'est le copier-coller d'une surface sur une 
// autre : on colle le rectangle "clip" de "source" 
// sur "destination" à partir de "x,y"
// ----------------------------------------------

void 
applySurface(int x, int y, SDL_Surface* source, 
         SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}


int 
main(int argc, char* argv[])
{
  bool quit=false;

  SDL_Surface *screen;
  SDL_Event event;
  SDL_Surface *source01;
  SDL_Surface *source02;
  
  SDL_Rect lecture;
  lecture.x=0;
  lecture.y=0;
  lecture.w=40;
  lecture.h=60;

  SDL_Rect lectureBis;
  lectureBis.x=40;
  lectureBis.y=0;
  lectureBis.w=40;
  lectureBis.h=60;

  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

  source01=loadImage("sprite.png");
  source02=loadImageWithColorKey("sprite.png",82,123,156);

  while(!quit)
    {
      SDL_FillRect(screen,&screen->clip_rect, 
           SDL_MapRGB(screen->format,255,255,255));

      // Partie 1

      //applySurface(0,0,source01,screen,NULL);
      //applySurface(100,0,source01,screen,NULL);
      //applySurface(0,100,source01,screen,NULL);
      //applySurface(240,100,source01,screen,NULL);
      //applySurface(240,100,source01,screen,&lecture);
      //applySurface(240,100,source02,screen,&lecture);
      

      // Partie 2

      /*
    applySurface(240,100,source02,screen,&lecture);
    applySurface(340,200,source02,screen,&lectureBis);
      */

      SDL_Flip(screen);

      while(SDL_PollEvent(&event))
    if(event.type==SDL_QUIT)
        quit=true;

      SDL_Delay(100);
    }

  SDL_FreeSurface(screen);
  SDL_Quit();
  return EXIT_SUCCESS;    
}
