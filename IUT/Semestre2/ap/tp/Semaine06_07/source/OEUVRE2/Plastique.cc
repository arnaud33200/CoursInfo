#include <iostream>
#include <string>

#include "Plastique.h"
#include "Oeuvre.h"
#include "Date.h"
#include "util.h"

using namespace std;

// souci : constructeur ma default avec "my_appart(ap), my_materiaux(mat)"

Plastique::Plastique( string aut, string t, string s, int j, int m, int a,
					int v, string ap, int cj, int cm, int ca, string mat )
: Oeuvre(aut, t, s, j, m, a, v), my_change(cj, cm, ca)
{
	my_appart = ap;
	my_materiaux = mat;
}

Plastique::Plastique( const Plastique & p )
: Oeuvre(p)
{
	my_materiaux = p.my_materiaux;
}

Plastique::~Plastique()
{}

string Plastique::toString() const
{
  string inf = "Affichage de art plastique :\n";
  inf += Oeuvre::toString();  // classe de base
  inf += "Appartient à   :  " + my_appart +"\n";
  inf += "Acquis(e) le :  " + my_change.toString()+"\n";
  inf += "fait avec  :  " + my_materiaux + "\n";
  return inf;
}
