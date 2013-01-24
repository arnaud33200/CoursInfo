#include<iostream>
#include<cstdlib>

using namespace std;

const int TAILLE=100;

int randomvar() 
{
	
	int a;  
 	a = rand()%(8-1)+1;


   	return a; 
}



int main()
{
  int tab[TAILLE];

  cout << "nombre au hazard" << endl << endl;

      srand(time(NULL));
  for ( int i=0; i<TAILLE; i++)
    {

      tab[i]=rand()%(8-1)+1;     
      cout << tab[i] << " ";
    }

  return 0;
}
