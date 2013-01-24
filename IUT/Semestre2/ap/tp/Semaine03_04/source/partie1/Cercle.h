// Fichier Cercle.h

#ifndef __CERCLE__
#define __CERCLE__

#include <sstream>
#include <string>

#include "Point.h"

using namespace std;

class Cercle 
{ 
	private :
	
    	Point my_centre;
    	float my_rayon;
    	
  	public :
  	
   		Cercle();                                   // constructeur par defaut
    	~Cercle();                                  // destructeur
    	Cercle( float r );                          // constructeur rayon
    	Cercle( float r, float x, float y );        // constructeur rayon + x + y
    	Cercle( float r, const Point & p ); 
    	Cercle( const Cercle & c );        // constructeur rayon + point
    	
    	Cercle & operator=( const Cercle & c );
    	string toString() const;
    	// ... a completer par vos soins.
};

ostream& operator<<(ostream& out, const Cercle& c);
#endif

