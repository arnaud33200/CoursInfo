#include <iostream>

using namespace std;

void fct( int j )
{
  // Le 'i' defini ici n'a rien a voir avec le 'i'
  // de la fonction 'main', comme l'atteste l'execution.
  int i = j ;
  cout << "fct(1) : i = " << i << endl ;
  i = i * 2 ;
  cout << "fct(2) : i = " << i << endl ;
}

int main()
{
  int i ;
  cout << "main(1) : entrez un entier = " ;
  cin >> i  ;
  cout << "main(2) : i = " << i << endl ;
  fct ( i ) ;
  cout << "main(3) : i = " << i << endl ;
  return 0;
}
