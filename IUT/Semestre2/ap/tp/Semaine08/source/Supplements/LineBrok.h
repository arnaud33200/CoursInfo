#ifndef __MYLINEBROK__
#define __MYLINEBROK__

#include "Screen.h"
#include "Line.h"
#include "Point.h"

class LineBrok : public Line
{
  protected:
    Point my_m;
	
  public:
    LineBrok( char col, const Point & a, const Point & b, const Point & m );
    virtual ~LineBrok();
    virtual void move( int dx, int dy );
    virtual void draw( Screen & s );
};

#endif

