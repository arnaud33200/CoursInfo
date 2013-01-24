#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX=200;
typedef string TtabChaine[MAX];
typedef string occurence[2][MAX];

/********************************************************************/

void saisirtableau( TtabChaine &tab, int &taille)
{
	for (int i=0; i<taille; i++)
	{
		cin>> tab[i];
	}
}

void afficher( occurence tab, int taille)
{
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<taille; j++)		
			cout << tab[i][j] << " | ";
		cout << endl;
	}
}

int find (occurence tab, int taille, string mot)
{
	int i=0;
	bool bon;
	while ( i<taille && !bon )
	{
		if ( tab[0][i]==mot )
			return i;
		i++;
	}
	return -1;	
}

void init(TtabChaine tab, occurence &sav, int n, int &taille)
{
	int f;
	stringstream s;
	int nb;
	string a;
	sav[0][0]=tab[0];
	sav[1][0]="1";
	for (int i=1; i<n; i++)
	{
		f=find(sav, taille, tab[i]);
		if ( f == -1 )
		{
			taille++;
			sav[0][taille-1]=tab[i];
			sav[1][taille-1]="1";
		}
		else
		{
			nb=0;
			nb = atoi(sav[1][f].c_str()); 
			nb++;
			s << 0;
			a=s.str();
			cout << a << endl;
		}
	}
}
/****************************************************************/

int main ( int argc, char* argv[] )
{	
	int taille;
	int taillo=1;
	cin >> taille;
	TtabChaine tabmot;
	occurence tabo;
	
	if ( taille > MAX )
	{
		cout << "trop de mot a integrer" << endl;
		cout << "MAX = " << MAX << endl;
		exit(-1);
	}

saisirtableau(tabmot, taille);
init(tabmot, tabo, taille, taillo);
afficher(tabo, taillo);
	
	return 0;
}
