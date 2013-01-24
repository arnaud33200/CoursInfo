#include<iostream>
using namespace std;

void dessine5etoiles() {
  for (int i=0; i<5; i++)
    cout << "#";
  cout << endl; }

int main() {
  for (int i=0; i<5; i++)
    dessine5etoiles();
}
