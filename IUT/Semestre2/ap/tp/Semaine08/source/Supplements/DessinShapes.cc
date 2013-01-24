#include <iostream>
#include <cstdlib>

#include "DessinShapes.h"
#include "Screen.h"
#include "util.h"

DessinShapes::DessinShapes()
{
	my_nbShapes = 0;
}

DessinShapes::~DessinShapes()
{}

void DessinShapes::addShape( Shape * pshape )
{
	if ( my_nbShapes < MAX )
	{
		//~ cout << "enregistrement dans la case " << my_nbShapes << endl;
		my_tabShapes[my_nbShapes] = pshape;
		my_nbShapes++;
	}
}

void DessinShapes::refresh( Screen & s )
{
	s.clear();
	for ( int i=0; i<my_nbShapes; i++ )
	{
		//~ cout << "affichage du shape numero " << i << endl;
		my_tabShapes[i]->draw(s);
	}
	s.refresh();
}

// ################ modification générale ########################

void DessinShapes::setColourAll( char col)
{
	cinColour(col);
	for ( int i=0; i<my_nbShapes; i++ )
		my_tabShapes[i]->setColour(col);
}

void DessinShapes::moveAll( int dx, int dy)
{
	cinPoint(dx, dy);
	for ( int i=0; i<my_nbShapes; i++ )
		my_tabShapes[i]->move(dx,dy);
}

void DessinShapes::eraseAll()
{
	for ( int i=0; i<my_nbShapes; i++ )
		my_tabShapes[i] = NULL;
	my_nbShapes = 0;
}


// ################## modification individuel ######################

Shape* DessinShapes::select( const int & ind )
{
	if ( ind >= my_nbShapes )
		return NULL;
	else
	{
		return my_tabShapes[ind];
	}
}

void DessinShapes::setColour( char col, int ind )
{
	if ( select(ind) != NULL )
	{
		cinColour(col);
		select(ind)->setColour(col);
	}
}

void DessinShapes::move( int dx, int dy, int ind)
{
	if ( select(ind) != NULL )
	{
		cinPoint(dx,dy);
		select(ind)->move(dx, dy);
	}
}

void DessinShapes::erase(int ind)
{
	if ( select(ind) != NULL )
	{
		my_tabShapes[ind] = NULL;
		for ( int i=0; i<my_nbShapes-1; i++ )
			my_tabShapes[i] = my_tabShapes[i+1];
		my_nbShapes--;
	}
}

