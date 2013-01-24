#ifndef VERIF_HH
#define VERIF_HH

#include "struct.hh"


/********* verifie si 3 diamant ou plus sont alignés en colone *****/
bool solutioncolone(board &tab);

/********* verifie si 3 diamant ou plus sont alignés en ligne ******/
bool solutionligne(board &tab);

/********* verification du cote à cote ****************************/
bool acote (board &tab);

/********* verification des solutions general restante ************/
bool verifgenerale(board & tab) ;

/********* verification des bonnes coordonnées de la sourie ************/
bool goodmouse (board tab, int x, int y);

#endif
