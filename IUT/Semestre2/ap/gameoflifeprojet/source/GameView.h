#ifndef GAMEVIEW_H
#define GAMEVIEW_H

/**
 * \file GameView.h
 * \brief View du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>
#include <string>

#include "Button.h"
#include "GameModel.h"
#include "MenuView.h"
#include "Element.h"

using namespace sf;

/** 
 * \class GameView
 * \brief classe qui gère la partie graphique du jeu
*/
class GameView : public Element
{
	private:
		RenderWindow* _window;
		GameModel* _model;
		MenuView* _menu;
		float _mouseX, _mouseY;
		
		Image _bgImg, _bgBar, _celluleImg, _virusImg, _selectImg;
		Sprite _bgSprite, _barSprite, _celluleSprite, _virusSprite, _selectSprite;
		String _nbVirus, _nbCellule,
				_valVirus, _valCellule;
		Clock clock;
		Button _buttonPar, _open, _save;	
	
	public:
	
/// ##################### CONSTRUCTEUR & DESTRUCTEUR ##################

		GameView(const float & w, const float & h, const float & x, const float & y );
		~GameView ( );
		
/// ##################### ACTION FENETRE DE JEU ##################
		
		void draw ( );
		bool treatEvents ( );
		void updateVal();
		
/// ##################### ACCESSEUR ##################	
		
		void setModel (GameModel* model );
		void setMenu ( MenuView* menu );
};

#endif // GAMEVIEW_H
