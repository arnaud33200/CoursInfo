#include<iostream>
#include<string>
using namespace std;

void valpositif(int &n) { 
 while (n<=0) {
      cout << "entrez un entier positif : ";
      cin >> n;}
 }


int main() {
  int n, max;
  n=-1;
  max=0;
  while (n!=0) {
    cout << "entrez valeur : "; cin >> n;
    if (n>max)
      max=n; }
  cout << "fin" << endl << "valeur max = " << max << endl;

return 0; }

