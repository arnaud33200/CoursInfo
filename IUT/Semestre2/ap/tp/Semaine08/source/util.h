#ifndef __MYUTIL__
#define __MYUTIL__

#include "Point.h"

enum color{ white=' ', black='*', red='µ', green='#', blue='%' };

void cinColour( char & col );
void cinPoint( Point & a );

void cinLine( char & col, Point & sw, Point & ne );
void cinLineHoriz( char & col, Point & sw, int & w );

void cinLineBrok( char & col, Point & sw, Point & ne, Point & m );

void cinRectangle( char & col, Point & sw, Point & ne );

void cinCircle( char & col, Point & c, int & r );

void cinTriangle( char & col, Point & f, Point & s, Point & t);

void cinSquare( char & col, Point & p, int & c );

#endif

