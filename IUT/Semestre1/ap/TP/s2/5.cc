#include<iostream>
using namespace std;

int max(int a, int b) {
  if (a>=b)
    return a;
  else
    return b; }

int main (void) {
  float a,b;
  cout << "a ? "; cin >> a;
 cout << "b ? "; cin >> b;

  int resultat;
  resultat=max(a,b);
  cout << resultat << endl;
  return 0; }

