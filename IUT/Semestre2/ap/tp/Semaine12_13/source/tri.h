#ifndef TRI_H
#define TRI_H

#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

TAdresse adrElemMedian( const Liste<Etudiant> & l, const TAdresse & a, const TAdresse & b );

void fusion( Liste<Etudiant> & l, const TAdresse & m, const TAdresse & a, const TAdresse & b);


#endif
