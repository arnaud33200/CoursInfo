#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  // && correspond a "and"
 
  bool a,b,c,d;
  a= true;
  b=false;
  c=a && b;
  cout << c << endl;
  c=a && a;
  cout << c << endl;
  d=c && a && b;
  cout << d << endl;





  return 0;
}
