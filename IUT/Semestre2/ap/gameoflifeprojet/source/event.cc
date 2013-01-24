/**
 * \file event.cc
 * \brief gestion d'évenements
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 * 
 */

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

/**
 * \fn clickDownLeft( Event* event )
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \return un booléen qui indique si on effectue un click préssé gauche
 */
bool clickDownLeft( Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonPressed) 
			&& (event->MouseButton.Button == sf::Mouse::Left) );
}

/**
 * \fn clickDownRight( Event* event )
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \return un booléen qui indique si on effectue un click préssé droit
 */
bool clickDownRight( Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonPressed) 
			&& (event->MouseButton.Button == sf::Mouse::Right) );
}

/**
 * \fn clickUpLeft( Event* event )
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \return un booléen qui indique si on effectue un click relaché gauche
 */
bool clickUpLeft( Event* event )
{ 
	return ( (event->Type == sf::Event::MouseButtonReleased) 
			&& (event->MouseButton.Button == sf::Mouse::Left) );
}

/**
 * \fn clickUpRight( Event* event )
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \return un booléen qui indique si on effectue un click relaché droit
 */
bool clickUpRight( Event* event )
{
	return ( (event->Type == sf::Event::MouseButtonReleased) 
			&& (event->MouseButton.Button == sf::Mouse::Right) );
}

/// ############# Evenement clavier ##################

/**
 * \fn keyPress( Event* event, const Key::Code & key )
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments clavier
 * \param key Key::Code précise la touche qui nous interesse
 * \return un booléen qui indique si la touche en question est préssé
 */
bool keyPress( Event* event, const Key::Code & key )
{
	return ( (event->Type == sf::Event::KeyPressed) && (event->Key.Code == key) );
}

/*#############################################################################
/#                                                                            #
/#            EVENEMENTS SUR DES OBJETS                                       #
/#                                                                            #
##############################################################################*/

/**
 * \fn clickButton(Event* event, const float & mx, const float & my, Button* button)
 * \brief Fonction qui gére les clicks et selection de l'objet Button
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \param button pointeur sur Boutton, pour faire appel au différent accesseur de la classe
 * \param mx et my réels qui indique les coordonnées de la sourie
 * \return un booléen qui indique si ont peut executer l'action que produit le boutton
 */
bool clickButton(Event* event, const float & mx, const float & my, Button* button)
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
}

/**
 * \fn moveSlider(Event* event, Element* element, Slider* slider, const float & mx, const float & my)
 * \brief Fonction de gestion du mouvement d'un objet Slider
 * \param event pointeur d'Event provenant de MenuView et contenant les évenments sourie
 * \param element pointeur sur l'Element bougeable du Slider pour récupérer la taille et coordonnées
 * \param slider pointeur sur l'objet Slider, permet de faire appel au méthode contenue dans le slider
 * \param mx et my réels qui indique les coordonnées de la sourie
 * \return rien.
 */
void moveSlider(Event* event, Element* element, Slider* slider, const float & mx, const float & my)
{
	if ( clickDownLeft(event)
		&& mx >= element->getX() && mx <= ( element->getX() + element->getW()+2) 
		&& my >= element->getY() && my <= ( element->getY() + element->getH()) )
	{
		slider->setMove( true );   	// le slider est en état de mouvement
		
	}
// quand on relache le click et que le slider est en etat de bougé
	else if ( clickUpLeft(event) && slider->getMove() )
	{
		slider->setMove( false ); 
	}
// si on click sur la bar du slider, hors de la partie mobile
	if ( clickDownLeft(event)
		&& !(mx >= element->getX() && mx <= ( element->getX() + element->getW()+2) 
		&& my >= element->getY() && my <= ( element->getY() + element->getH()))
		&& (mx >= slider->getX() && mx <= ( slider->getX() + slider->getW()) 
		&& my >= slider->getY() && my <= ( slider->getY() + slider->getH()))  )
	{
		element->setX( mx ); 		// definit la position du slider par rapport à sourie
		slider->updateSlider(); 	// met à jour le slider pour aligner et vérifier la position	
	}
	
	if ( slider->getMove() )
	{
		element->setX( mx ); 		// definit la position du slider par rapport à sourie
		slider->updateSlider(); 	// met à jour le slider pour aligner et vérifier la position
	}
}
