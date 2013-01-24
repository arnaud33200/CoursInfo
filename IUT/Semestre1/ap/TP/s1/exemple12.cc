#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int tab1[5];
  char tab2[10];
  tab1[0]=9, tab1[4]=2;
  tab2[0]='c', tab2[9]='q';
  cout << "table entier : " << tab1[0] << " " << tab1[4] << endl;
  cout << "table caracteres : " << tab2[0] << " " << tab2[9] << endl;

  return 0;
}
