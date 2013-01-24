#ifndef VERIF_HH
#define VERIF_HH

#include "struct.hh"


/********* Vérifie si trois diamant ou plus sont alignés en colonne *****/
bool solutioncolone(board &tab);

/********* Vérifie si trois diamant ou plus sont alignés en ligne ******/
bool solutionligne(board &tab);

/********* Vérification du côte à côte ****************************/
bool acote (board &tab);

/********* Vérification des solutions generales restantes ************/
bool verifgenerale(board & tab) ;

/********* Vérification des bonnes coordonnées de la souris ************/
bool goodmouse (board tab, int x, int y);

#endif
