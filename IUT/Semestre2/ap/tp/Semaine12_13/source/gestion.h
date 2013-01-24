///////////////////////////////////////////////////////////////////////////////
// gestion.h
///////////////////////////////////////////////////////////////////////////////

#ifndef GESTION_H
#define GESTION_H

#include <fstream>

#include "Liste.h"
#include "Etudiant.h"

// Raccourci pour TAdresse
typedef Liste<Etudiant>::TIterator TAdresse;


// comme son nom l'indique...
void afficherListe( const Liste<Etudiant> & liste );


// crée une liste à partir d'un fichier
void fic2liste( const string & file, Liste<Etudiant> & l );
void liste2fic( const string & file, Liste<Etudiant> & l );

// sauvegarde une liste dans un fichier
// A FAIRE 


// et tout ce qui peut servir...
// à compléter

#endif
