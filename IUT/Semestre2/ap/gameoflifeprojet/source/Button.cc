/**
 * \file Button.cc
 * \brief bouttons avec un texte
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */


#include <iostream>
#include <cstdlib>
#include <string>

#include "Button.h"
#include "image.h"

using namespace std;
using namespace sf;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Button::Button(const float & x, const float & y, const float & w, const float & h,const bool & keep,
				const string & txt, const int & tx, const int & ty, const int & tt )
: Element(x, y, w, h),
_press(false), _hover(false), _keep(keep)
{
	_buttonImg = new Image();
	_font = new Font();
	
	loadimage( *_buttonImg, _buttonSprite, "images/button.png" );
	sizepositionimg(_buttonSprite, x, y, w, h);
	_font->LoadFromFile("images/antique.ttf");
	loadtextefont( _texte, _font, tt, x+tx, y+ty, txt);
}

Button::~Button ( )
{
	delete _font; 
	delete _buttonImg; 
}


/*#############################################################################
/#                                                                            #
/#            ACTION BUTTON                                                   #
/#                                                                            #
##############################################################################*/

/**
 * \fn Button::changeSprite(const float & x, const float & y, const float & w, const float & h)
 * \brief change le carré de lecture du sprite sur l'image qu'il contient
 * \param x,y,w,h réels qui definissent les coordonnées et la taille du nouveau carré de lecture
 * \return rien
 */
void Button::changeSprite(const float & x, const float & y, const float & w, const float & h)
{
	setSprite( _buttonSprite, x, y, w, h);
	sizepositionimg(_buttonSprite, getX(), getY(), getW(), getH() );
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/

String Button::getTxt() const
{ return _texte; }

Sprite Button::getSprite() const
{ return _buttonSprite; }

bool Button::getPress() const
{ return _press; }

bool Button::getHover() const
{ return _hover; }

bool Button::getKeep() const
{ return _keep; }

void Button::setTxt( const string & txt )
{ _texte.SetText(txt); }

void Button::setPress( const bool & p )
{ _press = p; }

void Button::setHover( const bool & h )
{ _hover = h; }
