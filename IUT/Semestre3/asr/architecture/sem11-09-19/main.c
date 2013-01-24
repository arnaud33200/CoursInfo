#include "stdio.h"
#include "stdlib.h"

int somme(int *t, int l)
{
	int s=t[0];
	int i=0;
	for(;i<l;i++)
	{
		if ( s < t[i] )
			s = t[i];
	}
	return s;
}

int main( int argc, char * argv[] )
{
	int t[5];
	int resultat = somme(t,5);
	
	return resultat;
}
