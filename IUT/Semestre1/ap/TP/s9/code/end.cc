#include <iostream>
#include <cstdlib>

using namespace std;

#include "end.hh"
#include "verif.hh"
#include "const.hh"

bool 
fini ( int tab[][nbcase] )
{
	bool end=1;
	int i=0, j;
	while ( end && i<nbcase )
	{
		j=0;
		while ( end && j<nbcase )
		{
			if ( tab[i][j] == 0 )
				end=0;
			j++;
		}
		i++;
	}
	if ( end == 1 )
	cout << endl
	<< "la partie est terminée" << endl << endl;
	return end;
}

bool 
gagne (int tab[][nbcase], int joueur )
{
	return ( verifcolone(tab, joueur) || verifligne(tab, joueur) || verifdiago(tab, joueur) );

}
		

