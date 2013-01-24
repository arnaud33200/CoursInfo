#include<iostream>
#include<string>
using namespace std;

void valpositif(int &n) { 
 while (n<=0) {
      cout << "entrez un entier positif : ";
      cin >> n;}
 }


int main() {
  int n, tmp;
  n=-1;
  tmp=-2;
  while (tmp<n) {
    tmp=n;
    valpositif(n); }
  cout << "davide" << endl;




return 0; }

