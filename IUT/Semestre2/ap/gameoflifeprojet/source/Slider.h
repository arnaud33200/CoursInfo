#ifndef SLIDER_H
#define SLIDER_H

/**
 * \file Slider.h
 * \brief molette de reglage avec texte
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>
#include <string>

#include "Element.h"

using namespace std;
using namespace sf;

/** 
 * \class Slider
 * \brief classe qui gère une molette de réglage
*/
class Slider : public Element
{
	private:
		string _nom_slider;
		Sprite _slider_fg_sprite, _slider_bg_sprite;
		String _txt_info, _txt_val;
		int _val_max, _val_min, _val;
		float _xMax, _coef, _ord;
		bool _move;
		Element _posSlider;
		Image _slider_fg_img, _slider_bg_img;
		Font * _font;
		
		
	public:
	
/// ###################### CONSTRUCTOR & DESTRUCTOR ####################

		Slider(const int & bx, const int & by, const int & bw, const int & bh,
				const int & val, const int & max, const int & min,
				const int & tt, const string & txt );
		~Slider( );
		
/// ###################### ACTION SLIDER ####################
		
		void updateSlider();
		void updateSliderLoad();
		void changeSprite(const float & x, const float & y, const float & w, const float & h);
		
/// ###################### ACCESSEURS SLIDER ####################
		
		Sprite getSpriteBg() const;
		Sprite getSpriteFg() const;
		String getTxtInfo() const;
		String getTxtVal() const;
		Element* getSlider();
		int getVal() const;
		bool getMove() const;
		
		bool setMove( const bool & m );
		void setVal( const int & v );
		
};

#endif // SLIDER_H
