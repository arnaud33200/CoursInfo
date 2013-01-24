#include<iostream>
#include<cstdlib>

using namespace std;

#include "saisir.hh"
#include "verif.hh"
#include "const.hh"

void 
saisirpos ( int tab[][nbcase], int &i, int &j )
{
	bool good=0;
	
	while ( not good )
	{
		i=-1;  // initialise a -1 
		j=-1;
		while ( i<0 || i>=nbcase || j<0 || j>=nbcase )
		{
			cout << endl;
			cout << "colone i = "; cin >> i;
			cout << " ligne j = "; cin >> j;
		}
		good = verifcase(tab, i, j);  // from verif.cc
	}

}

void 
poserM ( int tab[][nbcase], int i, int j, int joueur) 
{
	tab[i][j]=joueur;
}
