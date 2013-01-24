#include<iostream>
#include<cstdlib>
using namespace std;

void FCT1(int a){
a=3;
cout << a ;}

void FCT2(int b) {
b=3;
cout << b ;}

int main ( ) {
int a=2;
FCT1(a);
cout << a;
FCT2(a);
cout << a;
return 0;
}

