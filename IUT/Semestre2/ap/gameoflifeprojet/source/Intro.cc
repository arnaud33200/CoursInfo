/**
 * \file Intro.cc
 * \brief introduction du jeu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include "Intro.h"
#include "event.h"
#include "image.h"

using namespace std;
using namespace sf;

Intro::Intro()
: _i(0), _next(654,8,138,44,0,"Passer l'intro", 12, 11, 18) 
{
	if (!_start.OpenFromFile("musics/intro.ogg"))
	{
		cout << "erreur dans l'ouverture du fichier musique" << endl;
		//~ exit -1;
	}
	else
		_start.Play();
	
	_window = new RenderWindow(sf::VideoMode(800, 600, 32), "Game Of Life", sf::Style::Close );  //| sf::Style::Resize
	_window->SetPosition(0,0);
	
	loadimage( _bgImg, _bgSprite, "images/bg.png");
	loadimage( _meduseImg, _meduseSprite, "images/meduse.png");
	loadimage( _introImg, _introSprite, "images/txtanim.png");
	loadimage( _iutImg, _iutSprite, "images/iut.png");
	loadimage( _autorImg, _autorSprite, "images/auteur.png");
	
	setSprite( _meduseSprite, 358, 0, 358, 298 );
	sizepositionimg( _meduseSprite, -358, 176, 358, 298 );
	setSprite( _introSprite, 0,0,0,0);
	sizepositionimg( _introSprite, 222, 336, 656, 147 );
	sizepositionimg( _bgSprite, 0, 0, 800, 600);
	sizepositionimg( _iutSprite, 7, 7, 112, 98 );
	sizepositionimg( _autorSprite, 4,559,689,34);
	
	_time.Reset();

}

Intro::~Intro()
{
	if( _window!= NULL )
    	delete _window;
}
 
void Intro::draw()
{
	if ( _time.GetElapsedTime() >= 0.1 && _meduseSprite.GetPosition().x <= 800 )
	{
		animation();
		_time.Reset();
	}
	_window->Draw( _bgSprite );
	afficherButton(_window, &_next);
	_window->Draw( _introSprite );
	_window->Draw( _meduseSprite );
	if ( timePassedAfter(0.6) ) _window->Draw( _iutSprite );
	if ( timePassedAfter(0.9) ) _window->Draw( _autorSprite);
	usleep(40000);
	_window->Display();
}

bool Intro::treatEvents()
{
bool result = false;
 	if ( timePassedAfter(9) )
 	{
 		result = false;
	}
 	else if(_window->IsOpened())
 	{
    	result = true;
    	sf::Event event;
    	
   		while ( _window->GetEvent(event) )
   		{
			
			_mouseX = _window->GetInput().GetMouseX();
     		_mouseY = _window->GetInput().GetMouseY();
			
     		if ((event.Type == Event::Closed) || keyPress( &event, Key::Escape) ) 
	 		{
				_window->Close();
				result = false;
     		}
     		if ( clickButton( &event, _mouseX, _mouseY, &_next)) result = false;
								
     	}
	}
	return result;
}


void Intro::animation()
{
	float x = _meduseSprite.GetPosition().x;
	
	if ( _i == 0 )
	{
		setSprite( _meduseSprite, 0, 0, 358, 298 );
		sizepositionimg( _meduseSprite, x, 136, 358, 298 );
		_i = 1;
	}
	else if ( _i == 1 )
	{
		setSprite( _meduseSprite, 358, 0, 358, 298 );
		sizepositionimg( _meduseSprite, x+35, 136, 358, 298 );
		_i = 0;
	}
	if ( x > 84 )
	{
		setSprite( _introSprite, 0,0,(x-84),147);
		sizepositionimg( _introSprite, 30, 227, (x-30), 147 );
	}
}

bool Intro::timePassedAfter( const float & t )
{
	return ( _time.GetElapsedTime() >= t && _meduseSprite.GetPosition().x > 800 );
}
