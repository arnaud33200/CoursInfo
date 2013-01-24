/**
 * \file GameView.cc
 * \brief View du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameView.h"
#include "Button.h"
#include "image.h"
#include "util.h"
#include "event.h"

using namespace std;
using namespace sf;

static sf::Font* _font;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn GameView::GameView(const float & w, const float & h, const float & x, const float & y )
 * \brief constructeur par paramétre du GameView
 * \param w,h des réels pour indiqué la taille de la fenêtre
 * \param x,y des réels pour definir la position de la fenêtre
 */
GameView::GameView(const float & w, const float & h, const float & x, const float & y )
: Element(x, y, w, h),
_buttonPar( 680, 0, 120, 30, 0, "Parametre", 12, 1, 20),
_open(380, 0, 100, 30, 0, "Ouvrir", 22, 1, 20),
_save(490, 0, 100, 30, 0, "Charger", 18, 1, 20)

{
	_window = new RenderWindow(sf::VideoMode(w, h, 32), "Game Of Life", sf::Style::Close );  //| sf::Style::Resize
	_window->SetPosition(x,y);
	
	loadimage(_bgImg, _bgSprite, "images/bg.png",0,0,800,630);
	loadimage(_bgBar, _barSprite,"images/bg_bar.png");
	loadimage(_celluleImg, _celluleSprite, "images/cell.png");
	loadimage(_virusImg, _virusSprite, "images/virus.png");
	loadimage(_selectImg, _selectSprite, "images/rect.png");
	
	_font = new Font();
	_font->LoadFromFile("images/antique.ttf");
	
	loadtextefont( _nbCellule, _font, 17, 5, 4, "Cellule : ");
	loadtextefont( _nbVirus, _font, 17, 200, 4, "Virus : ");
	
	loadtextefont( _valCellule, _font, 17, 70, 4, "0" );
	loadtextefont( _valVirus, _font, 17, 260, 4, "0" );

}

 GameView::~GameView ( )
{
	if(_window!= NULL)
	{
    	delete _window; 
	}
    delete _font;
}


/*#############################################################################
/#                                                                            #
/#            ACTION FENETRE DE JEU                                           #
/#                                                                            #
##############################################################################*/

/**
 * \fn GameView::updateVal()
 * \brief met a jour le texte d'information des Cellules et Virus
 * \param rien
 * \return rien
 */
void GameView::updateVal()
{
	int vi, ci, cj;
	_model->getTailleGrilleCellule(ci, cj);
	vi = _model->getSizeGroupeVirus();

	_valVirus.SetText( toString(vi)  );
	_valCellule.SetText( toString(cj) + " X " + toString(ci) );
}

/**
 * \fn GameView::draw()
 * \brief dessine les objets sur la fenetre de jeu
 * \param rien
 * \return rien
 */
void GameView::draw()
{	
	//~ int ti, tj; _model->getTailleGrilleCellule(ti,tj);
	
	_window->Draw(_bgSprite);

	afficherCellules(_model, _window, &_celluleSprite);
	afficherVirus(_model, _window, &_virusSprite );
	
// ~~~~~~~~~~~~ AFFICHAGE DU TEXTE ~~~~~~~~~~~~~~~~~~~~~~~
	
	_window->Draw(_barSprite);
	afficherButton( _window, &_buttonPar );
	afficherButton( _window, &_open );
	afficherButton( _window, &_save );
	
	_window->Draw( _nbCellule );
	_window->Draw( _nbVirus );
	
	if ( _mouseX >= 0 && _mouseX < _w && _mouseY >= 30 && _mouseY < _h )
		//~ afficherselect( _window, &_selectSprite,  ( _mouseX * ti ) / _w, (_mouseY * tj )/ (_h-30.0), _w/ti, (_h-30)/tj);
	
	updateVal();
	_window->Draw( _valCellule );
	_window->Draw( _valVirus );
		
	_window->Display();
	
// permet d'avoir un usleep constant en fonction de si la fenetre est ouvert ou pas
	if ( _menu->getWindow() ) 
		usleep(10000);
	else
		usleep(20000);
}

/**
 * \fn GameView::treatEvents()
 * \brief traite les évenements qu'effectue le joueur
 * \param rien
 * \return rien
 */
bool GameView::treatEvents()
{
	bool result = false;
 	if(_window->IsOpened())
 	{
    	result = true;
    	sf::Event event;
    	
   		while ( _window->GetEvent(event) )
   		{
  
// ~~~~~~~~~ FERMER LA FENETRE DE JEU ~~~~~~~~~~~~~~~~~~~~~~
   			Key::Code key = Key::Escape;
   			
   			
     		if ((event.Type == Event::Closed) || keyPress( &event, Key::Escape) ) 
	 		{
				result = false;
     		}
     		
// ~~~~~~~~~ RECUPERE COORDONNE SOURIE ~~~~~~~~~~~~~~~~~~~~~
     		
     		_mouseX = _window->GetInput().GetMouseX();
     		_mouseY = _window->GetInput().GetMouseY();

     		
// ~~~~~~~~~ DONNER VIE OU MORT D'UNE CELLULE ~~~~~~~~~~~~~~
     		
     		_model->alive_cellule( &event, _mouseX, _mouseY);
     		_model->dead_cellule( &event, _mouseX, _mouseY);	


// ~~~~~~~~~~ OUVRIR FENETRE DE PARAMETRE ~~~~~~~~~~~~~~~~~
			
			_menu->openWindow( clickButton( &event, _mouseX, _mouseY,  &_buttonPar) ,_x - 110, _y);
			
			_model->play_pause( keyPress( &event, Key::Space ) );
			
			_model->loadSave( clickButton( &event, _mouseX, _mouseY,  &_open) );
			_model->saveSave( clickButton( &event, _mouseX, _mouseY,  &_save) );						
     	}
	}
	return result;
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/

void GameView::setModel(GameModel* model )
{ _model = model; }

void GameView::setMenu( MenuView* menu )
{ _menu = menu; }
