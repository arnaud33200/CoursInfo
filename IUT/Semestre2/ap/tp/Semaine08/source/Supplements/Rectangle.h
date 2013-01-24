#ifndef __MYRECTANGLE__
#define __MYRECTANGLE__

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape
{
  private:
    void search_sw_ne( const Point & a, const Point & b );

  protected: 
    Point my_sw, my_ne;
	
  public:
    Rectangle( char col, const Point & a, const Point & b );
    Rectangle( char col, const Point & a, int width, int height );
    virtual ~Rectangle();
    virtual void move( int dx, int dy );
    virtual void draw( Screen & s );
};

#endif
