#define _XOPEN_SOURCE 700
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void whoiam(int s)
{
	printf("vous avez reçut le signal %s\n", strsignal(s) );
}

int main()
{
	int i;
	struct sigaction a;
	a.sa_handler = whoiam;
	a.sa_flags = 0;
	sigemptyset( &a.sa_mask);
	
	printf("mon pid : %d\n", getpid());
	
	for (i=1; i<32; i++)
	{
		if ( sigaction(i, &a, NULL) == -1 )
		{
			printf("%d\n", i);
			perror("");
		}
	}
	
	while(1) pause();
	
	return 0;
}
