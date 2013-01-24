#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "point.h"
#include "polygone.h"

int main()
{
	Polygone p;
	p.saisie();
	cout << p.toString() << endl;
	cout << endl << "perimetre = " << p.perimetre() << endl;

	
	return 0;
}
