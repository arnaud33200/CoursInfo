#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main( int argc, char * argv[])
{
	int fd[2];
	pipe(fd);
	pid_t r;
	if ( (r = fork()) == 0 )
	{
		dup2(fd[1], 1);
		//~ close(fd[1]);
		//~ close(fd[0]);
		execlp(argv[1], argv[1], NULL);
		perror(argv[1]);
		exit(1);		
	}
	else
	{
		dup2(fd[0], 0);
		//~ close(fd[0]);
		close(fd[1]);
		execvp(argv[2], &argv[2]);
		perror(argv[2]);
		exit(1);	
	}
	
	return 0;
}
