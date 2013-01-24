/**
 * \file MenuView.cc
 * \brief View du menu
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>

#include "MenuView.h"
#include "image.h"
#include "event.h"

using namespace std;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

/**
 * \fn MenuView(const float & w, const float & h, const float & x, const float & y )
 * \brief Constructeur par parametre de MenuView
 * \param w,h des réels pour indiqué la taille de la fenêtre
 * \param x,y des réels pour definir la position de la fenêtre
 */
MenuView::MenuView(const float & w, const float & h, const float & x, const float & y )
: Element(x, y, w, h), 

/// BOUTTON :

_playButton( 0, 475, 100, 50, 0, "jouer", 20, 8, 25), 					// boutton joueur / pause

_addColum( 0, 350, 100, 50, 1, "Ajouter \nColonne", 27, 8, 15),			// boutton ajouter une colonne de cellule
_removeColum( 100, 350, 100, 50, 1, "Enlever \nColonne", 27, 8, 15),	// boutton enlever une colonne de cellule
_addLine( 0, 400, 100, 50, 1, "Ajouter  \nLigne", 27, 8, 15),			// boutton ajouter une ligne de cellule
_removeLine( 100, 400, 100, 50, 1, "Enlever\n  Ligne", 25, 8, 15),		// boutton enlever une ligne de cellule
_updateAll( 100, 475, 100, 50, 1,"Mise a\n Jour", 28, 8, 15),			// boutton mise a jour des cellules

_addVirus( 0, 50, 100, 50, 1, "Ajouter\n Virus", 27, 8, 15),			// boutton ajouter un virus
_removeVirus( 100, 50, 100, 50, 1, "Retirer\n Virus", 27, 8, 15), 		// boutton enlever un virus
_removeAllVirus( 50, 100, 100, 50, 0, "Enlever\n Tout", 27, 8, 15),		// boutton tout les virus	

/// SLIDER :

_vitesseJeu( 10, 570, 180, 10, 65, 100, 0, 18, "vitesse jeu =" ),		// vitesse du jeu
	
_minAliveCellule( 10, 80, 180, 10, 2, 8, 0, 18, "Min Vivant = " ), 		// minimum cellule voisin pour rester vivant
_maxAliveCellule( 10, 125, 180, 10, 3, 8, 0, 18, "Max Vivant = " ), 	// maximum cellule voisin pour rester vivant
_minDeadCellule( 10, 170, 180, 10, 3, 8, 0, 18, "Min Mort = " ), 		// minimum cellule voisin pour devenir vivant
_maxDeadCellule( 10, 215, 180, 10, 3, 8, 0, 18, "Max Mort = " ),		// maximum cellule voisin pour devenir vivant
_aleaCellule( 10, 260, 180, 10, 45, 100, 0, 18, "ViVant/100 = "),		// pourcentage aleatoire pour l'apparittion de cellule vivante
_aleaResist(10, 305, 180, 10, 10, 100, 0, 18, "Resistant/100 = "),		// pourcentage aleatoire pour l'apparattion de cellule resistante

_nbEnfantVirus( 10, 195, 180, 10, 2, 8, 1, 18, "Enfant = " ), 			// nombre d'enfant descendant d'un virus
_tmpLifeVirus( 10, 245, 180, 10, 6, 12, 1, 18, "Temps Vie = "  ), 		// temps de vie d'un virus
_tmpIncubVirus( 10, 295, 180, 10, 2, 8, 2, 18, "Incubation = " )		// temps d'incubation d'un virus

{
	_onglet = cellule;
	_window = new RenderWindow(sf::VideoMode(_w, _h, 32), "Parametre", sf::Style::Close);
	_window->SetPosition(_x,_y);
	
	loadimage(_bgCellImg, _bgCellSprite, "images/bg_cell.png");
	loadimage(_bgVirusImg, _bgVirusSprite, "images/bg_virus.png");	
}

MenuView::~MenuView ( )
{
	if(_window != NULL) delete _window;
}


/*#############################################################################
/#                                                                            #
/#            ACTION FENETRE                                                  #
/#                                                                            #
##############################################################################*/


/**
 * \fn MenuView::draw( )
 * \brief Methode qui dessine les images et Objets du menu
 * \param rien
 * \return rien
 */
void MenuView::draw( )
{
/// SEULEMENT SI LA FENETRE EST OUVERTE
	if(_window->IsOpened())
 	{
		if ( _model->getStateGame() ) _playButton.setTxt( "pause" );
			else _playButton.setTxt( "jouer" );
	
		if ( _onglet == cellule ) // l'onglet cellule selectionné, afficher ....
		{
			_window->Draw(_bgCellSprite);           	// fond de menu (select cellule)
			
			afficherSlider(_window, &_minAliveCellule);		// slider : min vivant Cellule
			afficherSlider(_window, &_maxAliveCellule);		// slider : max vivant Cellule
			afficherSlider(_window, &_minDeadCellule);		// slider : min mort Cellule
			afficherSlider(_window, &_maxDeadCellule);		// slider : max mort Cellule
			afficherSlider(_window, &_aleaCellule);			// slider : pourcentage Cellule vivante
			afficherSlider(_window, &_aleaResist);			// slider : pourcentage Cellule Resistante
			
				
		}
		else // l'onglet virus selectionné, afficher ....
		{
			_window->Draw(_bgVirusSprite);			// fond de menu (select virus)
			afficherButton(_window, &_addVirus);		// boutton : ajouter un virus
			afficherButton(_window, &_removeVirus);		// boutton : enlever un virus
			afficherButton(_window, &_removeAllVirus);	// boutton : enlever tous les virus
			
			afficherSlider(_window, &_nbEnfantVirus);	// slider : nombre d'enfant
			afficherSlider(_window, &_tmpLifeVirus);	// slider : temps de vie Virus
			afficherSlider(_window, &_tmpIncubVirus);	// slider : temps d'incubation
		}
		
		_model->setVitesse( _vitesseJeu.getVal() );
		_model->setMinAliveCellule( _minAliveCellule.getVal() );
		_model->setMaxAliveCellule( _maxAliveCellule.getVal() ); 
		_model->setMinDeadCellule( _minDeadCellule.getVal() ); 
		_model->setMaxDeadCellule( _maxDeadCellule.getVal() );
		_model->setNbEfantVirus( _nbEnfantVirus.getVal() );
		_model->setDureVieVirus( _tmpLifeVirus.getVal() );
		_model->setDureIncubVirus( _tmpIncubVirus.getVal() );
		
		afficherButton(_window, &_addColum);		// boutton : ajouter colone cellule
		afficherButton(_window, &_removeColum);		// boutton : enlever colone cellule
		afficherButton(_window, &_addLine);			// boutton : ajouter ligne cellule
		afficherButton(_window, &_removeLine);		// boutton : enlever ligne cellule	
		
		afficherButton(_window, &_playButton);			// boutton : jeu en pause ou lecteur
		afficherButton(_window, &_updateAll);
		afficherSlider(_window, &_vitesseJeu);


		_window->Display();
		usleep(10000);
	}
}

/**
 * \fn MenuView::treatEvents()
 * \brief Methode qui récupére les évenements d'entrées sorties 
 * \param rien
 * \return rien
 */
bool MenuView::treatEvents()
{
	bool result = false;
 	if(_window->IsOpened())
 	{
    	result = true;
    	sf::Event event;
   		while ( _window->GetEvent(event) )
   		{
   			// evenement permettant de fermer la fenetre
     		if ((event.Type == sf::Event::Closed) ||
	 		((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))) 
	 		{
				_window->Close();
				result = false;
     		}
     		
     		_mouseX = _window->GetInput().GetMouseX();
     		_mouseY = _window->GetInput().GetMouseY();
     		

     		// ~~~~~~~~~ AJOUTER UN VIRUS DANS LE JEU ~~~~~~~~~~~~~~~~~  		
     		if ( _onglet == virus )
     		{
				_model->add_virus( clickButton(&event, _mouseX, _mouseY, &_addVirus) );	
				_model->del_virus( clickButton(&event, _mouseX, _mouseY, &_removeVirus) );   		
				_model->removeAllVirus( clickButton(&event, _mouseX, _mouseY, &_removeAllVirus) );
				
				moveSlider( &event, _nbEnfantVirus.getSlider(), &_nbEnfantVirus, _mouseX, _mouseY );
				moveSlider( &event, _tmpLifeVirus.getSlider(), &_tmpLifeVirus, _mouseX, _mouseY );
				moveSlider( &event, _tmpIncubVirus.getSlider(), &_tmpIncubVirus, _mouseX, _mouseY );
			}
     		
     		else  // l'onglet Cellule
     		{
				moveSlider( &event, _minAliveCellule.getSlider(), &_minAliveCellule, _mouseX, _mouseY );
				moveSlider( &event, _maxAliveCellule.getSlider(), &_maxAliveCellule, _mouseX, _mouseY );
				moveSlider( &event, _maxDeadCellule.getSlider(), &_maxDeadCellule, _mouseX, _mouseY );
				moveSlider( &event, _minDeadCellule.getSlider(), &_minDeadCellule, _mouseX, _mouseY );
				moveSlider( &event, _aleaCellule.getSlider(), &_aleaCellule, _mouseX, _mouseY );
				moveSlider( &event, _aleaResist.getSlider(), &_aleaResist, _mouseX, _mouseY );
			}
			
			updateSlider();
			
     		moveSlider( &event, _vitesseJeu.getSlider(), &_vitesseJeu, _mouseX, _mouseY );

     		_model->play_pause( clickButton(&event, _mouseX, _mouseY, &_playButton) );
     		_model->update_all_Cellule( clickButton(&event, _mouseX, _mouseY, &_updateAll) );
     		
     		
     		changeTabCellule( (event.Type == sf::Event::MouseButtonPressed) 
							   && _mouseX >= 0 && _mouseX <=100 && _mouseY >= 0 && _mouseY <= 40 );
			changeTabVirus( (event.Type == sf::Event::MouseButtonPressed) 
							   && _mouseX >= 100 && _mouseY >= 0 && _mouseY <= 40 );
     	}
     	
     	_model->add_line( clickButton(&event, _mouseX, _mouseY, &_addLine), &_addLine );
		_model->remove_line( clickButton(&event, _mouseX, _mouseY, &_removeLine), &_removeLine );
     	_model->add_column( clickButton(&event, _mouseX, _mouseY, &_addColum), &_addColum );
     	_model->remove_column( clickButton(&event, _mouseX, _mouseY, &_removeColum), &_removeColum );
	}
	return result;
}

/**
 * \fn MenuView::updateSlider()
 * \brief Methode qui met a jours les valeurs de chaque slider du Menu
 * \param rien
 * \return rien
 */
void MenuView::updateSlider()
{
	_model->setVitesse( _vitesseJeu.getVal() );
	_model->setMinAliveCellule( _minAliveCellule.getVal() );
	_model->setMaxAliveCellule( _maxAliveCellule.getVal() ); 
	_model->setMinDeadCellule( _minDeadCellule.getVal() ); 
	_model->setMaxDeadCellule( _maxDeadCellule.getVal() );
	_model->setAleaCelluleGrille( _aleaCellule.getVal() );
	_model->setAleaResistGrille( _aleaResist.getVal() );
	
	_model->setNbEfantVirus( _nbEnfantVirus.getVal() );
	_model->setDureVieVirus( _tmpLifeVirus.getVal() );
	_model->setDureIncubVirus( _tmpIncubVirus.getVal() );
}

/**
 * \fn MenuView::openWindow(const bool & open, int x, int y)
 * \brief Methode qui reouvre la fenetre du MenuView
 * \param open booléen venant du Gameview aprés un click sur un boutton
 * \param x, y entiers qui definissent la position d'apparition de la fenetre menu
 * \return rien
 */
void MenuView::openWindow(const bool & open, int x, int y)
{
	if ( ! getWindow() && open )
	{
		delete _window;
		_window = new RenderWindow(sf::VideoMode(_w, _h, 32), "Parametre G O F", sf::Style::Close);
		//~ _window->SetPosition(0,0);	
		//~ _window->Display();
	}
	
		
}


/*#############################################################################
/#                                                                            #
/#            CHANGEMENT ONGLETS                                              #
/#                                                                            #
##############################################################################*/

/**
 * \fn MenuView::changeTabCellule( const bool & t )
 * \brief méthode qui ouvre l'onglet "Cellule"
 * \param t booléen qui indique si on a cliqué dans la zone de l'onglet
 * \return rien
 */
void MenuView::changeTabCellule( const bool & t )
{
	if ( t )
	{
		if ( _onglet == virus )
		{
			_onglet = cellule;
		}
	}
}

/**
 * \fn MenuView::changeTabVirus( const bool & t )
 * \brief méthode qui ouvre l'onglet "Virus"
 * \param t booléen qui indique si on a cliqué dans la zone de l'onglet
 * \return rien
 */
void MenuView::changeTabVirus( const bool & t )
{
	if ( t )
	{
		if ( _onglet == cellule )
		{
			_onglet = virus;
		}
	}
}

/*#############################################################################
/#                                                                            #
/#            ACCESSEURS MENU                                                 #
/#                                                                            #
##############################################################################*/


bool MenuView::getWindow() const
{ return _window->IsOpened(); }

void MenuView::setModel (GameModel * model )
{ 
	_model = model; 
}

