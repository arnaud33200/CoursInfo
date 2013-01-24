// event.cc

#include<iostream>
#include<cstdlib>
#include<string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;


//-- structure permettant de rassembler une image avec ses coordonnées
struct Sprite
{
  int x;     // abscisse
  int y;     // ordonnée
  bool front; //booléen indiquant si le personnage est de face
  SDL_Surface *source;
  SDL_Rect lecture;
  SDL_Rect lectureFront;
  SDL_Rect lectureBack;
};

// -- initSprite ---------------------------------
// initialisation d'un sprite passé en référence
// ----------------------------------------------
void
initSprite(Sprite &s)
{
  s.x=340;
  s.y=200;
  s.front = true;
  s.lectureFront.x=40;
  s.lectureFront.y=0;
  s.lectureFront.w=40;
  s.lectureFront.h=60;
  s.lectureBack.x=40;
  s.lectureBack.y=120;
  s.lectureBack.w=40;
  s.lectureBack.h=60;
  s.lecture = s.lectureFront;
}

// -- loadImage ---------------------------------
// chargement d'une image
// cf atelier03 pour plus d'explication
// ----------------------------------------------

SDL_Surface *
loadImage(string filename)
{
     return SDL_DisplayFormat(IMG_Load( filename.c_str()));
}

// -- loadImageWithColorKey ---------------------
// chargement d'une image
// cf atelier03 pour plus d'explication
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
// cf atelier03 pour plus d'explication
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

  Sprite mon_sprite;
  initSprite(mon_sprite);

  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

  mon_sprite.source=loadImageWithColorKey("sprite.png",82,123,156);

  while(quit==false)
    {
      SDL_FillRect(screen,&screen->clip_rect,
           SDL_MapRGB(screen->format,255,255,255));

      applySurface(mon_sprite.x,mon_sprite.y,mon_sprite.source,screen,&mon_sprite.lecture);
     

      SDL_Flip(screen);
     
      //lecture des évènements dans la queue d'évènements
      while(SDL_PollEvent(&event))
    {
      //événement de fermeture d'application, on sort la boucle
      if( event.type == SDL_QUIT )
            {
          quit = true;
            }
     
      //
      // Partie 1
      //
      // touche appuyée
      else if( event.type == SDL_KEYDOWN )
            {
          //associons pour chaque flèche directionnelle le bon déplacement
          switch( event.key.keysym.sym )
                {
        case SDLK_UP: mon_sprite.y-=5; break;
        case SDLK_DOWN: mon_sprite.y+=5; break;
        case SDLK_LEFT: mon_sprite.x-=5; break;
        case SDLK_RIGHT: mon_sprite.x+=5; break;
                }
            }

      //
      // Partie 2
      //
      // touche relâchée
      /* else if(event.type == SDL_KEYUP )
            {
          //associons pour chaque flèche directionnelle un déplacement plus important
          switch( event.key.keysym.sym )
                {
        case SDLK_UP: mon_sprite.y-=50; break;
        case SDLK_DOWN: mon_sprite.y+=50; break;
        case SDLK_LEFT: mon_sprite.x-=50; break;
        case SDLK_RIGHT: mon_sprite.x+=50; break;
                }
		} */
      
      //
      // Partie 3
      //
      // événements souris
      /*else if( event.type == SDL_MOUSEBUTTONDOWN )
        {
          //les coordonnées de la souris
          int x = event.button.x;
          int y = event.button.y;
         
          if( ( x < mon_sprite.x ) || ( x > mon_sprite.x + mon_sprite.lecture.w ) ||
          ( y < mon_sprite.y ) || ( y > mon_sprite.y + mon_sprite.lecture.h ) )
        {
          switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
              mon_sprite.x+= (x-mon_sprite.x)/5;
              mon_sprite.y+= (y-mon_sprite.y)/5;
              break;
            case SDL_BUTTON_RIGHT:
              mon_sprite.x-= (x-mon_sprite.x)/5;
              mon_sprite.y-= (y-mon_sprite.y)/5;
              break;
            }
        }
          else{
        if( mon_sprite.front){
          mon_sprite.lecture = mon_sprite.lectureBack;
          mon_sprite.front=false;
        }
        else{
          mon_sprite.lecture = mon_sprite.lectureFront;
          mon_sprite.front=true;
        }
          }
          }
      */
    }

      //
      // Partie 4
      //
      //gestion des états des touches
     
      Uint8 *keystates = SDL_GetKeyState( NULL );
   
      //If up is pressed
      if( keystates[ SDLK_UP ] )
    mon_sprite.y-=1;
     
      //If down is pressed
      if( keystates[ SDLK_DOWN ] )
    mon_sprite.y+=1;
     
      //If left is pressed
      if( keystates[ SDLK_LEFT ] )
    mon_sprite.x-=1;
     
      //If right is pressed
      if( keystates[ SDLK_RIGHT ] )
    mon_sprite.x+=1;
      
     
    }

  SDL_FreeSurface(screen);//Free the image
  SDL_Quit();//Quit SDL
  return EXIT_SUCCESS;   
}
