#include<iostream>
#include<cstdlib>
#include "sort.h"
using namespace std;

int alea(int n)
{
  return rand()%(n+1);
}

void echange(int t[], int i, int j)
{
  int tmp;
  tmp=t[i];
  t[i]=t[j];
  t[j]=tmp;
}

void genererPermutation(int t[], int n)
{
  for(int i=0 ; i<n ; i++)
    t[i]=i;
  for(int j=n-1 ; j>0 ; j--)
    echange(t, j, alea(j));
}

void saisirTableau(int t[], int n)
{
  for(int i=0 ; i<n ; i++)
    cin >> t[i];
}

void afficherTableau(int t[], int n)
{
  for(int i=0 ; i<n ; i++)
    cout << t[i] << " " ;
  cout << endl;
}

void pireSort(int t[], int n)
{
  for(int i=0 ; i<n ; i++)
    t[i]=n-i-1;
}

/* *************************************************** */
/* ******************* Bubble Sort ******************* */
/* *************************************************** */

void bubbleSort(int t[], int n)
{
	int cpt=0;
	
	int i=0;
	bool good;
	do
	{
		good=1;
		for (int j=n-1; j>i; j-=1)
		{
			if ( t[j] < t[j-1] )
			{
			echange(t,j,j-1);
			cpt++;
			good=0;
			}
		}
		i++;
	}
	while ( i=n-1 && good!=1 );
	cout << endl << cpt << " echanges" << endl << endl;		
}

/* *************************************************** */


/* *************************************************** */
/* ******************* Select Sort ******************* */
/* *************************************************** */

void selectSort(int t[], int n)
{
	int cpt=0;
	
    int pospp;
    for (int i=0; i<n; i++)
    {
    	pospp=i;
    	for ( int j=i+1; j<n; j++ )
    	{
    		if ( t[pospp]>t[j] )
    		{
    			echange(t,pospp,j);
    			cpt++;
			}
		}
	}
	cout << endl << cpt << " echanges" << endl << endl;		
}
/* *************************************************** */


/* *************************************************** */
/* ******************* Insert Sort ******************* */
/* *************************************************** */

void insertSort(int t[], int n)
{
	int cpt=0;
	
   int elem, pos;
   bool good;
   for ( int i=1; i<n; i++)
   {
   	elem=t[i];
   	pos=i-1;
   	good=0;
   	while ( pos>=0 && good!=1 )
   	{
   		if ( t[pos] > elem )
   		{
   			t[pos+1]=t[pos];
   			cpt++;
   			pos-=1; 
		}
		else
			good=1;
	}
	t[pos+1]=elem;
	}
	cout << endl << cpt << " echanges" << endl << endl;	
}
/* *************************************************** */

/* *************************************************** */
/* ******************* tri par tas ******************* */
/* *************************************************** */


// On doit avoir i>0
int pere(int i)
{
  return (i-1)/2;
}

int droit(int i)
{
  return 2*i+2;
}

int gauche(int i)
{
  return 2*i+1;
}

bool existeFilsGauche(int n, int i)
{
  return gauche(i)<n;
}

bool existeFilsDroit(int n, int i)
{
  return droit(i)<n;
}

void entasser (int t[], int n, int i)
{
  int max;
  bool fin=false;

  while(existeFilsGauche(n,i) && !fin)
    {
      max = gauche(i);
      if(existeFilsDroit(n, i))
		if(t[max]<t[droit(i)])
	  		max = droit(i);
      
      if(t[max] < t[i])
	fin=true;
      else
	{
	  echange(t,i,max);
	  i=max;
	}
    }
}

void construireTas (int t[], int n)
{
  for(int i=n/2-1;i>=0;i--)
    entasser(t,n,i);
}

void heapSort(int t[], int n)
{
  construireTas(t,n);
  for(int i=n-1 ; i>0 ; i--)
    {
      echange(t,0,i);
      entasser(t,i,0);
    }
}
