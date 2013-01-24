#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  int a=4, d=4;
  char b='a', c='4';

  if (a==d)
    cout << "a et d sont egaux" << endl;

  if (a<=d)
    cout << "a est plus petit ou egale a d" << endl;

 if (a==d)
    cout << "a et d sont egaux" << endl;

 else if (a<=d)
   cout << "a est plus petit ou egal a d" << endl;

 if (b==c)
   {  cout << "b vaut " << b << " et c vaut " << c << endl;
 cout << "donc b et c sont egaux" << endl;
   }
 else
   {
     cout << "b vaut " << b << " et c vaut " << c << endl;
     cout << "donc b et c sont differents" << endl;
     }


  return 0;
}
