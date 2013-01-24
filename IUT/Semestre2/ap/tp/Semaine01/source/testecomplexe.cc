#include<iostream>
#include<cstdlib>

#include "complexe.h"

using namespace std;

int main()
{
	Complexe c1(3,5);
	Complexe c2(2,1);
	Complexe rc;
	
	c1.afficher();
	c2.afficher();
	
	cout << endl;
	
	c1.multiplier(c2,rc);
	rc.afficher();
	
	return 0;
}
