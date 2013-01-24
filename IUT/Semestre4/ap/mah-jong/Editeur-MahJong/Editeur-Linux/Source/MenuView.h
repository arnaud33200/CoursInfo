#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "Button.h"
#include "GameModel.h"
#include "GameView.h"


/**
 * \class MenuView
 * \brief classe qui gère la partie graphique du jeu
*/
class MenuView : public Element
{
///################ ATRIBUTS ####################
	private:
		GameModel * _model;
		GameView * _game;
		sf::RenderWindow * _window;
		int _mouseX, _mouseY;

	// ~~~~~~~~~~~~~ IMAGES & SPRITES ~~~~~~~~~~~~~

		vector<sf::Sprite> my_spriteColor;

		sf::Image my_tile_image;
		sf::Sprite my_tile_sprite;
		sf::Image my_bgImg;
		sf::Sprite my_bgSpt;
		sf::Font my_font;
		sf::String _viewD, _viewE, _viewF, _infoTuile, _savimp, _numEtage, _messAlert;

	// ~~~~~~~~~~~~~ BOUTTON ~~~~~~~~~~~~~
		Button my_newButton, my_loadButton, my_saveButton, my_quitButton,
			my_mdButton, my_ldButton,
			my_meButton, my_leButton,
			my_mfButton, my_lfButton;

	public:

/// ################# CONSTRUCTEUR DESTRUCTEUR ###############
		MenuView(const float & w, const float & h, const float & x, const float & y );
		~MenuView ( );

/// ################# ACTION FENETRE #################
		void draw ( );
		bool treatEvents( );
		void openWindow(const bool & open, int x, int y);

/// ################# ACCESSEURS MENU #################
		bool getWindow() const;
		void setPt (GameModel * model, GameView * game );
		void addD( int a );
		void addE( int a );
		void addF( int a );
		void updateInfo();
};

#endif // MENUVIEW_H
