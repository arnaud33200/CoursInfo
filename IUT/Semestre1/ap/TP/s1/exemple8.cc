#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{

  // pour l'utilisateur integre valeur : cin

  int note, notefinal;
  cout << "dit un entier entre 0 et 10" << endl;
  cin >> note;
  notefinal=note*2;
  cout << "ramenee sur 20 la note final : " << notefinal << endl;

 
  return 0;
}
