#ifndef __MYSCREEN__
#define __MYSCREEN__

#include "Point.h"

class Screen
{
  private:
    static const int XMAX = 60;
    static const int YMAX = 44;
	char my_screen[XMAX][YMAX];   // écran virtuel (zone) pour dessiner
	
	char my_colPen;               // couleur courante (du crayon) pour le dessin
	
  public:
    Screen();
    void clear();      // efface l'écran (zone) de dessin
    void refresh();    // reaffiche l'écran (zone) de dessin
	
	// accesseurs pour la couleur du crayon
	void setColPen( char col );
	char getColPen() const;
	
	// methodes pour verifier des coordonnees
    bool on_screen( const Point & p ) const; 
    bool on_screen( int a, int b ) const;
	
	// primitives de dessin
    void put_point( const Point & p );
    void put_point( int a, int b );
	
    void put_line( const Point & p1, const Point & p2 );
    void put_line( int x1, int y1, int x2, int y2 );
	
	void put_circle( const Point & center, int radius );
};

#endif

