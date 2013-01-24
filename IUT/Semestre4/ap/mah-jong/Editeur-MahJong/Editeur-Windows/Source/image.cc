#include <iostream>

#include "image.h"


/*#############################################################################
/#                                                                            #
/#            CHARGEMENT IMAGES / TEXTES                                      #
/#                                                                            #
##############################################################################*/


void loadimage( sf::Image & img, sf::Sprite & spt, std::string file )
{
	if (!img.LoadFromFile(file) )
	{
		std::cout << "l'images : " << file << " s'est pas chargé ! " << std::endl;
    	spt = sf::Sprite();
	}
  	else
		spt = sf::Sprite( img );
}

void loadimage( sf::Image & img, sf::Sprite & spt, std::string file, const float & x, const float & y, const float & w, const float & h )
{
	loadimage(img, spt, file);
	setSprite(spt, x, y, w, h);
}

void loadtextefont( sf::String & t, sf::Font* f, const float & size, const float & x, const float & y, const std::string & texte )
{
	t.SetFont(*f);
	t.SetSize(size);
	t.SetPosition(x,y);
	t.SetText(texte);
	t.SetColor(sf::Color(0,0,0));
}

void loadtextefont( sf::String & t, sf::Font* f, const float & size, const float & x, const float & y, const std::string & texte, const int & r, const int & g, const int & b )
{
	t.SetFont(*f);
	t.SetSize(size);
	t.SetPosition(x,y);
	t.SetText(texte);
	t.SetColor(sf::Color(r,g,b));
}

/*#############################################################################
/#                                                                            #
/#            MODIFICATION SPRITES                                            #
/#                                                                            #
##############################################################################*/

void sizepositionimg( sf::Sprite & spt, const float & x, const float & y, const float & w, const float & h )
{
	spt.SetPosition(x,y);
	spt.Resize(w,h);
}

void setSprite( sf::Sprite & spt, const float & x, const float & y, const float & w, const float & h )
{
	sf::Rect<int> r(x,y,x+w,y+h);
	spt.SetSubRect(r);
}


/*#############################################################################
/#                                                                            #
/#            AFFICHAGE OBJETS                                                #
/#                                                                            #
##############################################################################*/


void afficherButton( sf::RenderWindow* & window, Button* button )
{
	if(button != NULL )
	{
		if( button->getHover() ) button->changeSprite(0,192,166,96);
		else if ( button->getPress() ) button->changeSprite(0,96,166,96);
		else button->changeSprite(0,0,166,96);

		window->Draw( button->getSprite() );
		window->Draw( button->getTxt() );
	}
}



