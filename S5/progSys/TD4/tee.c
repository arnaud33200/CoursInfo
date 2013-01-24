#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char* argv[])
{	
	FILE *logfile = fopen( argv[1], "w");
		
	char a;
	while ( (fread(&a,1,1, stdin)) == 1 )
	{
		fwrite( &a, 1, 1, stdout);
		fwrite(&a, 1, 1, logfile);
	}
	
	return 0;
}
