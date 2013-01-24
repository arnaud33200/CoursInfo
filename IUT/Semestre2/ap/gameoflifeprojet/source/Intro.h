#ifndef INTRO_H
#define INTRO_H

/**
 * \file Intro.h
 * \brief introduction du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Button.h"

using namespace sf;

/** 
 * \class Intro
 * \brief classe qui gère l'introduction
*/
class Intro
{
	private:
	
		RenderWindow* _window;
		float _mouseX, _mouseY;
		int _i;
		Clock _time;
		
		Image _bgImg, _meduseImg, _introImg, _iutImg, _autorImg;
		Sprite _bgSprite, _meduseSprite, _introSprite, _iutSprite, _autorSprite;
		Button _next;
		Music _start;
		
		
	public :
	
		Intro();
		~Intro();
		void draw();
		bool treatEvents ();
		void animation();
		bool timePassedAfter( const float & t );
};

#endif // INTRO_H
