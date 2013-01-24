#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
#include <SDL/SDL_ttf.h>
#include<fstream>
#include<sstream>

#include "move.h"
#include "const.h"

using namespace std;

void 
mouvball ( SDL_Rect & player01, SDL_Rect & player02)
{
  Uint8 *keystates = SDL_GetKeyState( NULL ) ;

      if ( keystates [ SDLK_UP ] )
	player02.y-=VITESSE_PLAYER;
      if ( keystates [ SDLK_DOWN ] )
	player02.y+=VITESSE_PLAYER;
      if ( keystates [ SDLK_z ] )
	player01.y-=VITESSE_PLAYER;
      if ( keystates [ SDLK_s ] )
	player01.y+=VITESSE_PLAYER;
}


void
rebond ( SDL_Rect &ball, int &mv_x, int &mv_y)
{  
  if(ball.y+BALL_HEIGHT>SCREEN_HEIGHT) 
    {
      ball.y=SCREEN_HEIGHT-BALL_HEIGHT;
      mv_y*=-1;
    }

  if(ball.y<HBAR)
    {
      ball.y=HBAR;
      mv_y*=-1;
    }
}
