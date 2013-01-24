#include<iostream>
#include<string>
using namespace std;

void change(int &a, int &b) {
  a=a+b;
  b=a-b;
  a=a-b; }

int main() {
  int a, b;
  cout << "entrez la valeur de A : "; cin >> a;
  cout << "entrez lb valeur de B : "; cin >> b;
  cout << endl << endl;
  cout << "avant :" << endl << "A = " << a << endl << "B = " << b << endl;
  cout << endl << endl;
  change (a,b);
 cout << "apres :" << endl << "A = " << a << endl << "B = " << b << endl; 
 cout << endl << endl;

return 0; }

