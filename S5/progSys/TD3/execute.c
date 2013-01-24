#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	pid_t p;
	if( (p = fork()) == 0 )
	{
		execvp(argv[1], &argv[1]);	// ou argv + 1
		perror(argv[1]);
		exit(1);
	}
	else
	{
		// Function not afect by wait statue of another child process
		int st;
		waitpid(p, &st,0);
		if ( WIFEXITED(st) )
			return WEXITSTATUS(st);
		return -1;
	}
}
