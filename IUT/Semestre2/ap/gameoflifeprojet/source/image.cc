/**
 * \file image.cc
 * \brief chargement et affichage d'images
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */


#include <iostream>

#include "image.h"
#include "enum.h"
#include "Element.h"
#include "Unite.h"
#include "Button.h"
#include "Slider.h"


using namespace std;
using namespace sf;


/*#############################################################################
/#                                                                            #
/#            CHARGEMENT IMAGES / TEXTES                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn loadimage( Image & img, Sprite & spt, string file )
 * \brief Fonction qui simplifie le chargement d'une image dans un sprite
 * \param img Images qui sera chargé dans le sprite
 * \param spt Sprite qu'on doit charger
 * \param file string qui indique le chemin du fichier image
 * \return rien
 */
void loadimage( Image & img, Sprite & spt, string file )
{
	if (!img.LoadFromFile(file) )
	{
		cout << "l'images : " << file << " s'est pas chargé ! " << endl;
    	spt = Sprite();
	}
  	else
		spt = Sprite( img );
}

/**
 * \fn loadimage( Image & img, Sprite & spt, string file, const float & x, const float & y, const float & w, const float & h )
 * \brief Fonction qui simplifie le chargement d'une image dans un sprite et de ça forme
 * \param img Images qui sera chargé dans le sprite
 * \param spt Sprite qu'on doit charger
 * \param file string qui indique le chemin du fichier image
 * \param x, y, w, h réels qui definit taille et coordonné du sprite
 * \return rien
 */
void loadimage( Image & img, Sprite & spt, string file, const float & x, const float & y, const float & w, const float & h )
{
	loadimage(img, spt, file);
	setSprite(spt, x, y, w, h);
}

/**
 * \fn loadtextefont( String & t, Font* f, const float & size, const float & x, const float & y, const string & texte )
 * \brief Fonction qui simplifie le chargement d'un texte String
 * \param t String variable qui contiendra le texte
 * \param f Font qui correspond au type d'écriture
 * \param size, x, y réels qui definit taille et coordonnée du String
 * \param texte string qui contient le texte voulu
 * \return rien
 */
void loadtextefont( String & t, Font* f, const float & size, const float & x, const float & y, const string & texte )
{
	t.SetFont(*f);
	t.SetSize(size);
	t.SetPosition(x,y);
	t.SetText(texte);
	t.SetColor(Color(0,0,0));
}


/*#############################################################################
/#                                                                            #
/#            MODIFICATION SPRITES                                            #
/#                                                                            #
##############################################################################*/

/**
 * \fn sizepositionimg( Sprite & spt, const float & x, const float & y, const float & w, const float & h )
 * \brief Fonction qui définit les coordonnée et taille du sprite
 * \param spt Sprite qu'on doit modifier
 * \param x, y, w, h réels qui definit taille et coordonné du sprite
 * \return rien
 */
void sizepositionimg( Sprite & spt, const float & x, const float & y, const float & w, const float & h )
{
	spt.SetPosition(x,y);
	spt.Resize(w,h);
}

/**
 * \fn setSprite( Sprite & spt, const float & x, const float & y, const float & w, const float & h )
 * \brief Fonction qui définit rectangle de lecture de l'image
 * \param spt Sprite qu'on doit modifier
 * \param x, y, w, h réels qui definit taille et coordonné du rectangle de lecture
 * \return rien
 */
void setSprite( Sprite & spt, const float & x, const float & y, const float & w, const float & h )
{
	Rect<int> r(x,y,x+w,y+h);
	spt.SetSubRect(r);
}


/*#############################################################################
/#                                                                            #
/#            AFFICHAGE OBJETS                                                #
/#                                                                            #
##############################################################################*/

/**
 * \fn afficherCellules(GameModel* model, RenderWindow* & window, Sprite* celluleSprite)
 * \brief Fonction qui affiche les cellules de la GrilleCellule
 * \param model GameModel du jeu
 * \param window Renderwindow fenetre de jeu qui affichera les sprites
 * \param celluleSprite Sprite à afficher
 * \return rien
 */
void afficherCellules(GameModel* model, RenderWindow* & window, Sprite* celluleSprite)
{
	int ti, tj;
	float w,h;
	model->getSizePictureCellule(w,h);
	Unite e;
	
	model->getTailleGrilleCellule(ti, tj);
	
	for ( int i=0; i < ti; i++ )
	{
		for ( int j=0; j < tj; j++ )
		{
			model->getCoordonneCellule(i, j, e);
			if ( model->getEtatCellule(i,j) == alive )
			{
				if ( model->getSanteCellule(i,j) == resist ) // quand la cellule est resistante
				{
					setSprite(*celluleSprite,0,0,247,247);
					sizepositionimg(*celluleSprite, e.getX(), e.getY(), w, h);
					window->Draw(*celluleSprite);
				}
				else // si la cellule est normale
				{
					setSprite(*celluleSprite,0,494,247,247);
					sizepositionimg(*celluleSprite, e.getX(), e.getY(), w, h);
					window->Draw(*celluleSprite);
				}
			}
			else if ( model->getEtatCellule(i,j) == infest )
			{
				setSprite(*celluleSprite,0,247,247,247);
				sizepositionimg(*celluleSprite, e.getX(), e.getY(), w, h);
				window->Draw(*celluleSprite);
			}
		}
	}
}

/**
 * \fn afficherVirus(GameModel* model, RenderWindow* & window, Sprite virusSprite )
 * \brief Fonction qui affiche les virus du GroupeVirus
 * \param model GameModel du jeu
 * \param window Renderwindow fenetre de jeu qui affichera les sprites
 * \param virusSprite Sprite à afficher
 * \return rien
 */
void afficherVirus(GameModel* model, RenderWindow* & window, Sprite* virusSprite )
{
	int tg = model->getSizeGroupeVirus();
	float x, y, w, h;
	
	for ( int i=0; i < tg; i++ )
	{
		model->getCoordonneVirus(i, x, y, w, h);
		sizepositionimg(*virusSprite, x, y, w, h);
		window->Draw(*virusSprite);
	}
}

/**
 * \fn afficherButton( RenderWindow* & window, Button* button )
 * \brief Fonction qui affiche les objet Button
 * \param window Renderwindow fenetre de jeu qui affichera les sprites
 * \param button Button que l'on doit afficher
 * \return rien
 */
void afficherButton( RenderWindow* & window, Button* button )
{
	if( button->getHover() ) button->changeSprite(0,192,166,96);
	else if ( button->getPress() ) button->changeSprite(0,96,166,96);
	else button->changeSprite(0,0,166,96);

	window->Draw( button->getSprite() );
	window->Draw( button->getTxt() );
}

/**
 * \fn afficherSlider( RenderWindow* & window, Slider* slider )
 * \brief Fonction qui affiche les objet Slider
 * \param window Renderwindow fenetre de jeu qui affichera les sprites
 * \param slider Slider que l'on doit afficher
 * \return rien
 */
void afficherSlider( RenderWindow* & window, Slider* slider )
{
	if ( slider->getMove() ) slider->changeSprite(5,0,5,20);
	else slider->changeSprite(0,0,5,20);

	window->Draw( slider->getSpriteBg() );
	window->Draw( slider->getSpriteFg() );
	window->Draw( slider->getTxtInfo() );
	window->Draw( slider->getTxtVal() );
}

/**
 * \fn afficherselect( RenderWindow* & window, Sprite* select, const int & i, const int & j, const float & w, const float & h)
 * \brief Fonction qui affiche le cadre de selection des cellules
 * \param window Renderwindow fenetre de jeu qui affichera les sprites
 * \param select Sprite contenant l'image a afficher
 * \param i, j entiers indiquant les indices d'une cellules selectionnée
 * \param w, h réels definissant la taille du selecteur
 * \return rien
 */
void afficherselect( RenderWindow* & window, Sprite* select, const int & i, const int & j, const float & w, const float & h)
{
	if ( ((j-1)*h)+30 >= 30 )
	{
		sizepositionimg( *select, i*w, ((j-1)*h)+30, w, h);
		window->Draw( *select );
	}
}


