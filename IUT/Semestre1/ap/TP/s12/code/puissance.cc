#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/************************************** exercice 1 *******/
int 
puissance (int a, int n)
{
	if ( n == 0 )
		return 1;
	else
		return a * puissance(a, n-1);
}

int 
puissance2 ( int a, int n )
{
	if (n==0)
		return 1;
	else if (n%2==0)
		return puissance2(a,n/2) * puissance2(a,n/2);
	else
		return a * puissance2(a,(n-1)/2) * puissance2(a,(n-1)/2);
}

/************************************ exercice 2 *********/
int 
fibonacci ( int n )
{
	if ( n == 1 || n == 2 )
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

/************************************ exercice 3 *********/
int 
ackerman ( int a, int n )
{
	if ( a == 0 )
		return n+1;
	else if ( n == 0 )
		return ackerman(a-1, 1);
	else
		return ackerman(a-1, ackerman(a,n-1));
}


/************************************ exercice 4 *********/
int 
horner (int x, int n)
{
	int a[n];
	a[n]=2;
	if ( n == 0)
		return a[0];
	else
		return (x+a)*(horner(x,n-1));
}

/*********************************************************/
/*********************************************************/
int main(int argc, char *argv[])
{
int a, n;

if ( argc != 3)
{
	cout << "il faut 2 arguments" << endl;
	return 1;
}
	
a = atoi(argv[1]);
n = atoi(argv[2]);
cout << "puissance simple a^n = " << puissance(a, n) << endl;	
cout << "puissance special a^n = " << puissance2(a,n) << endl;
cout << n << "° terme fibonacci = " << fibonacci(n) << endl;
cout << "ackerman de a et n = " << ackerman(a,n) << endl;
cout << "horner de a degre n = " << horner (a,n) << endl;

	
	return 0;
}
