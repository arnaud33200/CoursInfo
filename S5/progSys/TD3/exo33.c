#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int System( char *commande)
{
	pid_t p;
	if( (p = fork()) == 0 )
	{
		execl("/bin/bash", "bash", "-c", commande, NULL);
		perror(commande);
		exit(1);
	}
	else
	{
		// Function not afect by wait statue of another child process
		int st;
		waitpid(p, &st,0);
		if ( WIFEXITED(st) )
			return WEXITSTATUS(st);
		return ;
	}
}

int main(int argc, char* argv[])
{
	System("ps --forest");
	return 0;
}
