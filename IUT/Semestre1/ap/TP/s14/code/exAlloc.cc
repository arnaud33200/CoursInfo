#include<iostream>
#include<cstdlib>
using namespace std;
 
int fct2() {
  int m = 17;
  float t[ 4 ];
  cout << "Adresse m : " << &m << endl;
  cout << "Adresse t : " << t << " " << &t[ 0 ] << endl;
}
int fct3() {
  int n = 25;
  int p = 27;
  cout << "Adresse n : " << &n << endl;
  cout << "Adresse p : " << &p << endl;
}
int main() {
  int i = 10;
  cout << "Adresse i : " << &i << endl;
  fct2(); 
  fct3();
  return EXIT_SUCCESS;
}
