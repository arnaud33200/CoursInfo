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
		dup2(fdpipe[0], 0);
		close(fdpipe[0]);
		close(fdpipe[1]);
		execlp("tee", "tee", argv[1], NULL);
		perror("tee");
		exit(1);
	}
	
	return 0;
}
