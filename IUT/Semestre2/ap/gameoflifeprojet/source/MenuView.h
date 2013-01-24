/**
 * \file MenuView.h
 * \brief View du menu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Button.h"
#include "Slider.h"
#include "GameModel.h"
#include "Element.h"

using namespace sf;

/** 
 * \class MenuView
 * \brief classe qui gère la partie graphique du jeu
*/
class MenuView : public Element
{
///################ ATRIBUTS ####################
	private:
		GameModel * _model;
		RenderWindow* _window;		
		tab _onglet;
		int _mouseX, _mouseY;
				
	// ~~~~~~~~~~~~~ IMAGES & SPRITES ~~~~~~~~~~~~~
		
		Image _bgCellImg, _bgVirusImg;
		Sprite _bgCellSprite, _bgVirusSprite;
		
	// ~~~~~~~~~~~~~ BOUTTON ~~~~~~~~~~~~~

		Button 	_playButton,
				_addColum, _removeColum, _addLine, _removeLine,
				_addVirus, _removeVirus, _removeAllVirus, _updateAll;
		
	// ~~~~~~~~~~~~~ SLIDER ~~~~~~~~~~~~~

		Slider 	_vitesseJeu, 
				_minAliveCellule, _maxAliveCellule, _minDeadCellule, _maxDeadCellule, _aleaCellule, _aleaResist,
				_nbEnfantVirus, _tmpLifeVirus, _tmpIncubVirus;

	public:
	
/// ################# CONSTRUCTEUR DESTRUCTEUR ###############	
	
		MenuView(const float & w, const float & h, const float & x, const float & y );
		~MenuView ( );
		
/// ################# ACTION FENETRE #################
		
		void draw ( );
		bool treatEvents ( );
		void updateSlider();
		void openWindow(const bool & open, int x, int y);
		
/// ################# CHANGEMENT ONGLETS ################
		
		void changeTabCellule( const bool & t );
		void changeTabVirus( const bool & t );
		
/// ################# ACCESSEURS MENU #################
		
		bool getWindow() const;
		void setModel (GameModel * model );
		//~ void setValVitesse( const int & v );
};

#endif // MENUVIEW_H
