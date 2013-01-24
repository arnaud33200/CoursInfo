// fichier Peinture.cc

#include <iostream>
#include <string>
#include "Peinture.h"
#include "Oeuvre.h"
#include "Date.h"
#include "util.h"

using namespace std;

Peinture::Peinture( string artiste, string titre, string sty,
                    int j, int m, int a, int val,
		    		string poss, int ja, int ma, int aa, string sup, string mat )
: Oeuvre(artiste, titre, sty, j, m, a, val),
  my_date_acquis(ja,ma,aa)
{  // appel constr. cl. de base Oeuvre ET constr. Date
  cout << "appel constructeur Peinture..." << endl;
  my_possesseur = poss;
  my_support = sup;
  my_matiere = mat;
  // pas besoin de modifier my_date_acquis
}

Peinture::Peinture( const Peinture & p )
: Oeuvre(p)
{
	my_support = p.my_support;
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
  inf +=  "Acquis(e) le :  " + my_date_acquis.toString()+"\n";
  return inf;
}

