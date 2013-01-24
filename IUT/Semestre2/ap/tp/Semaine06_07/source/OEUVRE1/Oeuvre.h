// fichier Oeuvre.h

#ifndef OEUVRE_H
#define OEUVRE_H

#include <string>

using namespace std;

class Oeuvre {
public:
   Oeuvre( string aut, string titre, string sty,
           int j, int m, int a, int val );
  // virtual
   ~Oeuvre();
  // virtual
   string toString() const;
private:
   string my_auteur;
   string my_titre;
   string my_style;
   int my_jour, my_mois, my_annee;  // date de creation 
   int my_valest;
};

#endif // #ifndef OEUVRE_H

