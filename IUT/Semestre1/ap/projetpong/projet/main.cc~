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

//======================================================================
// FONCTION 
//======================================================================


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // charger image simple |
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SDL_Surface *loadimage (string filename)
{
  return SDL_DisplayFormat(IMG_Load( filename.c_str()));
}

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // chargement image color key ||
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SDL_Surface *loadimagecolorkey (string filename, int r, int g, int b)
{
  SDL_Surface *optimg;
optimg = SDL_DisplayFormat(IMG_Load( filename.c_str()));
 SDL_SetColorKey(optimg, SDL_SRCCOLORKEY, SDL_MapRGB(optimg->format,r,g,b));
 return optimg;
}

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // copier coller surface |
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void pastesurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, clip, destination, &offset );
 }


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // la ball fait marqué un point
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int 
wallP1 (SDL_Rect &ball, int &mv_x, int &mv_y, int &score01)
{
  if(ball.x+BALL_HEIGHT>SCREEN_WIDTH) 
    {
      score01++;
      ball.x=SCREEN_WIDTH-(BALL_HEIGHT+100);
      ball.y=(SCREEN_HEIGHT/2)-(BALL_HEIGHT/2);
      mv_x*=-1;
      return 1;
    }
}
int  
wallP2 (SDL_Rect &ball, int &mv_x, int &mv_y, int &score02)
{  
  if(ball.x<0)
    {
      score02++;
      ball.x=100;
      ball.y=(SCREEN_HEIGHT/2)-(BALL_HEIGHT/2);
      mv_x*=-1;
      return 1;
    }
}

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // direction joueur |
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // colision : joeur / mure |
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void 
colisionmur ( SDL_Rect &player )
{
  if ( player.y < HBAR )
	player.y=HBAR;
      if ( player.y+PLAYER_HEIGHT > SCREEN_HEIGHT )
	player.y=SCREEN_HEIGHT-PLAYER_HEIGHT;
} 

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // colision : joueur / ball
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool 
colisionball ( SDL_Rect player, SDL_Rect ball )
{
  if ( ball.x < player.x+PLAYER_WIDTH && ball.x > player.x &&  ball.y < player.y+PLAYER_HEIGHT && ball.y > player.y )
	return 1;   
    
  else
    return 0;
}


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // met le jeu en pause
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void 
stop()
{
  bool go=0;
  SDL_Event event;
  while (go!=1)
    {
  SDL_WaitEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT: go=1;
      break;
    case SDL_KEYDOWN:
      if ( event.key.keysym.sym == SDLK_SPACE )
	go=1;
      break;
    }
  }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// convertisseur : entier -> lettre
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string 
convert(int n)
{
  ostringstream s;
  s << n;
  return s.str();
}


//======================================================================
// ACTION PRINCIPALE
//======================================================================


                //''''''''''''''''''''''''''''''''''''''''
                // pour ajouter une image, définir une SDL_Surface
                //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


int main(int argc, char* argv[]) 
{

  bool quit=false;

 
  SDL_Event event;


  SDL_Rect bargame;
  SDL_Rect ball;
  SDL_Rect player01;
  SDL_Rect player02;

          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // insertion des polices & couleur
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  TTF_Font *police = NULL;
  TTF_Font *police2 = NULL;

  SDL_Color white={255,255,255};

          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // definition des images
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  SDL_Surface *screen;

  SDL_Surface *wallpaper;
  SDL_Surface *ballimg;
  SDL_Surface *player01img;
  SDL_Surface *player02img;
  SDL_Surface *spriteboutton;
  SDL_Surface *acceuilimg;
  SDL_Surface *filletimg;
  SDL_Surface *aeropaus;


          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // defintion des textes
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                  //'''''''''''''''''''''''''''''''''''
                  // menu principal
                  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

  SDL_Surface *nom;
  SDL_Surface *nom2;
  SDL_Surface *groupe;
  SDL_Surface *year;

                  //'''''''''''''''''''''''''''''''''''
                  // bar de menu
                  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

  SDL_Surface *scoreP1;
  SDL_Surface *scoreP2;
  SDL_Surface *p1bar;
  SDL_Surface *p2bar;

                  //'''''''''''''''''''''''''''''''''''
                  // ecran de pause
                  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

  SDL_Surface *ready;
  SDL_Surface *paus;
  SDL_Surface *joueur1;
  SDL_Surface *joueur2;
  SDL_Surface *win;
  SDL_Surface *hit;
  SDL_Surface *start;
  SDL_Surface *menufin;
  SDL_Surface *continu;

          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // score en chaine de caractére
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  string sp1="0";
  string sp2="0";


  int score01=0;            // score du joueur01
  int score02=0;            // score du joueur02


                                  //??????????????????????????????????????????????????
                                  // utilité de "*"
                                  //??????????????????????????????????????????????????


          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // lecture partie de sprite |
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  SDL_Rect lecturep;
  lecturep.x=0;
  lecturep.y=100;
  lecturep.w=150;
  lecturep.h=60;

  SDL_Rect lectureq;
  lectureq.x=0;
  lectureq.y=0;
  lectureq.w=150;
  lectureq.h=60;

  SDL_Rect lecturepbis;
  lecturepbis.x=200;
  lecturepbis.y=100;
  lecturepbis.w=150;
  lecturepbis.h=60;

SDL_Rect lectureqbis;
  lectureqbis.x=200;
  lectureqbis.y=0;
  lectureqbis.w=150;
  lectureqbis.h=60;

  SDL_Rect lecturefillet;
  lecturefillet.x=0;
  lecturefillet.y=0;
  lecturefillet.w=4;
  lecturefillet.h=400;



          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          // initialisation
          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  int mv_x=VITESSE_BALL;
  int mv_y=VITESSE_BALL;

  bargame.x=0;
  bargame.y=0;
  bargame.w=SCREEN_WIDTH;
  bargame.h=HBAR;



  player01.x=30;
  player01.y=150;


  player02.x=SCREEN_WIDTH-PLAYER_WIDTH-30;
  player02.y=150;

  ball.x=100;
  ball.y=(SCREEN_HEIGHT/2)-(BALL_HEIGHT/2);

  SDL_Init(SDL_INIT_EVERYTHING);

 
 screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);



         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         // chargement du texte
         // couleur dispo : white
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  TTF_Init();

  police = TTF_OpenFont("police/game_over.ttf", 52);
  police2 = TTF_OpenFont("police/game_over.ttf", 80);


  nom = TTF_RenderText_Blended(police, "Arnaud Ladoucette", white);
  nom2 = TTF_RenderText_Blended(police, "Virgile Ygorra", white);
  groupe = TTF_RenderText_Blended(police, "S1C''", white);
  year = TTF_RenderText_Blended(police, "2010", white);
  paus = TTF_RenderText_Blended(police2, "PAUSE (press Space)", white);
  joueur1 = TTF_RenderText_Blended(police2, "PLAYER 1", white);
  joueur2 = TTF_RenderText_Blended(police2, "PLAYER 2", white);
  win = TTF_RenderText_Blended(police2, "WIN !", white);
  hit = TTF_RenderText_Blended(police2, "scores 1 point", white);
  start = TTF_RenderText_Blended(police2, "starts", white);
  menufin = TTF_RenderText_Blended(police2, "Press Space to return in main page", white);
  continu = TTF_RenderText_Blended(police2, "Press Space to continue", white);
  p1bar = TTF_RenderText_Blended(police, "Player 1", white);
  p2bar = TTF_RenderText_Blended(police, "Player 2", white);
  ready = TTF_RenderText_Blended(police2, "READY ?", white);

                  //'''''''''''''''''''''''''''''''''''
                  // inseret " .c_str() " pour afficher une var string
                  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

  scoreP1 = TTF_RenderText_Blended(police, sp1.c_str(), white);
  scoreP2 = TTF_RenderText_Blended(police, sp2.c_str(), white);

         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         // chargement des images
         //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
  acceuilimg = loadimage ("img/title.bmp");
  wallpaper = loadimage ("img/fond.bmp");
  ballimg = loadimagecolorkey ("img/ball.bmp",0,255,255);
  player01img = loadimagecolorkey ("img/player01.bmp",0,255,255);
  player02img = loadimagecolorkey ("img/player02.bmp",0,255,255);
  spriteboutton = loadimagecolorkey ("img/button.bmp",0,0,0);
  filletimg = loadimagecolorkey ("img/fillet.bmp",0,0,0);
  aeropaus = loadimagecolorkey ("img/pause.bmp",0,255,0);

//======================================================================
// BOUCLE PRINCIPALE
//======================================================================

  bool menu=0;

  while(!quit)
    {

SDL_WM_SetCaption("PONG !!!  (menu)", "ball.bmp");     

      SDL_FillRect(screen,&screen->clip_rect, SDL_MapRGB(screen->format,255,255,255));

      pastesurface(0,0,acceuilimg,screen,NULL);     
      pastesurface(245,235,spriteboutton,screen,&lecturep);
      pastesurface(245,305,spriteboutton,screen,&lectureq);
     
      pastesurface(450,0,nom,screen,NULL);
      pastesurface(485,30,nom2,screen,NULL);
      pastesurface(585,75,groupe,screen,0);
      pastesurface(585,360,year,screen,0);



              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // si le curseur passe au dessus d'une surface
              // alors il y a un changement de couleur des bouton
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


      if ( event.type == SDL_MOUSEMOTION )
	{
	  int mx = event.motion.x;
	  int my = event.motion.y;

	  if ( (mx>245) && (mx<395) && (my>235) && (my<295) )
	    pastesurface(245,235,spriteboutton,screen,&lecturepbis);

	  if ( (mx>245) && (mx<395) && (my>305) && (my<365) )
	    pastesurface(245,305,spriteboutton,screen,&lectureqbis);
	}
			

              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // evenements attendu 
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


      SDL_WaitEvent(&event);
      switch(event.type)
	{

	case SDL_QUIT:        // si on quitte la fenetre
	  quit = true;
	  break;

	case SDL_MOUSEBUTTONUP:
	  if (event.button.button == SDL_BUTTON_LEFT)
   
	    {  // debut case : boutton sourie

	      int bx = event.button.x;
	      int by = event.button.y;


        if ( (bx>245) && (bx<395) && (by>235) && (by<295) )
	  {  // (1)

	    menu=0;
	    bool debut=0;
	    score01=0;
	    score02=0;



//======================================================================
// BOUCLE JEU
//======================================================================


            //''''''''''''''''''''''''''''''''''''''''
            // lorsqu'on quitte la fenetre, on revient imediatement sur le menu
            //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

	    

  while(menu!=1)
    {



      SDL_WM_SetCaption("PONG !!!  (jeu)", "ball.bmp");

      Uint8 *keystates = SDL_GetKeyState(NULL);
      
 
      pastesurface(0,0,wallpaper,screen,NULL);                       // wallpaper
      pastesurface(ball.x,ball.y,ballimg,screen,NULL);               // ball     
      pastesurface(player01.x,player01.y,player01img,screen,NULL);   // player 1
      pastesurface(player02.x,player02.y,player02img,screen,NULL);   // player 2


       SDL_FillRect(screen, &bargame,  SDL_MapRGB(screen->format,0,0,0));

 
             //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // mise a jour des scores des joueurs
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      sp1=convert(score01);
      scoreP1 = TTF_RenderText_Blended(police, sp1.c_str(), white);
      sp2=convert(score02);
      scoreP2 = TTF_RenderText_Blended(police, sp2.c_str(), white);


      pastesurface(0,-3,p1bar,screen,0);
      pastesurface(554,-3,p2bar,screen,0);
      pastesurface(260,-3,scoreP1,screen,0);
      pastesurface(366,-3,scoreP2,screen,0);


 
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // ready ???
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      if (debut == 0)
	{
	  pastesurface(0,0,aeropaus,screen,NULL);
	  pastesurface(240,200,ready,screen,NULL);
	  pastesurface(130,300,continu,screen,NULL);
	  SDL_Flip(screen);
	  stop();
	  debut=1;
	}

         pastesurface(320,0,filletimg,screen,&lecturefillet);

    
      SDL_Flip(screen);

 
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // score maximum
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      if (score01==10 || score02 == 10)
	{
	  SDL_Flip(screen);
	  pastesurface(0,0,aeropaus,screen,NULL);
	  if (score01==10)
	    pastesurface(130,100,joueur1,screen,NULL);
	  else
	    pastesurface(130,100,joueur2,screen,NULL);

	  pastesurface(350,100,win,screen,NULL);
	  pastesurface(50,300,menufin,screen,NULL);
	  SDL_Flip(screen);
     
	  stop();
	  menu=1;
  	}
       

      while(SDL_PollEvent(&event))
	if(event.type==SDL_QUIT)
	  menu=1;


      ball.x+=mv_x;                  // ball.x = ball.x + mv_x 
      ball.y+=mv_y;

      SDL_Delay(16);

      /* rebond ball */       rebond(ball, mv_x, mv_y);


      /* mouv ball   */      mouvball ( player01, player02 );
      /* colision P1 */      colisionmur ( player01 );
      /* colision P2 */      colisionmur ( player02 ) ;


              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // si le joueur 1 marque un point :
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				 
      if (wallP1 ( ball, mv_x, mv_y, score01)==1)
	{
SDL_WM_SetCaption("PONG !!!  (PLAYER 1 +)", "ball.bmp");     
	  pastesurface(0,0,aeropaus,screen,NULL);
	  pastesurface(130,100,joueur1,screen,NULL);
	  pastesurface(350,100,hit,screen,NULL);
	  pastesurface(130,150,joueur2,screen,NULL);
	  pastesurface(350,150,start,screen,NULL);
	  pastesurface(130,300,continu,screen,NULL);
	  SDL_Flip(screen);
	stop();
	}

              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // si le joueur 1 marque un point :
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				 
      if (wallP2 ( ball, mv_x, mv_y, score02)==1)
	{
SDL_WM_SetCaption("PONG !!!  (PLAYER 2 +)", "ball.bmp");     
	  pastesurface(0,0,aeropaus,screen,NULL);
	  pastesurface(130,100,joueur2,screen,NULL);
	  pastesurface(350,100,hit,screen,NULL);
	  pastesurface(130,150,joueur1,screen,NULL);
	  pastesurface(350,150,start,screen,NULL);
	  pastesurface(130,300,continu,screen,NULL);
	  SDL_Flip(screen);
	stop();
	}

              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // colision entre joueurs et ball
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      if ( colisionball(player01, ball)==1 )
	{
	  ball.x=player01.x+PLAYER_WIDTH;
	  mv_x*=-1;
	}
      
      if ( colisionball(player02, ball)==1 )
	{
	  ball.x=player02.x;
	  mv_x*=-1;
	}

              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              // PAUSE lorsqu'on appuie sur "p"
              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      if ( keystates[SDLK_p] )
	{
  SDL_WM_SetCaption("PONG !!!  (PAUSE)", "ball.bmp");
	  pastesurface(0,0,aeropaus,screen,NULL);
	  pastesurface(180,180,paus,screen,NULL);
	  SDL_Flip(screen);
	  stop();
	}


    }


  //======================================================================


	  } // fin du (1)
	
	  
		else if  ( (bx>245) && (bx<395) && (by>305) && (by<365) )
	  quit = true;
	break;
	
	    }  // fin case : boutton sourie
	  

	  
	}  // fin du switch : WaitEvent


      SDL_Flip(screen);

      SDL_Delay(0);

      
    }  // fin de la boucle principale


  TTF_CloseFont(police);
  TTF_Quit();
  

  SDL_FreeSurface(screen);
  SDL_Quit();
  return EXIT_SUCCESS;
}
