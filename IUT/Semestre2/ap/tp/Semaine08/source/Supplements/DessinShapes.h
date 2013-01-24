#ifndef __MYDESSINSHAPES__
#define __MYDESSINSHAPES__

#include "Shape.h"
#include "Screen.h"

class DessinShapes
{
	private:
		static const int MAX = 100;
		Shape * my_tabShapes[MAX];
		int my_nbShapes;
		
	public:
		DessinShapes();
		~DessinShapes();
		
		void addShape( Shape * pshape );
		void refresh( Screen & s );
		
		void setColourAll( char col);
		void moveAll( int dx, int dy);
		void eraseAll();
		
		Shape* select( const int & ind );
		void setColour( char col, int ind );
		void move( int dx, int dy, int ind);
		void erase(int ind);
		
};


#endif

