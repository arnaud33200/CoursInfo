// Fichier Polygone.c

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cassert>
#include "Polygone.h"
#include "Point.h"

using namespace std;

ostream& operator<<(ostream& out, const Polygone& p){
  out << p.toString();
  return out;
}

Polygone::Polygone() 
{
  cout << "Polygone::Constructeur par defaut" << endl;
  my_taille = 0;
}

Polygone::~Polygone() 
{
  cout << "Polygone::Destructeur" << endl;
}

Polygone::Polygone( const Polygone & poly )
{
  cout << "Polygone::Constructeur par copie" << endl;
  my_taille = poly.my_taille;
  for(int i=0; i<my_taille; i++)
    my_tab[i] = poly.my_tab[i];
}

Polygone &
Polygone::operator=( const Polygone & poly )
{
  cout << "Polygone::Operateur affectation" << endl;
  if( this != &poly )
  {
    my_taille = poly.my_taille;
    for(int i=0; i<my_taille; i++)
      my_tab[i] = poly.my_tab[i];
  }
  return *this;
}
  
void
Polygone::saisie()
{
  float val;
  do {
    cout << "nb de sommets : ";
    cin >> my_taille;
  } while (my_taille <0 || my_taille > MAX);
  for (int i=0; i<my_taille; i++) {
    cout << i << " : abs ? ";
    cin >> val;
    my_tab[i].setX(val);
    cout << i << " : ord ? ";
    cin >> val;
    my_tab[i].setY(val);
  }
}

string 
Polygone::toString() const
{
  string p_s = "";
  for (int i=0; i<my_taille; i++)
      p_s += my_tab[i].toString() + "\n";
  return p_s;
}

void
Polygone::deplace( float dep_x, float dep_y )
{
  for (int i=0; i<my_taille; i++)
    my_tab[i].deplace( dep_x, dep_y );
}

void
Polygone::ajoutSommet (const Point & p)
{
  // A l'execution, message d'erreur si condition non respectee
  assert(my_taille < MAX);

  my_tab[my_taille] = p;
  my_taille ++;
}

float
Polygone::perimetre() const
{
  float res = 0 ;
  if (my_taille > 1) {
    for (int i=0; i<my_taille-1; i++)
      res = res + my_tab[i].distance(my_tab[i+1]) ;
    res = res + my_tab[0].distance(my_tab[my_taille-1]) ;
  }
  return res ;
}


// on suppose que le fichier ne contient pas plus de Point que MAX
void
Polygone::litFichier( string nom_fic )
{
  fstream f;
  Point p;

  f.open( nom_fic.data(), ios::in );
  if ( f.fail() ) {
    cerr << "Pb ouverture fichier en lecture" << endl;
    exit( -1 );
  }

  my_taille = 0;  // polygone vide au depart
  p.litFlux( f );
  while ( !f.eof() ) {
    // PEUT-ETRE TESTER S'IL N'Y EST PAS DEJA...
    // ==> rajout methode bool contient( const Point & p )
    ajoutSommet( p );
    p.litFlux( f );
  }

  f.close();
}

void
Polygone::ecritFichier( string nom_fic ) const
{
  fstream f;
  
  f.open( nom_fic.data(), ios::out );
  if ( f.fail() ) {
    cerr << "Pb ouverture fichier en ecriture" << endl;
    exit( -1 );
  }

  for (int i=0; i<my_taille; i++)
      my_tab[i].ecritFlux(f);

  f.close();
}


int
Polygone::taille() const
{
  return my_taille;
}


// Point
// ou
const Point & 
Polygone::getPoint( int ind ) const
{
  // A l'execution, message d'erreur si condition non respectee
  assert( ( ind >= 0 ) && ( ind < my_taille ) );

  return my_tab[ ind ];
}

