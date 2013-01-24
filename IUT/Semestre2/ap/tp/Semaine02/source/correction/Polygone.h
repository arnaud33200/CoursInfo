// Fichier Polygone.h

#ifndef _POLYGONE_
#define _POLYGONE_

#include "Point.h"

#include <sstream>
#include <string>

using namespace std;

class Polygone {
	
private:

  static const int MAX=5;
  Point my_tab[MAX];
  int my_taille;
  
public:
  Polygone();
  ~Polygone();
  Polygone( const Polygone & poly );
  Polygone & operator=( const Polygone & poly );
  void saisie();
  string toString() const;
  void deplace ( float dep_x, float dep_y );
  void ajoutSommet( const Point & p );
  float perimetre() const;
  void litFichier( string nom_fic );
  void ecritFichier( string nom_fic ) const;
  int taille() const;
  // Point getPoint( int ind ) const;  
  // ou
  const Point & getPoint( int ind ) const;  
};

ostream& operator<<(ostream& out, const Polygone& p); 
#endif

