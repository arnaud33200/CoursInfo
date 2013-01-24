#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int tab[500];
  for (int i=0; i<501; i++){
    tab[i]=i*2;
    cout << "tab[" << i << "]= " << tab[i] << endl; }
  

  return 0;

 }
