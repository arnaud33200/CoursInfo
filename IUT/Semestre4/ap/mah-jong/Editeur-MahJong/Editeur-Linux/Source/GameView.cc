#include "GameView.h"


bool result;
int mouseX, mouseY;
int i, j;
int tileColor = 0;
int selectionX, selectionY;


/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

GameView::GameView(const int &w, const int &h) : my_w(w), my_h(h)
{
    my_window = new sf::RenderWindow(sf::VideoMode( w, h, 32), "..:: Mahjong - Editeur de Plateau ::..", sf::Style::Close);
    my_window->ShowMouseCursor(false);
    my_window->SetPosition(281,0);

    my_quit = false;

    if (!my_selection_image.LoadFromFile("../images/selection.png") || !my_quadrillage_image.LoadFromFile("../images/quadrillage2.png") ||
        !my_tile_image.LoadFromFile("../images/tile2d.png"))
    {
        my_quadrillage_sprite = sf::Sprite();
        my_selection_sprite = sf::Sprite();
        my_tile_sprite = sf::Sprite();
    }
    else
    {
        my_quadrillage_image.SetSmooth(false);
        my_quadrillage_sprite = sf::Sprite(my_quadrillage_image);
        my_quadrillage_sprite.Resize(SCREEN_WIDTH, SCREEN_HEIGHT);
        my_quadrillage_sprite.SetPosition(0,0);

        my_selection_image.SetSmooth(false);
        my_selection_sprite = sf::Sprite(my_selection_image);
        my_selection_sprite.Resize(SELECT_WIDTH, SELECT_HEIGHT);
        my_selection_sprite.SetPosition((SCREEN_WIDTH - SELECT_WIDTH) / 2 ,(SCREEN_HEIGHT - SELECT_HEIGHT) / 2);

        my_tile_image.SetSmooth(false);
        my_tile_sprite = sf::Sprite(my_tile_image);

        for(int i=0 ; i<8 ; i++)
        {
            my_tile_sprite.SetSubRect(sf::Rect<int>(i * LARGEUR_RECTANGLE_QUADRILLAGE * 2, 0, (i+1) * LARGEUR_RECTANGLE_QUADRILLAGE * 2, HAUTEUR_RECTANGLE_QUADRILLAGE * 2));
            my_spriteColor.push_back(my_tile_sprite);
        }
    }
}

GameView::~GameView()
{
    if(my_window != NULL)
        delete my_window;
}

/*#############################################################################
/#                                                                            #
/#            ACTIONS FENETRE                                                 #
/#                                                                            #
##############################################################################*/

// ~~~~~~~~~~~~~~~~~ Gère l'affichage de tous les éléments

void GameView::draw()
{
    my_window->Draw(my_quadrillage_sprite);
    drawTile();
    my_window->Draw(my_selection_sprite);

    my_window->Display();

    usleep(10000);
}

void GameView::drawTile()
{
    std::vector<Tile> tmp;
    tmp = *my_model->getPlateau();

    for(unsigned int k=0 ; k < tmp.size() ; k++)
    {
        tileColor = tmp[k].getZTile() % 8;
        my_spriteColor[tileColor].SetPosition(MARGIN_LEFT + tmp[k].getXTile() * LARGEUR_RECTANGLE_QUADRILLAGE, MARGIN_TOP + tmp[k].getYTile() * HAUTEUR_RECTANGLE_QUADRILLAGE);
        my_window->Draw(my_spriteColor[tileColor]);
    }
}

// ~~~~~~~~~~~~~~~~~~~~ Gére les évenements de la fenètre
// ~~~~~~~~~~~ @return FALSE lorsque un évenement as entrainé la fermeture du parametre my_window

bool GameView::treatEvents()
{
    if(my_window->IsOpened())
    {
        result = true;
        sf::Event event;
        const sf::Input &input = my_window->GetInput();

        while(my_window->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                my_window->Close();
                result = false;
            }

            if (event.Type == sf::Event::MouseMoved)
                eventSelection(input);

            if(event.Type == sf::Event::MouseButtonPressed)
                eventPoseTile(input);
        }
    }
    return result;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~ EVENEMENT DE SELECTION DE TUILES ~~~~~~~~~~~~~~~~~~~~~~~

void GameView::eventSelection(const sf::Input &input)
{
    mouseX = my_window->GetInput().GetMouseX();
    mouseY = my_window->GetInput().GetMouseY();

	selectionX = ((mouseX - MARGIN_LEFT) / LARGEUR_RECTANGLE_QUADRILLAGE);
	selectionY = ((mouseY - MARGIN_TOP) / HAUTEUR_RECTANGLE_QUADRILLAGE);

    if(selectionX < LARGEUR_PLATEAU && selectionY < HAUTEUR_PLATEAU)
    	my_selection_sprite.SetPosition(selectionX * LARGEUR_RECTANGLE_QUADRILLAGE + MARGIN_LEFT, selectionY * HAUTEUR_RECTANGLE_QUADRILLAGE + MARGIN_TOP);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~ EVENEMENT DE POSE DE TUILES ~~~~~~~~~~~~~~~~~~~~~~~

void GameView::eventPoseTile(const sf::Input &input)
{
    mouseX = my_window->GetInput().GetMouseX();
    mouseY = my_window->GetInput().GetMouseY();

    if(mouseX >= MARGIN_LEFT && mouseX <= SCREEN_WIDTH - MARGIN_RIGHT - LARGEUR_RECTANGLE_QUADRILLAGE - 5 && mouseY >= MARGIN_TOP && mouseY <= SCREEN_HEIGHT - MARGIN_BOTTOM - HAUTEUR_RECTANGLE_QUADRILLAGE - 5)
    {
        if(input.IsMouseButtonDown(sf::Mouse::Left))
        {
            i = (mouseX - MARGIN_LEFT) / LARGEUR_RECTANGLE_QUADRILLAGE;
            j = (mouseY - MARGIN_TOP) / HAUTEUR_RECTANGLE_QUADRILLAGE;

            my_model->addTile(i, j);
        }

        else if(input.IsMouseButtonDown(sf::Mouse::Right))
        {
            i = (mouseX - MARGIN_LEFT) / LARGEUR_RECTANGLE_QUADRILLAGE;
            j = (mouseY - MARGIN_TOP) / HAUTEUR_RECTANGLE_QUADRILLAGE;

            my_model->delTile(i, j);
        }
    }
}

/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/

void GameView::quit()
{
	 my_quit =true;
}

/// Attribue un GameModel à la classe GameView

void GameView::setModel(GameModel * model)
{
    my_model = model;
}
