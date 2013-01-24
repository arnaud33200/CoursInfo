#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int fd[2];
	pipe( fd );
	
	close(fd[0]);
	char c;
	int w = write(fd[1], &c, 1);
	printf("retour read = %d\n", w);
	//~ int cpt=0;
	//~ for( cpt=0; ;cpt++)
	//~ {
		//~ int w = write(fd[1], &cpt, 1);
		//~ printf( "taille : %d - %d\n",w, cpt);
	//~ }
	return 0;
}
