#ifndef EVENT_H
#define EVENT_H

#include "Button.h"


/// ##################### EVENEMENT DE BASE ##################

	// evenement sourie

bool clickDownLeft( sf::Event* event );
bool clickDownRight( sf::Event* event );
bool clickUpLeft( sf::Event* event );
bool clickUpRight( sf::Event* event );

	// evenement clavier

bool keyPress( sf::Event* event, const sf::Key::Code & key );

/// ##################### EVENEMENT SUR OBJETS ##################

bool clickButton(sf::Event* event, const float & mx, const float & my, Button* button);

#endif // EVENT_H
