#ifndef _GAMEVIEW_
#define _GAMEVIEW_

#include "GameModel.h"

class GameModel;

class GameView
{
	private:
/// ################# ATTRIBUTS #################
		int my_w, my_h;
		GameModel * my_model;
		std::vector<sf::Sprite> my_spriteColor;
		bool my_quit;

		sf::RenderWindow * my_window;

		sf::Image my_selection_image;
		sf::Image my_quadrillage_image;
		sf::Image my_tile_image;

		sf::Sprite my_selection_sprite;
		sf::Sprite my_quadrillage_sprite;
		sf::Sprite my_tile_sprite;

	public:
///################ CONSTRUCTEURS & DESTRUCTEURS ####################
		GameView(const int &w, const int &h);
		~GameView();

/// ################# ACTION FENETRE #################		
		void draw();
		void drawTile();
		bool treatEvents();
		void eventSelection(const sf::Input &input);
		void eventPoseTile(const sf::Input &input);

///################ ACCESSEURS ####################
		void quit();
		void setModel(GameModel * model);

};
#endif


