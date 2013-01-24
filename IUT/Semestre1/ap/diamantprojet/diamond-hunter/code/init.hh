//~ fonction.hh

#ifndef INIT_HH
#define INIT_HH

#include<iostream>
#include<string>

#include "struct.hh"


/************* Initialise certaines cases de la grille au hazard ******/
void initgrille ( board & tab);

/************* Initialise toutes les images du jeu *******************/
void initpicture (board &tab);

/************* Initialise le jeu en fonction du niveau choisi *******/
void initsaveconfig (board &tab, saveconfig &save);

#endif
