#include<iostream>
#include<cstdlib>

#include "outil.h"

using namespace std;

void echange(int a, int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

int pgcdrationnel( int a, int b )
{
	int r=0, q=0;
	
	if ( a < b )
		echange(a,b);
	do
	{
		r = a % b;
		q = (a-r)/b;
		if ( r!=0 )
		{
			a = b;
			b = r;
		}
	}
	while ( r != 0 );
	return b;
}
	
