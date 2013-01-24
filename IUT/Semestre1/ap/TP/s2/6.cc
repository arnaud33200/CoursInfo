#include<iostream>
using namespace std;

int quatre() { return 4; }

float mquatretrois() { return -4.3; }

bool vrai() { return 1; }

char caract() { return '@'; }

bool reverse(bool r) { return not r; }

int division(int n) { return n/2; }

int main() {
  cout << quatre() << endl;
  cout << mquatretrois() << endl;
  cout << vrai() << endl;
  cout << caract() << endl;
  cout << reverse(1) << endl;
  cout << division(300) << endl; 
    return 0;
}

