#include<iostream>
#include<string>
using namespace std;


int main() {
  int chiffre, somme, cpt;
  somme=0;
  cpt=0;
  do {
    cout << "dites un chiffre entre 0 et 10 : "; cin >> chiffre;
    somme=somme+chiffre;   
    cpt++; }
  while (chiffre!=0);
  cout << "somme des chiffres entres : " << somme << endl;
  cout << "moyenne des chiffres rentres : " << somme/cpt << endl;
 
  return 0; }

