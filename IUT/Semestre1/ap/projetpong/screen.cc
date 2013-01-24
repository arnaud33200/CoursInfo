// screen.cc

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=820;
const int SCREEN_BPP=32;

int
main(int argc, char* argv[])
{
  bool quit=false;

  SDL_Surface *screen;
  SDL_Event event;
  SDL_Rect rect;

  rect.x=0;
  rect.y=0;
  rect.w=20;
  rect.h=20;
 

  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);

  change=0;

  while(!quit)
    {
    SDL_FillRect(screen,&rect,  
           SDL_MapRGB(screen->format,255,255,0));


  


 rect.x=rect.x+1;
    rect.y=rect.y+1;
    rect.w=rect.w+1;
    rect.h=rect.h+1;
 
  
      SDL_Flip(screen);

      while(SDL_PollEvent(&event))
    if(event.type==SDL_QUIT)
        quit=true;
    }

  SDL_FreeSurface(screen);
  SDL_Quit();
  return EXIT_SUCCESS;   
}
