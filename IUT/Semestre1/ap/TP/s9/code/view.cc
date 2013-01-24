#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

#include "view.hh"
#include "const.hh"

void 
affichergrille( int tab[][nbcase] )
{
	cout << endl;
	cout << "    0   1   2    " << endl; 
	cout << "  ----+---+----  " << endl;
	for (int i=0; i<nbcase; i++)
	{
		cout << i << " |";
		for (int j=0; j<nbcase; j++)
		{
			cout << " ";
			switch (tab[i][j])
			{
				case 0: cout << " ";
				break;	
				case 1: cout << "X";
				break;
				case 2: cout << "O";
				break;
			}
			cout << " |";
		}
		cout << endl;
		cout << "  ----+---+----  " 
		<< endl ;
	}
	cout << endl;			
}

void 
initgrille( int tab[][nbcase])
{
	for (int i=0; i<nbcase; i++)
	{
		for (int j=0; j<nbcase; j++)
		{
			tab[i][j]=0;
		}
	}
}
			
