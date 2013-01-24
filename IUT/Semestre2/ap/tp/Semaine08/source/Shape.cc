#include "Shape.h"


Shape::~Shape()
{}

void
Shape::setColour( char col )
{
  my_col = col;
}

char
Shape::getColour( ) const
{
  return my_col;
}
