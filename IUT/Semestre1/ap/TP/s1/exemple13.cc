#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int tab[3], tab2[1];
  tab2[0]=-4;
  tab[0]=4; tab[1]=-4; tab[2]=10;
  tab2[0]/=tab[0];
  tab[3]++;
  float tab1[1];
  tab1[0]=tab2[0]/tab[2];
  tab2[0]++;
  tab2[0]-=2;
  tab[1]*=2;
  tab[1]=3.5-tab[1];
  tab[1]=tab2[1];

  return 0;
}
