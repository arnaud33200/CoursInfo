#include <iostream>

#include "mylib.h"

using namespace std;

int main()
{
  cout << "n\tn^2\tn^3" << endl;
  cout << "----\t----\t----" << endl;

  for (int i=1; i<=5; i++) {
    cout << i << "\t"
	 << carre(i) << "\t"
	 << cube(i) << "\t"
	 << endl;
  }
}
