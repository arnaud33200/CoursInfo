#include "GameView.h"
#include "GameModel.h"
#include "MenuView.h"

int main()
{
    GameModel * model = new GameModel(SCREEN_WIDTH, SCREEN_HEIGHT);
    GameView * view = new GameView(SCREEN_WIDTH, SCREEN_HEIGHT);
    MenuView * menu = new MenuView(320, 700, 0,0);
    view->setModel(model);
    menu->setPt(model, view);

    while( view->treatEvents() )
    {
		menu->treatEvents();
        view->draw();
        menu->draw();
    }

    delete menu;
    delete view;
    delete model;

    return EXIT_SUCCESS;
}
