#ifndef __MYLINE__
#define __MYLINE__

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Line : public Shape
{
  protected:
    Point my_w, my_e;
	
  public:
    Line( char col, const Point & a, const Point & b );
	Line( char col, const Point & a, int l );
    virtual ~Line();
    virtual void move( int dx, int dy );
    virtual void draw( Screen & s );
};

#endif

