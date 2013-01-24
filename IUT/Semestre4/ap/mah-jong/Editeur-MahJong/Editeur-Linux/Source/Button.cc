#include "image.h"
#include "Button.h"


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Button::Button(const float & x, const float & y, const float & w, const float & h,const bool & keep,
				const std::string & txt, const int & tx, const int & ty, const int & tt )
: Element(x, y, w, h),
_press(false), _hover(false), _keep(keep)
{
	_buttonImg = new sf::Image();
	_font = new sf::Font();

	loadimage( *_buttonImg, _buttonSprite, "../images/button.png" );
	sizepositionimg(_buttonSprite, x, y, w, h);
	_font->LoadFromFile("../images/Arial.ttf");
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

sf::String Button::getTxt() const
{ return _texte; }

sf::Sprite Button::getSprite() const
{ return _buttonSprite; }

bool Button::getPress() const
{ return _press; }

bool Button::getHover() const
{ return _hover; }

bool Button::getKeep() const
{ return _keep; }

void Button::setTxt( const sf::String & txt )
{ _texte = txt; }

void Button::setPress( const bool & p )
{ _press = p; }

void Button::setHover( const bool & h )
{ _hover = h; }

void Button::setColor( int r, int g, int b )
{
	_texte.SetColor(sf::Color(r,g,b));
}
