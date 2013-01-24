#include<iostream>
#include<cstdlib>

using namespace std;


int** compresseur ( int f[], int n)
{
        int** tab=new int*[n];
	for (int i=0; i<n; i++)
	{
		if ( i>0)
		for (int s=i-1; s>=0; s--)
		  {
			if ( f[s] == f[i] )
			  {
				tab[i]=tab[s];
				cout << "deja vu" << endl;
			  }
		  }
		if ( tab[i] == NULL )
		{
			tab[i]=new int;
			*tab[i]=f[i];
			cout << "new alocation" << endl;
		}			
	}
	return tab;
}

void afficher (int** tab, int n)
{
	for ( int i=0; i<n; i++ )
	  {
	    cout << *tab[i] << " - ";
	    cout << tab[i] << endl;
	  }
}

void erasepoint ( int** tab, int n )
{
  for ( int i=0; i<n; i++ )
    {
      delete tab[i];
    }
  delete[] tab;
}

int main()
{
	int n=5;
	int file[]={1,4,1,2,4};
	int **tab=compresseur(file,n);
	afficher(tab,n);
	erasepoint(tab,n);
	afficher(tab,n);
	return 0;
}
