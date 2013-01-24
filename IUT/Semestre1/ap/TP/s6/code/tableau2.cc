#include<iostream>
#include<cstdlib>
using namespace std;

const int N = 5;
const int M = 5;
typedef int TTabInt[N];

void 
saisirTableau(TTabInt tab, int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++ )
    cin >> tab[i];
}


void 
afficherTableau(TTabInt tab, int taille)
{
  int i;

  for( i = 0 ; i < taille ; i++ )
    cout << tab[i] << " ";
  cout << endl;
}

void 
saisircroissant(TTabInt tab, int n)
{
  int i;
  cin >> tab[0];
  for ( i=1; i<n; i++)
    do
      {
	cin >> tab[i];
	if ( tab[i-1]>tab[i] )
	  cout << "entré une valeur plus grande que " << tab[i-1] << endl;
      }
    while (tab[i-1]>tab[i]);
}	   


    


int main()
{
  TTabInt tab1;
  TTabInt tab2;
  TTabInt tab12;

 
  //  saisirTableau(tabl, N);
  saisircroissant(tab1, N);
  afficherTableau(tab1, N);


  return EXIT_SUCCESS;
}


