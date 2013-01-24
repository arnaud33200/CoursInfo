#include <iostream>
#include <cstdlib>

#include "rationnel.h"
#include "outil.h"

using namespace std;

int main()
{
	Rationnel p1(4,2);
	Rationnel p2(6,8);
	Rationnel rr;
	p1.affiche();
	p2.affiche();
	p1.multiplication(p2,rr);
	rr.affiche();
	rr.reducteur();
	rr.affiche();

	return 0;
}
