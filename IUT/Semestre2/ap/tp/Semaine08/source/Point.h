// Fichier Point.h

#ifndef __MYPOINT__
#define __MYPOINT__

#include <sstream>
#include <string>

using namespace std;

class Point
{ 
	private :
    	int my_abs, my_ord;

  	public :
    	Point( int x, int y );                     // constructeur
	    Point();                                   // constructeur par defaut
	    ~Point();                                  // destructeur
	    Point( const Point & p );                  // constructeur par copie
	    Point & operator=( const Point & p );      // operateur d'affectation
	    string toString() const;
	    int getX() const;
	    int getY() const;
	    void setX( int new_x );
	    void setY( int new_y );
	    // quelques services
	    void deplace( int d_x, int d_y );
	    bool operator==( const Point & p ) const;
	    bool operator<( const Point & p) const;
};

ostream& operator<<(ostream& out, const Point& p);
#endif

