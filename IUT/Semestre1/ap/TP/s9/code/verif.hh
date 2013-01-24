#ifndef VERIF_HH
#define VERIF_HH

#include "const.hh"

bool verifcase( int tab[][nbcase], int i, int j);

bool verifligne (int tab[][nbcase], int joueur );

bool verifcolone (int tab[][nbcase], int joueur );

bool verifdiago (int tab[][nbcase], int joueur );
#endif
