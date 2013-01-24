#include "MenuView.h"
#include "image.h"
#include "event.h"


using namespace std;

// Convertisseur entier vers un string
string toString( const int & e )
{
	ostringstream s;
	s << e;
	return s.str();
}

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/


MenuView::MenuView(const float & w, const float & h, const float & x, const float & y )
: Element(x, y, w, h),
my_newButton(20, 635, 100, 50, 0, "Nouveau", 18, 14, 16),
my_loadButton(200, 575, 100, 50, 0, "Charger", 20, 14, 16),
my_saveButton(20, 575, 100, 50, 0, "Enregistrer", 15, 14, 14),
my_quitButton(200, 635, 100, 50, 0, "Quitter", 24, 14, 16),
my_mdButton(288, 10, 21, 21, 0, "+", 4, -7, 25),
my_ldButton(260, 10, 21, 21, 0, "-", 8, -7, 25),
my_meButton(288, 54, 21, 21, 0, "+", 4, -7, 25),
my_leButton(260, 54, 21, 21, 0, "-", 8, -7, 25),
my_mfButton(288, 98, 21, 21, 0, "+", 4, -7, 25),
my_lfButton(260, 98, 21, 21, 0, "-", 8, -7, 25)
{
	_window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Parametre");
	_window->SetPosition(_x,_y);

	loadimage(my_bgImg, my_bgSpt, "../images/backmenu.png", 0,0,this->getW(),this->getH());

	my_font.LoadFromFile("../images/Arial.ttf");

	loadtextefont( _viewD, & my_font, 16, 62, 12, "Tuiles differentes (d) : 2");
	loadtextefont(_viewE, & my_font, 16, 8, 56, "Eliminations simultanees (e) : 2");
	loadtextefont(_viewF, & my_font, 16, 60, 100, "Tuiles identiques (f) : 2\na eliminer simultanement");
	loadtextefont(_infoTuile, & my_font, 16, 8, 170, "Nombre de tuiles a placee : 8\n- tuiles restantes = 8\n- tuiles en trop = 0\n\n\nNumero etage en fonction de la couleur :");
	loadtextefont(_numEtage, & my_font, 16, 8, 210, "0");
	loadtextefont(_messAlert, & my_font, 20, 14, 510, "Enregistrement impossible car\nIl y manque x pieces");

	my_tile_image.LoadFromFile("../images/tile2d.png");
	my_tile_image.SetSmooth(false);
    my_tile_sprite = sf::Sprite(my_tile_image);

    int tx, ty;
	for(int i=0 ; i<8 ; i++)
	{
		my_tile_sprite.SetSubRect(sf::Rect<int>(i * LARGEUR_RECTANGLE_QUADRILLAGE * 2, 0, (i+1) * LARGEUR_RECTANGLE_QUADRILLAGE * 2, HAUTEUR_RECTANGLE_QUADRILLAGE * 2));
		my_spriteColor.push_back(my_tile_sprite);

		if( i>3 ) tx= 170;
		else tx= 20;
		ty=((SELECT_HEIGHT/2)*(i%4)) + 310 ;
		my_spriteColor[i].SetPosition( tx,ty);
		my_spriteColor[i].Resize( SELECT_WIDTH/3, SELECT_HEIGHT/3 );
	}

}

MenuView::~MenuView( )
{
	if(_window != NULL) delete _window;
}


/*#############################################################################
/#                                                                            #
/#            ACTION FENETRE                                                  #
/#                                                                            #
##############################################################################*/

// ~~~~~~~~~~~~~~~ Dessin ~~~~~~~~~~~~~~~~~~~~~~~

void MenuView::draw( )
{
/// SEULEMENT SI LA FENETRE EST OUVERTE
	if(_window->IsOpened())
 	{
		updateInfo();
		_window->Draw(my_bgSpt);

/// Etat instable du jeu : trop de piècre ou pas assez
/// indicateur couleur en fonction de l'état
	// ETAT STABLE
		if( _model->getD()*_model->getE()*_model->getF() == _model->getNbTile() )
		{
			my_saveButton.setColor(0,0,0);
			_messAlert.SetColor(sf::Color(48,255,0));
			_messAlert.SetText("Vous Pouvez Enregistrer !");

		}
		else
		{
			my_saveButton.setColor(150,150,150);
			_messAlert.SetColor(sf::Color(255,160,0));
			if( _model->getD()*_model->getE()*_model->getF() > _model->getNbTile() )
				_messAlert.SetText("Enregistrement impossible car\nIl manque des pieces");
			else
				_messAlert.SetText("Enregistrement impossible car\nIl y a trop de pieces");
		}

// affichage bouttons
		afficherButton(_window,&my_newButton);
		afficherButton(_window,&my_loadButton);
		afficherButton(_window,&my_saveButton);
		afficherButton(_window,&my_quitButton);
		afficherButton(_window,&my_mdButton);
		afficherButton(_window,&my_ldButton);
		afficherButton(_window,&my_meButton);
		afficherButton(_window,&my_leButton );
		afficherButton(_window,&my_mfButton);
		afficherButton(_window,&my_lfButton);

// affichage textes
		_window->Draw(_viewD);
		_window->Draw(_viewE);
		_window->Draw(_viewF);
		_window->Draw(_infoTuile);
		_window->Draw(_messAlert);

// affichage du des numéros d'étages avec la couleur associé
// un modulo gère les 2 colonnes et les 4 lignes
// la variable plus gère le décalage pour les numéros
		int x, y;
		int tmp, plus;
		tmp = plus = 0;
		int t = _model->getMaxEtage();
		for(int i=0; i<=t; i++)
		{
			if( tmp<=3 )
			{
				x= 60 + plus;
				tmp++;
			}
			else// if( tmp>3 && tmp<=7 )
			{
				x= 220 + plus;
				tmp++;
			}

			if( tmp > 7)
			{
				tmp=0;
				plus+=30;
			}

			y=((SELECT_HEIGHT/2)*(i%4)) + 310 ;
			_numEtage.SetPosition(x,y);
			_numEtage.SetText( toString(i) );

			if( i<8 ) 				// on dessine qu'une fois chaque couleur
				_window->Draw(my_spriteColor[i]);
			_window->Draw(_numEtage);
		}

		usleep(10000);
		_window->Display();
	}

}

// ~~~~~~~~~~~~~~~~~~~ GESTION DES EVENEMENTS ~~~~~~~~~~~~~~~~~~~~~~~

bool MenuView::treatEvents()
{
	bool result = false;
 	if(_window->IsOpened())
 	{
    	result = true;
    	sf::Event event;
   		while ( _window->GetEvent(event) )
   		{
     		_mouseX = _window->GetInput().GetMouseX();
     		_mouseY = _window->GetInput().GetMouseY();
// boutton "enregistrer"
     		if( _model->getD()*_model->getE()*_model->getF() == _model->getNbTile() )
     		{
				if( clickButton(&event, _mouseX, _mouseY, &my_saveButton) )
				_model->saveLevel("plateau.sav");
			}
// boutton "charger"
			if( clickButton(&event, _mouseX, _mouseY, &my_loadButton) )
			{
				_model->loadLevel("plateau.sav");
				addD(0); addE(0); addF(0);			// valeur 0 modifie rien mais met à jours
			}
// boutton "Nouveau"
			if( clickButton(&event, _mouseX, _mouseY, &my_newButton) )
				_model->clearPlateau();
// boutton "Quitter"
			if( clickButton(&event, _mouseX, _mouseY, &my_quitButton) )
			{
				_game->quit();
				_window->Close();
				exit(0);
			}

// Boutton reglage des parametre d, e & f
			if( clickButton(&event, _mouseX, _mouseY, &my_mdButton) )
				addD(1);
			if( clickButton(&event, _mouseX, _mouseY, &my_ldButton) )
				addD(-1);
			if( clickButton(&event, _mouseX, _mouseY, &my_meButton) )
				addE(1);
			if( clickButton(&event, _mouseX, _mouseY, &my_leButton) )
				addE(-1);
			if( clickButton(&event, _mouseX, _mouseY, &my_mfButton) )
				addF(1);
			if( clickButton(&event, _mouseX, _mouseY, &my_lfButton) )
				addF(-1);

     	}
	}
	return result;
}

void MenuView::openWindow(const bool & open, int x, int y)
{
	if ( ! getWindow() && open )
	{
		delete _window;
		_window = new sf::RenderWindow(sf::VideoMode(_w, _h, 32), "Parametre", sf::Style::Close);
	}
}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS MENU                                                 #
/#                                                                            #
##############################################################################*/


bool MenuView::getWindow() const
{ return _window->IsOpened(); }

void MenuView::setPt(GameModel * model, GameView * game )
{
	_model = model;
	_game = game;
}

// ~~~~~~~~~~~~~~~~~~~~~~ MISE A JOUR DE VALEUR ~~~~~~~~~~~~~~~~~~~~~
// ~~~~~ met à jours dans le model les variables d, e & f

void MenuView::addD( int a )
{
	int d = _model->getD();
	if( (d>2 && a<0) || a>=0 )
	{
		d += a;
		_model->setD(d);
		_viewD.SetText("Tuiles différentes (d) : " + toString(d) );
	}
}

void MenuView::addE( int a )
{
	int e = _model->getE();
	if( (e>2 && a<0) || a>=0 )
	{
		e += a;
		_model->setE(e);
		_viewE.SetText("Eliminations simultanes (e) : " + toString(e) );
	}
}

void MenuView::addF( int a )
{
	int f = _model->getF();
	if( (f>2 && a<0) || a>=0 )
	{
		f += a;
		_model->setF(f);
		_viewF.SetText("Tuiles identiques (f) : " + toString(f) + "\na eliminer simultanement" );
	}
}

//~~~~~~~~~~~~~~~~~~~~~ MISE A JOURS DU TEXTE INFORMATION ~~~~~~~~~~~~~~~~~~~~~~~

void MenuView::updateInfo()
{
	int d = _model->getD();
	int e = _model->getE();
	int f = _model->getF();

	int total = d*e*f;
	int rest, trop = 0;
	if ( total - _model->getNbTile() >= 0 )
	{
		rest = total - _model->getNbTile();
		trop = 0;
	}
	else
	{
		trop = _model->getNbTile() - total;
		rest = 0;
	}
	_infoTuile.SetText("Nombre de tuiles a placee : " + toString(total) + "\n- tuiles restantes = " + toString(rest) + "\n- tuiles en trop = " + toString(trop) + "\n\n\nNumero etage en fonction de la couleur :");
}
