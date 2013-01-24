// fichier Peinture.h

#ifndef PEINTURE_H
#define PEINTURE_H

#include <string>
#include "Oeuvre.h" // declarons la classe de base

using namespace std;

class Peinture : public Oeuvre {   // heritage ...
public:
   Peinture( string artiste, string titre, string sty,
             int j, int m, int a, int val,
             string poss, int ja, int ma, int aa );
   ~Peinture();
   string info() const;       // renseignons nous sur la peinture...
private:                           // ajoutons de nouveaux elements
   string my_possesseur;
   int my_jour_a, my_mois_a, my_annee_a;  // date d'acquisition
};

#endif // #ifndef PEINTURE_H

