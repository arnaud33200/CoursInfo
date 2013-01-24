#include<iostream>
using namespace std;

void dessineNcaract(int n, char val) {
  for (int i=0; i<n; i++)
    cout << val;
  cout << endl; }



int main() {
  int n;
  char val;  
cout << "combien d'étoile ? "; cin >> n;
cout << "quel caractére ? "; cin >> val;

 dessineNcaract(n, val);
 return 0;
}
