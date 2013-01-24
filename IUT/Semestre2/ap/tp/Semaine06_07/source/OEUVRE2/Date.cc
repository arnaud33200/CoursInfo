// fichier Date.cc

#include <iostream>
#include <string>
#include "Date.h"
#include "util.h"

using namespace std;

Date::Date()
{
  cout << "appel Date()" << endl;
  my_jour = 1;
  my_mois = 1;
  my_annee = 1970;
}

Date::~Date()
{
  cout << "appel ~Date()" << endl;
}

Date::Date( int j, int m, int a )
{
  cout << "appel Date( int j, int m, int a )" << endl;
  my_jour = j;
  my_mois = m;
  my_annee = a;
}

Date::Date( const Date & d )
{
  cout << "appel Date( const Date & d )" << endl;
  my_jour = d.my_jour;
  my_mois = d.my_mois;
  my_annee = d.my_annee;
}

void
Date::setDate( int j, int m, int a )
{
  my_jour = j;
  my_mois = m;
  my_annee = a;
}

void
Date::getDate( int &j, int &m, int &a ) const
{
  j = my_jour;
  m = my_mois;
  a = my_annee;
}

string
Date::toString() const
{
  return intToString(my_jour)+"/" + intToString(my_mois)
    + "/" +intToString(my_annee);
}

