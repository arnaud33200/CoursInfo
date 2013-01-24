#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void erreursi( int test, char * s )
{
	if ( test )
	{
		perror(s);
		exit(1);	
	}
}

int main( int argc, char* argv[])
{
	FILE * mfile;
	mfile = fopen(argv[1], "r");
	long t = ftell(mfile);
	char * buffer = (char*) malloc(sizeof(char)*t);
	
	int r = fread(buffer,1,t,mfile);
	
	int w = fwrite(buffer,1,sizeof(buffer),stdout);
	
	fclose(mfile);
	free(buffer);

	return EXIT_SUCCESS;
}
