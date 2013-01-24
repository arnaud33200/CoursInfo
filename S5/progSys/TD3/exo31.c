#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int f;
	if ( (f = fork()) != 0 )
	{
		printf( "je m'appel %d et je suis le père de %d\n", getpid(), f );
	}
	else
	{
		getchar();
		printf( "je m'appel %d et je suis le fils de %d\n", getpid(), getppid() );
	}
		
	return 0;
}
