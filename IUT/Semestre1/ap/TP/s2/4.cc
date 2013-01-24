#include<iostream>
using namespace std;

void bonjour() {
  cout << "bonjour"; }

void alors(bool a) {
  if (a==1)
    cout << "vrai" << endl;
else  if (a==0)
    cout << "faux" << endl; }

void repete(int n) {
  for (int i=0; i<n; i++)
    bonjour(); }

void divise(int d) {
  cout << d/2 << endl; }


int main() {
  int n, d;
  bool a;

  cout << "repete combien de fois "; cin >> n; 
 repete(n);
 cout << endl << endl;
  cout << "0 ou 1 ? "; cin >> a;
  alors(a);
 cout << endl << endl;
  cout << "on divise quoi par 2 ? "; cin >> d;
  divise(d);
	 return 0;
	 }


