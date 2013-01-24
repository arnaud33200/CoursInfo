#ifndef __MYCIRCLE__
#define __MYCIRCLE__

#include "Screen.h"
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
  private:
    void put_circle_point( Screen & s, int x, int y );
	void draw_circle_points( Screen & s, const Point & pt );
	
  protected:
    Point my_center;
    int my_radius;
	
  public:
    Circle( char col, const Point & a, int r );
    virtual ~Circle();
    virtual void move( int dx, int dy );
    virtual void draw( Screen & s );
};

#endif
