/**
 * \file main.cc
 * \brief main du programme
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include "GameModel.h"
#include "GameView.h"
#include "MenuView.h"
#include "util.h"
#include "Intro.h"

using namespace std;

const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 600;
const float PAR_WIDTH = 198;
const float PAR_HEIGHT = 600;

int main()
{
	srand(time(NULL));

///~~ COMMENTER CETTE PARTIE POUR ENLEVER L'INTRODUCTION
// DEBUT
	Intro* introjeu = new Intro;
  	while(introjeu->treatEvents())
  	{ introjeu->draw(); }
  	delete introjeu;
// FIN
	
	GameModel * model = new GameModel(SCREEN_WIDTH, SCREEN_HEIGHT);
	
 	MenuView * menuView = new MenuView(PAR_WIDTH, PAR_HEIGHT, 0, 0);
 	GameView * gameView = new GameView(SCREEN_WIDTH, SCREEN_HEIGHT+30, 210, 0);
 	
  	gameView->setModel(model);
  	gameView->setMenu(menuView);
  	menuView->setModel(model);

  	while(gameView->treatEvents())
  	{
  		menuView->treatEvents();
  		model->nextStep();
  		gameView->draw();
  		menuView->draw();
  	}
	
	delete gameView; 
	delete menuView; 
	delete model; 
  	
	return EXIT_SUCCESS;
}
