#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main( int argc, char * argv[])
{
	int fd = open("fichierpipe", O_RDWR, O_CREAT, O_TRUNC, 0666);
	pid_t r;
	if ( (r = fork()) == 0 )
	{
		dup2(fd, 1);
		close(fd);
		execlp(argv[1], argv[1], NULL);
		perror(argv[1]);
		exit(1);		
	}
	else
	{
		int st;
		wait(&st);
		if ( !WIFEXITED(st) || WEXITSTATUS(st) != 0 )
			exit(1);
		
		lseek(fd, 0, SEEK_SET);
		dup2(fd, 0);
		close(fd);
		execvp(argv[2], &argv[2]);
		perror(argv[2]);
		exit(1);	
	}
	
	return 0;
}
