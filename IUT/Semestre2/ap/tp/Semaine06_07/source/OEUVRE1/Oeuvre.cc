// fichier Oeuvre.cc

#include <iostream>
#include <string>

#include "Oeuvre.h"
#include "util.h"

using namespace std;

Oeuvre::Oeuvre( string aut, string titre, string sty,
		int j, int m, int a, int val )
{
  cout << "appel constructeur Oeuvre..." << endl;
  my_auteur = aut;
  my_titre = titre;
  my_style = sty;
  my_jour = j;
  my_mois = m;
  my_annee = a;
  my_valest = val;
}

Oeuvre::~Oeuvre()
{
  cout << "appel destructeur Oeuvre..." << endl;
}

string
Oeuvre::toString() const
{
  string aff = "";
  aff += "Affichage de Oeuvre :\n" ;
  aff += "Titre      :  " + my_titre +"\n";
  aff += "Auteur     :  " + my_auteur +"\n";
  aff += "Style      :  " + my_style +"\n";
  aff += "Cree(e) le :  " + intToString(my_jour) + "/" + 
    intToString(my_mois) + "/" +intToString(my_annee) +"\n";
  aff += "Valeur     :  " + intToString(my_valest) + " euros" +"\n";
  return aff;
}

