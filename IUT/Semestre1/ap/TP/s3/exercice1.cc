#include<iostream>
#include<string>
using namespace std;

string paire(int n) {
  if (n%2==0)
    return "paire";
 else 
   return "impaire"; }

int main() {
  int n;
  cout << "entrez un entier : " << endl;
  cin >> n;
  cout << "votre nombre est " << paire(n) << endl;
  return 0; }

