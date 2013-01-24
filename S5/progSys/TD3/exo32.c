#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int i;
	for (i = 0; i < atoi(argv[1]); i++)
	{
		if( fork() == 0 )
		{
			printf("je suis le fils num %d\n", i);
			exit(0);
		}
	}
	
	for (i = 0; i < atoi(argv[1]); i++)
	{
		wait(NULL);
	}

		
	return 0;
}
