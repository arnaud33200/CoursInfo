#ifndef GESTION_H
#define GESTION_H

#include <string>

#include "Liste.h"
#include "Etudiant.h"

typedef Liste<Etudiant>::TIterator TAdresse;

// ~~~~~~~~~~~~ Pour des listes non triée ~~~~~~~~~~~~~

void saisirListe( Liste<Etudiant>* l );
void afficherListe( const Liste<Etudiant>* & l );
int rangEtudiant( const string & n, const Liste<Etudiant>* & l );
float moyenNote( const Liste<Etudiant>* & l );

// ~~~~~~~~~~~~ Pour des listes triée ~~~~~~~~~~~~~~~~

void ajouterEtudiant( Liste<Etudiant>* l, const Etudiant & etu );

#endif // GESTION_H
