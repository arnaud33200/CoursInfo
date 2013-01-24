#ifndef IMAGE_H
#define IMAGE_H


#include "Button.h"


///############# CHARGEMENT IMAGES / TEXTES ######################

void loadimage( sf::Image & img, sf::Sprite & spt, std::string file );
void loadimage( sf::Image & img, sf::Sprite & spt, std::string file, const float & x, const float & y, const float & w, const float & h );
void loadtextefont( sf::String & t, sf::Font* f, const float & size, const float & x, const float & y, const std::string & texte );
void loadtextefont( sf::String & t, sf::Font* f, const float & size, const float & x, const float & y, const std::string & texte, const int & r, const int & g, const int & b );

/// ############ MODIFICATION SPRITES #################

void sizepositionimg( sf::Sprite & spt, const float & x, const float & y, const float & w, const float & h );
void setSprite( sf::Sprite & spt, const float & x, const float & y, const float & w, const float & h );

/// ############# AFFICHAGE OBJETS ####################

void afficherButton( sf::RenderWindow* & window, Button* button );

#endif
