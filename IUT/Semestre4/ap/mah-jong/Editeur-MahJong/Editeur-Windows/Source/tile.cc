#include "tile.h"

/*#############################################################################
/#                                                                            #
/#            CONSTRUCTEUR & DESTRUCTEUR                                      #
/#                                                                            #
##############################################################################*/

Tile::Tile(const int x_tile, const int y_tile, const int z_tile)
{
    my_x_tile = x_tile;
    my_y_tile = y_tile;
    my_z_tile = z_tile;
}

Tile::Tile(const Tile &tile)
{
    my_x_tile = tile.my_x_tile;
    my_y_tile = tile.my_y_tile;
    my_z_tile = tile.my_z_tile;
}

Tile::~Tile()
{}


/*#############################################################################
/#                                                                            #
/#            ACCESSEURS                                                      #
/#                                                                            #
##############################################################################*/

int Tile::getXTile() const
{ return my_x_tile; }

int Tile::getYTile() const
{ return my_y_tile; }

int Tile::getZTile() const
{ return my_z_tile; }

void Tile::setXTile(const int &x_tile)
{ my_x_tile = x_tile; }

void Tile::setYTile(const int &y_tile)
{ my_y_tile = y_tile; }

void Tile::setZTile(const int &z_tile)
{ my_z_tile = z_tile; }
