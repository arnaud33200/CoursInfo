//~ fonction.hh

#ifndef INIT_HH
#define INIT_HH

#include<iostream>
#include<string>

#include "struct.hh"


/************* initialise certaine case de la grille au hazard ******/
void initgrille ( board & tab);

/************* initialise toute les images du jeu *******************/
void initpicture (board &tab);

/************* initialise le jeu en fonction du niveau choisi *******/
void initsaveconfig (board &tab, saveconfig &save);

#endif
