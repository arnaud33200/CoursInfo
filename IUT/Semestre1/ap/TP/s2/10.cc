#include<iostream>
#include<cstdlib>
using namespace std;

void FCT1( int &a ) {
a=3;
 cout << a << endl; }

void FCT2( int &b ) {
b=5;
 cout << b << endl ; }


int main( ) {
int a=2;
FCT1( a ) ;
 cout << a << endl;
FCT2( a ) ;
 cout << a << endl;
return 0; }

