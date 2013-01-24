// ball02.cc

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
const int SCREEN_BPP=32;

const int TAILLE=20;

int
main(int argc, char* argv[])
{
  bool quit=false;

  SDL_Surface *screen;
  SDL_Event event;
 
  SDL_Rect ball;
 
  ball.x=SCREEN_WIDTH/2-TAILLE/2;
  ball.y=SCREEN_HEIGHT/2-TAILLE/2;
  ball.w=TAILLE;
  ball.h=TAILLE;

  int mvt_x=2;
  int mvt_y=2;

  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,
              SCREEN_BPP,SDL_SWSURFACE);

  while(!quit)
    {
      SDL_FillRect(screen,&screen->clip_rect,
           SDL_MapRGB(screen->format,255,255,255));

      SDL_FillRect(screen,&ball,
           SDL_MapRGB(screen->format,255,0,0));

      SDL_Flip(screen);

      while(SDL_PollEvent(&event))
    if(event.type==SDL_QUIT)
        quit=true;

      ball.x+=mvt_x;
      ball.y+=mvt_y;

      // Correction Mouvement Horizontal
      if(ball.x+TAILLE>SCREEN_WIDTH)
    {
      ball.x=SCREEN_WIDTH-TAILLE;
      mvt_x*=-1;
    }
      if(ball.x<0)
    {
      ball.x=0;
      mvt_x*=-1;
    }
     
      // Correction Mouvement Vertical
      if(ball.y+TAILLE>SCREEN_HEIGHT)
    {
      ball.y=SCREEN_HEIGHT-TAILLE;
      mvt_y*=-1;
    }
      if(ball.y<0)
    {
      ball.y=0;
      mvt_y*=-1;
    }
      SDL_Delay(10);
    }

  SDL_FreeSurface(screen);
  SDL_Quit();
  return EXIT_SUCCESS;   
}
