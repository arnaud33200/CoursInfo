#ifndef IMAGE_H
#define IMAGE_H

/**
 * \file image.h
 * \brief chargement et affichage d'images
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>
#include <string>

#include "GameModel.h"
#include "Button.h"
#include "Slider.h"

using namespace std;
using namespace sf;

///############# CHARGEMENT IMAGES / TEXTES ######################

void loadimage( Image & img, Sprite & spt, string file );
void loadimage( Image & img, Sprite & spt, string file, const float & x, const float & y, const float & w, const float & h );
void loadtextefont( String & t, Font* f, const float & size, const float & x, const float & y, const string & texte );

/// ############ MODIFICATION SPRITES #################

void sizepositionimg( Sprite & spt, const float & x, const float & y, const float & w, const float & h );
void setSprite( Sprite & spt, const float & x, const float & y, const float & w, const float & h );

/// ############# AFFICHAGE OBJETS ####################

void afficherCellules(GameModel* model, RenderWindow* & window, Sprite* celluleSprite);
void afficherVirus(GameModel* model, RenderWindow* & window, Sprite* virusSprite );
void afficherButton( RenderWindow* & window, Button* button );
void afficherSlider( RenderWindow* & window, Slider* slider );
void afficherselect( RenderWindow* & window, Sprite* select, const int & i, const int & j, const float & w, const float & h);


#endif
