#ifndef BUTTON_H
#define BUTTON_H

#include "Element.h"


class Button : public Element
{
	private:
		sf::String _nomButton;
		sf::Sprite _buttonSprite;
		sf::String _texte;
		bool _press, _hover, _keep;
		sf::Image* _buttonImg;
		sf::Font* _font;

	public:

/// ####################### CONSTRUCTEUR DESTRUCTEUR ###################

		Button(const float & x, const float & y, const float & w, const float & h,const bool & keep,
				const std::string & txt, const int & tx, const int & ty, const int & tt );
		~Button();

/// ####################### ACTION BUTTON ##############################

		void changeSprite(const float & x, const float & y, const float & w, const float & h);

/// ####################### ACCESSEURS ################################

		sf::String getTxt() const;
		sf::Sprite getSprite() const;
		bool getPress() const;
		bool getHover() const;
		bool getKeep() const;

		void setTxt( const sf::String & txt );
		void setPress( const bool & p );
		void setHover( const bool & h );
		void setColor( int r, int g, int b );

};

#endif // BUTTON_H
