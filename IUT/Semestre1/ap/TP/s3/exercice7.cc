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
    cout << "entre la " << i << "° température" << endl;
    cin >> tmp;
    somme=somme+tmp;
    cpt++;
    if (tmp<min)
      min=tmp;
    if (tmp>max)
      max=tmp; }
  cout << endl << endl << "--------------------" << endl << "--------------------" << endl << endl;
  cout << "température MAX : " << max << endl << endl;
  cout << "température MIN : " << min << endl << endl;
  cout << "moyenne de température : " << somme/cpt << endl << endl; }

int main() {
  temperature();
  return 0;}
