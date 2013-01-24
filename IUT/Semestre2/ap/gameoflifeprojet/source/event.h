#ifndef EVENT_H
#define EVENT_H

/**
 * \file event.h
 * \brief gestion d'évenements
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Element.h"
#include "Slider.h"

using namespace sf;

/// ##################### EVENEMENT DE BASE ##################

	// evenement sourie
		
bool clickDownLeft( Event* event );
bool clickDownRight( Event* event );
bool clickUpLeft( Event* event );
bool clickUpRight( Event* event );

	// evenement clavier

bool keyPress( Event* event, const Key::Code & key );

/// ##################### EVENEMENT SUR OBJETS ##################

bool clickButton(Event* event, const float & mx, const float & my, Button* button);
void moveSlider(Event* event, Element* element, Slider* slider, const float & mx, const float & my);


#endif // EVENT_H
