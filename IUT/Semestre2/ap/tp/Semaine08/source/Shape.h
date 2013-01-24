#ifndef __MYSHAPE__
#define __MYSHAPE__

#include "Screen.h"

class Shape
{
  protected:
    char my_col;
	
  public:
    virtual ~Shape();
    virtual void draw( Screen & s ) = 0;
    virtual void move( int dx, int dy ) = 0;
	
    void setColour( char col );
    char getColour( ) const;
};

#endif

