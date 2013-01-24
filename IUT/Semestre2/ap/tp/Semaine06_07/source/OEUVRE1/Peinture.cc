// fichier Peinture.cc

#include <iostream>
#include <string>
#include "Peinture.h"
#include "Oeuvre.h"
#include "util.h"

using namespace std;

Peinture::Peinture( string artiste, string titre, string sty,
                    int j, int m, int a, int val,
		    string poss, int ja, int ma, int aa )
: Oeuvre(artiste, titre, sty, j, m, a, val)
{             // appel constr. cl. de base Oeuvre
  cout << "appel constructeur Peinture..." << endl;
  my_possesseur = poss;
  my_jour_a = ja;
  my_mois_a = ma;
  my_annee_a = aa;
}

Peinture::~Peinture()
{
  cout << "appel destructeur Peinture..." << endl;
}

string
Peinture::toString() const
{
  string inf = "Affichage de Peinture :\n";
  inf += Oeuvre::toString();  // classe de base
  inf += "Possesseur   :  " + my_possesseur +"\n";
  inf +=  "Acquis(e) le :  " + intToString(my_jour_a) + "/"
    + intToString(my_mois_a) + "/" + intToString(my_annee_a) +"\n";
  return inf;
}

