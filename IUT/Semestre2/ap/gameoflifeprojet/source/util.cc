/**
 * \file util.cc
 * \brief fonctions utiles
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <iostream>
#include <sstream>

#include "util.h"


using namespace std;
using namespace sf;


float aleafloat(float a, float b)
{ 
	return ( rand()/(float)RAND_MAX ) * (b-(a)) + a ;
}

int aleaint(int a, int b)
{ 
	return Randomizer::Random(a,b) ; 
}

int aleadirect( const int & a, const int & b )
{
	if ( Randomizer::Random(a,b) >= 0 )
		return b;
	else
		return a;
}


bool aleabool(float pct)
{
	if ( aleafloat(0,1) > pct )
		return true;
	else
		return false;
}

state aleastate(float pct)
{
	if ( aleabool(pct) )
		return alive;
	else
		return dead;
}

health aleahealth(float pct)
{
	if ( aleabool(pct) )
		return resist;
	else
		return normal;
}

string toString( const int & e )
{
	ostringstream s;
	s << e;
	return s.str();
}

