#include<iostream>
#include<cstdlib>
#include "sort.h"
using namespace std;

int main()
{
  const int MAX = 1000000;
  int t[MAX]; 
  int n=1000000;

  srand(time(NULL));
  
  saisirTableau(t,n);


	//~ cout << "tableau non trie : " << endl;
  //~ afficherTableau(t,n);
	//~ cout << endl << endl;
	
	//~ cout << "tableau trie par bulles" << endl;
	//~ bubbleSort(t,n);
	//~ afficherTableau(t,n);
	//~ cout << endl << endl;
	
	//~ cout << "tableau trie par insertion" << endl;
	//~ insertSort(t,n);
	//~ afficherTableau(t,n);
	//~ cout << endl << endl;
	
	//~ cout << "tableau trie par selection" << endl;
	//~ selectSort(t,n);
	//~ afficherTableau(t,n);
	//~ cout << endl << endl;
	
	heapSort(t,n);
	
	
	
  return EXIT_SUCCESS;
}
