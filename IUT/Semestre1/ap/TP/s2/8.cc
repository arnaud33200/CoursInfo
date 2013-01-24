#include<iostream>
#include<cstdlib>
using namespace std;

void maFonction(int e) {
  e=2;
  cout << e << endl; }

void changer(int first, int b) {
  int temp; temp=first;
  first=b;
  b=temp;
  cout << "Dedans : first vaut " << first << " et last vaut " << b << endl; }

int main() {
  int first=3; int last=5;
  cout << "avant : first vaut " << first << " et last vaut " << last << endl;
  changer(first, last);
 cout << "apres : first vaut " << first << " et last vaut " << last << endl;

    return 0;
}

