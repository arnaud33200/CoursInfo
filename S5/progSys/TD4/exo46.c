#define _XOPEN_SOURCE 600
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int nombresuivant( double * d )
{
	int r = read(0, d, sizeof(*d));
	return (r==0)?-1:0;
}

int main( int argc, char* argv[])
{	
	for ( i = 0; i < n-1; i++)
	{
		int tube[2];
		pipe(tube);
		if ((fork()) == 0 )
		{
			dup2(tube[1],1);
			close(tube[1]);
			close(tube[0]);
			travailler(i);
			exit(0);
		}
		
		dup2(tube[0],0);
		close(tube[1]);
		close(tube[0]);
		travailler(i);
	}
	return 0;
}

ecrire
{
	for (i=1; i<atoi(argv[1]); i++)
	{
		double v = i;
		write(0, &d, sizeof(d));
	}
}

lire
{
	double d;
	while ( (read(1, &d, sizeof(d))) > 0)
	{
		printf("%g ", d);
	}
}

exemple : ecrire 2 | ./a.out | lire 
