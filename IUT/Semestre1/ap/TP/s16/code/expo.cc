#include<iostream>
#include<cstdlib>

using namespace std;

int powa( int a, int b)
{
	if ( b == 0 )
		return 1;
	else
		return powa(a,b-1)*a;
}

int powb( int a, int b)
{
	if ( b == 0 )
		return 1;
	else if ( b%2 == 0 && b > 0 )
		return powb(a*a,b/2);
	else
		return powb(a*a,(b-1)/2)*a;
}


int main ()
{
	cout << powa(2,3) << endl;
	cout << powb(2,3) << endl;
	return 0;
}
