#include <iostream>

#include "event.h"

using namespace std;


/*#############################################################################
/#                                                                            #
/#            EVENEMENTS DE BASE                                              #
/#                                                                            #
/# ces fonctions simplifie les evenement basique proposé par SFML             #
/#                                                                            #
##############################################################################*/

/// ########## Evenement sourie #############

bool clickDownLeft( sf::Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonPressed)
			&& (event->MouseButton.Button == sf::Mouse::Left) );
}

bool clickDownRight( sf::Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonPressed)
			&& (event->MouseButton.Button == sf::Mouse::Right) );
}

bool clickUpLeft( sf::Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonReleased)
			&& (event->MouseButton.Button == sf::Mouse::Left) );
}

bool clickUpRight( sf::Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonReleased)
			&& (event->MouseButton.Button == sf::Mouse::Right) );
}

/// ############# Evenement clavier ##################

bool keyPress( sf::Event* event, const sf::Key::Code & key )
{
	return ( (event->Type == sf::Event::KeyPressed) && (event->Key.Code == key) );
}

/*#############################################################################
/#                                                                            #
/#            EVENEMENTS SUR DES OBJETS                                       #
/#                                                                            #
##############################################################################*/


bool clickButton(sf::Event* event, const float & mx, const float & my, Button* button)
{
// si on click gauche sur un boutton
	if ( clickDownLeft(event) && !button->getPress()
		&& mx >= button->getX()+2 && mx <= ( button->getX() + button->getW())-2
		&& my >= button->getY()+2 && my <= ( button->getY() + button->getH())-2 )
	{
		button->setPress(true);
	}
// si on relache la sourie sur la zone du boutton
	if ( clickUpLeft(event) && button->getPress()
		&& mx >= button->getX()+2 && mx <= ( button->getX() + button->getW())-2
		&& my >= button->getY()+2 && my <= ( button->getY() + button->getH())-2 )
	{
		button->setPress(false);
			return true;
	}
// si on relache la sourie hors du boutton
	else if ( clickUpLeft(event) && button->getPress() )
	{
		button->setPress(false);
	}
// si on fait seulement survolé la sourie sur le bouton
	else if ( !clickUpLeft(event) && !clickDownLeft(event)
		&& mx >= button->getX()+2 && mx <= ( button->getX() + button->getW())-2
		&& my >= button->getY()+2 && my <= ( button->getY() + button->getH())-2 )
	{
		button->setHover(true);
		return false;
	}
	else
	{
		button->setHover(false);
		return false;
	}

	return false;
}

