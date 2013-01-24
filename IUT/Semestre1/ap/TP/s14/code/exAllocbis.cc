#include<iostream>
#include<cstdlib>
using namespace std;

void puissance4( int e, int & s ) {
  int t;
  cout << "Adresse e : " << &e << endl;
  cout << "Adresse s : " << &s << endl;
  cout << "Adresse t : " << &t << endl;
  t = e * e;
  s = t * t;
}

int* randomvar()
{
	int* p=new int;
	*p=2.5;
	return p;
}

int* pointtab(int n)
{
	int* t=new int[n];
	return t;
}

int main() {
  //~ int i = 10;
  //~ int j;
  //~ cout << "Adresse i : " << &i << endl;
  //~ cout << "Adresse j : " << &j << endl;
  //~ puissance4( i, j );
  //~ cout << "puissance 4 de " << i << " : " << j << endl;
	int *d;
	d=pointtab(5);
	delete []d;
		for (int i=0; i<5; i++)
	{	
		d[i]=i;
		cout << d[i] << " - ";
	}
	cout << endl;

  return EXIT_SUCCESS;
}
