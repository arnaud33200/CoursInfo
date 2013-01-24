// Fichier Boite.cc

// ... a completer par vos soins.

#include <iostream>
#include "Boite.h"
#include "Point.h"

using namespace std;

// PAS BESOIN DE L'ECRIRE...
// le compilateur ne rale pas...
//Boite::Boite() {};

Boite::Boite( const Point & p )
  : my_bas_gauche( p ), my_haut_droite( p )
{
  my_nb_alloues = 5;
  my_points = new Point[ my_nb_alloues ];
  my_points[ 0 ] = p;
  my_nb_points = 1;
}

void
Boite::affiche() const
{
}

bool
Boite::interieur( const Point & p ) const
{
  return ( p.getX() >= my_bas_gauche.getX() )
         && ( p.getX() <= my_haut_droite.getX() )
         && ( p.getY() >= my_bas_gauche.getY() )
         && ( p.getY() <= my_haut_droite.getY() );
}

void
Boite::agrandir()
{
  my_nb_alloues *= 2;
  Point* tbl = new Point[ my_nb_alloues ];
  // recopie
  for( int i=0; i<my_nb_points; i++ )
    tbl[ i ] = my_points[ i ];
	
  delete[] my_points;
  my_points = tbl;
}

Boite::~Boite()
{
  delete[] my_points;
}

void
Boite::ajouterPoint( const Point & p )
{
  if ( my_nb_alloues == my_nb_points ) 
    agrandir();
  if ( ! interieur( p ) )
    {
      if ( p.getX() < my_bas_gauche.getX() )
        my_bas_gauche.setX( p.getX() );
      else if ( p.getX() > my_haut_droite.getX() )
        my_haut_droite.setX( p.getX() );
      if ( p.getY() < my_bas_gauche.getY() )
        my_bas_gauche.setY( p.getY() );
      else if ( p.getY() > my_haut_droite.getY() )
        my_haut_droite.setY( p.getY() );
    }
  my_points[ my_nb_points ] = p;
  my_nb_points++;
}

void
supprimerPoint( const Point & p )
{
}
