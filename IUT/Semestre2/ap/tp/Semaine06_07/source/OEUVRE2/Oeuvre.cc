// fichier Oeuvre.cc

#include <iostream>
#include <string>
#include "Oeuvre.h"
#include "Date.h"
#include "util.h"

using namespace std;

Oeuvre::Oeuvre( string aut, string titre, string sty, int j, int m, int a, int val )
 : Date(j,m,a)
{
  cout << "appel constructeur Oeuvre..." << endl;
  my_auteur = aut;
  my_titre = titre;
  my_style = sty;
  my_valest = val;
}

Oeuvre::~Oeuvre()
{
  cout << "appel destructeur Oeuvre..." << endl;
}

Oeuvre::Oeuvre( const Oeuvre & o )
{
	my_auteur = o.my_auteur;
	my_titre = o.my_titre;
	my_style = o.my_style;
}

string
Oeuvre::toString() const
{
  string aff = "";
  aff += "Affichage de Oeuvre :\n" ;
  aff += "Titre      :  " + my_titre +"\n";
  aff += "Auteur     :  " + my_auteur +"\n";
  aff += "Style      :  " + my_style +"\n";
  aff += "Cree(e) le :  " +  my_date_creation.toString()+"\n";
  aff += "Valeur     :  " + intToString(my_valest) + " euros" +"\n";
  return aff;
}

