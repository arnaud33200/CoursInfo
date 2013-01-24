#include<iostream>
#include<string>
using namespace std;

int quiminim(int x, int y, int z, int t) {
  int min;
  min=x;
  if (y<min)
    min=y;
  if (z<min)
    min=z;
  if (t<min)
    min=t;
  return min; }


int main() {
  int x, y, z, t;
  cout << "valeur de 'x' ? "; cin >> x;
  cout << "valeur de 'y' ? "; cin >> y;
  cout << "valeur de 'z' ? "; cin >> z;
  cout << "valeur de 't' ? "; cin >> t;
  cout << endl << endl;
  cout << "la valeur minimum est : " << quiminim(x,y,z,t) << endl;
 

return 0; }

