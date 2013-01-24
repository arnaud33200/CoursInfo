#ifndef _TILE_
#define _TILE_

#include "constantes.h"

class Tile
{
    private:
///################ ATRIBUTS ####################
        int my_x_tile, my_y_tile , my_z_tile;

    public:
///################ CONSTRUCTEURS & DESTRUCTEURS ####################
        Tile();
        Tile(const int x_tile, const int y_tile, const int z_tile);
        Tile(const  Tile &tile);
        ~Tile();

///################ ACCESSEURS ####################
        int getXTile() const;
        int getYTile() const;
        int getZTile() const;

        void setXTile(const int &x_tile);
        void setYTile(const int &y_tile);
        void setZTile(const int &z_tile);
};

#endif


