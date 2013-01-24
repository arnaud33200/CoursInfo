#include<iostream>
#include<cstdlib>
using namespace std;

const int TAILLE = 100;


typedef int TTabInt[TAILLE];

void saisirTableau(TTabInt tab, int taille)
{
  for( int i = 0 ; i < taille ; i++ )
    cin >> tab[i];

  for ( int i=0; i<taille; i++ )
    for ( int j=i+1; j<taille; j++ )
      if ( tab[i] > tab[j] )
	{
	  tab[i]=tab[i]+tab[j];
	  tab[j]=tab[i]-tab[j];
	  tab[i]=tab[i]-tab[j];
	}
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
fusionner (int tab1[], int taille1, int tab2[], int taille2, int tab12[])
{
  tab12[taille1+taille2];

  int petit=0;   //la taille du plus petit tableau


  int i=0;  // indice tab12
  int j=0;  // indice tab1
  int k=0;  // indice tab2

  while ( i<(taille1+taille2) )
    {

      if ( tab1[j] < tab2[k] )
	{
	  tab12[i]=tab1[j];
	  i++; j++;
	}

      if ( tab2[k] < tab1[j] )
	{
	  tab12[i]=tab2[k];
	  i++; k++;
	}

      /*   if ( tab2[k] == tab1[j] )
	{
	tab12[i]=tab2[k];
	i++; k++;
	tab12[i]=tab1[j];
	i++; j++;
	}
      */
 
    }
}


int main()
{
  TTabInt tab1;
  TTabInt tab2;
  TTabInt tab12;

  int taille1 = 25;
  int taille2 = 6;
 
  saisirTableau(tab1, taille1);
  saisirTableau(tab2, taille2);
  afficherTableau(tab1, taille1);
  cout << endl;
  afficherTableau(tab2, taille2);
  cout << endl;

  // fait une fusion differente en fonction de la taille1 et taille 2


  return EXIT_SUCCESS;
}


