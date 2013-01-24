#include<iostream>
#include<cstdlib>

using namespace std;

#include "verif.hh"
#include "const.hh"

bool 
verifcase( int tab[][nbcase], int i, int j)
{
	bool good=0;
	if ( tab[i][j] == 0 )
		good=1;
	else
		cout << endl
		<< "case deja occupé" << endl 
		<< "reécrivez les coordonnées : " << endl;
	return good;
}

bool 
verifcolone (int tab[][nbcase], int joueur )
{
	int i=0, j;
	bool good;
	while ( not good && i<nbcase )
	{
		good=1;
		j=0;
		while ( good && j<nbcase )
		{
			if ( tab[j][i] != joueur )
				good=0;
			j++;
		}
		i++;
	}
	if ( good == 1 )
	cout << endl << "le joueur " << joueur << " gagne la partie" << endl;
	return good;
}
				
bool 
verifligne (int tab[][nbcase], int joueur )
{
	int i=0, j;
	bool good;
	while ( not good && i<nbcase )
	{
		good=1;
		j=0;
		while ( good && j<nbcase )
		{
			if ( tab[i][j] != joueur )
				good=0;
			j++;
		}
		i++;
	}
	if ( good == 1 )
		cout << endl << "le joueur " << joueur << " gagne la partie" << endl;
	return good;
}	

bool 
verifdiago (int tab[][nbcase], int joueur )
{
	int i=0;
	bool g=1;
	bool h=1;
	while ( i<nbcase && ( g || h ) )
	{
		if ( tab[i][i] != joueur & g )
			g=0;
		if ( tab[nbcase-1-i][i] != joueur & h )
			h=0;
		i++;
	}
	if ( g || h )
	cout << endl << "le joueur " << joueur << " gagne la partie" << endl;
	return ( g || h );
}
	
	
