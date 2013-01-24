#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char* argv[])
{	
	int fdpipe[2];
	pipe(fdpipe);
	
	int p;
	if ( (p = fork()) == 0 )
	{
		close(fdpipe[0]);
		dup2(fdpipe[1], 1);
		close(fdpipe[1]);
		execvp(argv[2], argv+2);
		perror( argv[2]);
		exit(1);
	}
	else
	{
		close(fdpipe[1]);
		FILE *logfile = fopen( argv[1], "w");
		FILE *readt = fdopen( fdpipe[0], "r" );
		
		char a;
		while ( (fread(&a,1,1, readt)) == 1 )
		{
			fwrite( &a, 1, 1, stdout);
			fwrite(&a, 1, 1, logfile);
		}
	}
	
	return 0;
}
