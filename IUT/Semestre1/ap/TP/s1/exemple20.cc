#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int tab [100], cpt=0;
bool trouve=0;
 tab[14]=52; tab[35]=52;  
  while ((cpt<101) && (trouve==0 )) {
    if (tab[cpt]==52)
      { cout << "nombre 52 affiche!" << endl;
	trouve=1; }
    
    cpt=cpt+1;
  }
  cout << "fini" << endl;

  return 0;

 }
