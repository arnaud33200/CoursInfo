#include<iostream>
using namespace std;

void temperature() {
  int n, cpt;
  float max, min, somme, tmp;
  max=0;
  min=0;
  somme=0;
  cpt=0;
  cout << "nb de temperatures ? "; cin >> n;
  for (int i=1; i<n+1; i++) {
    cout << "entre la " << i << "� temp�rature" << endl;
    cin >> tmp;
    somme=somme+tmp;
    cpt++;
    if (tmp<min)
      min=tmp;
    if (tmp>max)
      max=tmp; }
  cout << endl << endl << "--------------------" << endl << "--------------------" << endl << endl;
  cout << "temp�rature MAX : " << max << endl << endl;
  cout << "temp�rature MIN : " << min << endl << endl;
  cout << "moyenne de temp�rature : " << somme/cpt << endl << endl; }

int main() {
  temperature();
  return 0;}
