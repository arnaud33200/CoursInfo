#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  int n=4, fact=1, e=1;
  while (fact<=n) {
    e++;
    fact*=e; }

  e--;
  cout << "le resultat est " << e << endl;
 

  return 0; }
