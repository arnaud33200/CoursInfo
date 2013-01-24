#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int a,b;
  float c,d;
  char e,f;
  bool g;


  // a est il égale a b ? => g=0 donc faux
  // les parenthése améne donc a un test question qui sera inscrit dans g
  a=2;
  b=3;
  g=(a==b);
  cout << g << endl;

 
 // c plus petit que d ? => g=1 donc vrai
  c=-1.3;
  d=5.2;
  g=(c<=d);
  cout << g << endl;


  e='@';
  f='e';
  g=(e!=f);
  cout << g << endl;



 
  return 0;
}
