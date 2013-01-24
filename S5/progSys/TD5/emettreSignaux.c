#define _XOPEN_SOURCE 700
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int main( int argc, char* argv[])
{
	int i, j;
	
	for (i=0; i<atoi(argv[2]); i++)
	{
		for(j=3; j<argc; j++)
		{
			kill(atoi(argv[1]), atoi(argv[j]));
			volatile int x;
			for ( x=0; x<100000; x++);
		}
	}
	
	return 0;
}
