#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

   bool a,b,c,d;
  a= true;
  b=false;
  c=a || b;
  cout << c << endl;
  c=b || a;
  cout << c << endl;
  c=b || b;
  cout << c << endl;
  return 0;
}
