#include<iostream>
#include<cstdlib>

using namespace std;

const int MAX=30;
typedef bool damier[MAX][MAX];

void generedamier ( damier &tab )
{
	float proba;
	do
	{
	cout << "quel probabilité voulez vous ? ( > 0 & < 1 ) : ";
	cin >> proba;
	}
	while ( proba < 0 || proba > 1 );
	
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
			tab[i][j]=( (1.*rand()/RAND_MAX) < proba );
	}	
}

void afficherdamier ( damier tab )
{
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			if ( tab[i][j] == 1 )
				cout << "# ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

int nbvoisin ( damier tab, int a, int b )
{
	int cpt=0;
	for (int i=a-1; i<=a+1; i++)
	{
		for (int j=(b-1); j<=(b+1); j++)
		{	
			if ( i!=a || j!=b )
				if ( i >= 0 && i < MAX && j >= 0 && j < MAX )
					if ( tab[i][j] == 1 )
						cpt++;
		}
	}
	return cpt;
}
	
void liferules (  damier& tab )
{
	damier tab1;
	for (int i=0; i<MAX; i++)
		for (int j=0; j<MAX; j++)
		{
			if ( tab[i][j]==0 && nbvoisin(tab,i,j)==3 )
				tab1[i][j]=1;
			else if ( tab[i][j]==1 && ( nbvoisin(tab,i,j)==3 || ( nbvoisin(tab,i,j)==2 )) )
				tab1[i][j]=1;
			else 
				tab1[i][j]=0;
		}
	for (int i=0; i<MAX; i++)
		for (int j=0; j<MAX; j++)
			tab[i][j]=tab1[i][j];
}
		


int main ()
{
	int cpt=0;
	srand(time(NULL));
	system("clear");
	damier tab;
	generedamier(tab);
	while ( cpt < 100000 )
	{
		cpt++;
		cout << cpt << endl << endl;
		system("clear");
		afficherdamier(tab);
		liferules(tab);
		sleep(1);
	}
	cout << nbvoisin(tab,1,1) << endl;
	
	return 0;
}
