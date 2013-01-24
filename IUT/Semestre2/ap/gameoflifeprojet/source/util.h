#ifndef UTIL_H
#define UTIL_H

/**
 * \file util.h
 * \brief fonctions utiles
 * \author Mayira.Y	Arnaud.L
 * \date avril/mai 2011
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "enum.h"

using namespace std;
using namespace sf;


float aleafloat(float a, float b);

int aleaint(int a, int b);

int aleadirect( const int & a, const int & b );

bool aleabool(float pct);

state aleastate(float pct);

health aleahealth(float pct);

string toString( const int & e );

#endif
