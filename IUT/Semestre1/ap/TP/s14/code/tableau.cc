#include <iostream>
#include <cstdlib>

using namespace std;


int** saisir(int &n)
{
	int tmp;
	int** p = new int*[];
	cout << "quel taille pour le tableau ? ";
	cin >> n;
	for ( int i=0; i<n; i++ )
	{
		p[i] = new int;
		cout << "saisissez la " << i+1 << "° valeur : ";
		cin >> *p[i];
	}
}

void afficher(int** p, int n)
{
	for (int i=0; i<0; i++)
		cout << *p[i] << " - ";
	cout << endl;
}
		
		
void enfiler(int** &p, int &n)
{
	p[n]=new int;
	cout << "quel valeur ajouté en fin de tableau ? ";
	cin >> *p[n];
	n++;
}


void defiler(int** &p, int &n)
{
	for (int i=1; i<n; i++)
		*p[i-1]=*p[i];
	delete p[n-1];
	n--;
}

int premierfile(int** p)
{
	return *p[0];
}

int 
		
