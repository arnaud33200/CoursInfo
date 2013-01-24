#include<iostream>
using namespace std;

void premierdegre(float a, float b, float c) {
  float d;
  cout << "ensembe de solution pour : a.x²+b.x+c=0 est : " << endl << endl;
  cout << "determination du discriminant : D = ";
    d=b*b-4*a*c;
    cout << d << endl;
      if (d>0) {
	cout << "d>0 donc deux solutions :" << endl:
	  cout << "x1 = " << (-b-d^0.5)/2*a << endl;
	cout << "x1 = " << (b-d^0.5)/2a << endl; }
      else if (d==0) {
	cout << "d=0 donc une solution :" << endl;
	cout << "x= " << -b/2*a << endl;}
	else
	  cout << "aucune solution" << endl; }

int main() {
  float a, b, c;
 cout << "soit la fonction a.x²+b.x+c avec : " << endl;
 cout << "- a= "; cin >> a;
 cout << "- b= "; cin >> b;
 cout << "- c= "; cin >> c;
 cout << endl << endl;
 premierdegre(a,b,c);
 return 0; }
