#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int tab[3], tab2[1];
  bool a;
  tab2[0]=-4
    tab[0]=4; tab[1]=-4; tab[2]=10;

  if (tab2[0]==tab[0])
    a=true;
else  if (tab2[0]==tab[1])
    a=true;
else  if (tab2[0]==tab[2])
    a=true;
 else
   a=false;

  if (a==false)
    cout << "nombre" << tab2[0] << "non trouve" << endl;
  else
    cout << "nombre" << tab2[0] << "trouve" << endl;

  return 0;
}
