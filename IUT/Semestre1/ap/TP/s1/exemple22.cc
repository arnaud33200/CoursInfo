#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  int taille=5;
  for (int i=0; i<taille; i++)
    cout << i;
  cout << endl;
 
  for (int i=-1; i<taille-1; i++)
    cout << i;
  cout << endl;

  int i=0;
  while (i<taille) {
    cout << i;
    i++; }
  cout << endl;

  i=0;
  do {
    cout << i;
    i++; }
  while (i<taille);

  cout << endl;
 

  return 0; }
