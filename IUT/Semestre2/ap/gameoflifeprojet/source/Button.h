#ifndef BUTTON_H
#define BUTTON_H

/**
 * \file Button.h
 * \brief boutton avec un texte
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include <SFML/Graphics.hpp>
#include <string>

#include "Element.h"

using namespace std;
using namespace sf;


/** 
 * \class Button
 * \brief classe qui gère les boutons
*/
class Button : public Element
{
	private:
		string _nomButton;
		Sprite _buttonSprite;
		String _texte;
		bool _press, _hover, _keep;
		Image* _buttonImg;
		Font* _font;
		
	public:

/// ####################### CONSTRUCTEUR DESTRUCTEUR ###################

		Button(const float & x, const float & y, const float & w, const float & h,const bool & keep,
				const string & txt, const int & tx, const int & ty, const int & tt );
		~Button();

/// ####################### ACTION BUTTON ##############################
		
		void changeSprite(const float & x, const float & y, const float & w, const float & h);
		
/// ####################### ACCESSEURS ################################	
		
		String getTxt() const;
		Sprite getSprite() const;
		bool getPress() const;
		bool getHover() const;
		bool getKeep() const;
		
		void setTxt( const string & txt );
		void setPress( const bool & p );
		void setHover( const bool & h );

};

#endif // BUTTON_H
