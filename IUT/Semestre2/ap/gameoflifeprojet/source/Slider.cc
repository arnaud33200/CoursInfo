/**
 * \file Slider.cc
 * \brief molette de reglage avec texte
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include "Slider.h"
#include "image.h"
#include "util.h"

using namespace std;
using namespace sf;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn Slider(const int & bx, const int & by, const int & bw, const int & bh,
			   const int & val, const int & max, const int & min,
			   const int & tt, const string & txt )
 * \brief Constructeur par parametre du Slider
 * \param bx, by, bw, bh entiers qui definissent les coordonnées et taille du fond du Slider
 * \param val, max, min entiers qui definisse la valeur de depart, la valeur max, et la valeur min du Slider
 * \param tt réel definisant la taille du texte
 * \param txt string contenant le texte qui va avec le Slider
 */
Slider::Slider(const int & bx, const int & by, const int & bw, const int & bh,
			   const int & val, const int & max, const int & min,
			   const int & tt, const string & txt )
: _posSlider(bx, by-(bh/2), bw*5/120, 2*bh), 
Element(bx,by,bw,bh),
_val_max(max), _val_min(min), _val(val), _move(false)
{
	_xMax = bx+bw-_posSlider.getW();
	_coef = ( max - min ) / (_xMax - bx );
	_ord = max - ( _coef * _xMax );
	_posSlider.setX( (_val - _ord) / _coef );
	
	loadimage(_slider_fg_img, _slider_fg_sprite, "images/slider_fg.png" );
	sizepositionimg(_slider_fg_sprite, _posSlider.getX(), _posSlider.getY(), _posSlider.getW(), _posSlider.getH());
	loadimage(_slider_bg_img, _slider_bg_sprite, "images/slider_bg.png" );
	sizepositionimg(_slider_bg_sprite, bx, by, bw, bh);
	
	_font = new Font();
	_font->LoadFromFile("images/antique.ttf");
	
	loadtextefont( _txt_info, _font, tt, bx, by - ( tt + 10 ), txt );
	loadtextefont( _txt_val, _font, tt, txt.length() * (tt/2) + bx, by - ( tt + 10 ), toString(_val) );
}

Slider::~Slider ( )
{
	delete _font;
}


/*#############################################################################
/#                                                                            #
/#            ACTION SLIDER                                                   #
/#                                                                            #
##############################################################################*/

/**
 * \fn Slider::updateSlider()
 * \brief Methode qui met a jours la position et la valeur du slider
 * \param rien
 * \return rien
 */
void Slider::updateSlider()
{
	if ( _posSlider.getX() > _xMax ) _posSlider.setX( _xMax );
	if ( _posSlider.getX() <= getX() ) _posSlider.setX( getX() ); 
	_val = (_coef * _posSlider.getX()) + _ord;
	_posSlider.setX( (_val - _ord) / _coef );
	sizepositionimg(_slider_fg_sprite, _posSlider.getX(), _posSlider.getY(), _posSlider.getW(), _posSlider.getH());
	_txt_val.SetText(toString(_val) );
	
}

/**
 * \fn Slider::updateSlider()
 * \brief Methode qui met a jours de la valeur du slider
 * \param rien
 * \return rien
 */
void Slider::updateSliderLoad()
{
	if ( _posSlider.getX() > _xMax ) _posSlider.setX( _xMax );
	if ( _posSlider.getX() <= getX() ) _posSlider.setX( getX() ); 
	_posSlider.setX( (_val - _ord) / _coef );
	sizepositionimg(_slider_fg_sprite, _posSlider.getX(), _posSlider.getY(), _posSlider.getW(), _posSlider.getH());
	_txt_val.SetText(toString(_val) );
	
}

/**
 * \fn Slider::changeSprite(const float & x, const float & y, const float & w, const float & h)
 * \brief change le rectangle de lecture de l'image du Sprite
 * \param x,y,w,h réels definissant la position et la taille du rectangle de lecture
 * \return rien
 */
void Slider::changeSprite(const float & x, const float & y, const float & w, const float & h)
{
	setSprite(_slider_fg_sprite,x,y,w,h);
	sizepositionimg(_slider_fg_sprite, _posSlider.getX(), _posSlider.getY(), _posSlider.getW(), _posSlider.getH() );
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS SLIDER                                               #
/#                                                                            #
##############################################################################*/

Sprite Slider::getSpriteBg() const
{ return _slider_bg_sprite; }

Sprite Slider::getSpriteFg() const
{ return _slider_fg_sprite; }

String Slider::getTxtInfo() const
{ return _txt_info; }

String Slider::getTxtVal() const
{ return _txt_val; }

int Slider::getVal() const
{ return _val; }

Element* Slider::getSlider()
{ return &_posSlider; }	

bool Slider::getMove() const
{ return _move; }

bool Slider::setMove( const bool & m )
{ _move = m; }

void Slider::setVal( const int & v )
{ 
	_val = v;
	updateSliderLoad();
}
