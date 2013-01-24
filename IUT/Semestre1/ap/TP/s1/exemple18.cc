#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
 cout << "boucle 0" << endl;
  for (int i=0; i<10; i=i+1){
    cout << "coucou" << endl;
  } cout << endl;

 cout << "boucle 1" << endl;
  for (int i=0; i<10; i=i+1)
    cout << "coucou" << endl;
 cout << endl;

 cout << "boucle 2" << endl;
  for (int i=0; i<10; i=i+1)
    cout << "coucou" << endl;
  cout << "bye" << endl;
 cout << endl;

 cout << "boucle 3" << endl;
 for (int i=0; i<10; i=i+1) {
    cout << "coucou" << endl;
    cout << "bye" << endl; }
 cout << endl;

 cout << "boucle 4" << endl;
  for (int i=-1; i<9; i=i+1)
    cout << i << endl;
 cout << endl;

 cout << "boucle 5" << endl;
  for (int i=0; i<9; i=i+2)
    cout << i << endl;
 cout << endl;

 cout << "boucle 6" << endl;
  for (int i=10; i>=0; i=i-1)
    cout << i << endl;
 cout << endl;

 cout << "boucle 7" << endl;
  for (int i=0; i<=9; i=i+1)
    cout << i << endl;
 cout << endl;


  return 0;

 }
