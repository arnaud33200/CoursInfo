#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void erreursi( int test, char * s )
{
	if ( test )
	{
		perror(s);
		exit(1);	
	}
}

int main( int argc, char* argv[])
{
	int fd1 = open(argv[1], O_RDONLY);
	erreursi( fd1 == -1, argv[1] );
	int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
	erreursi( fd2 == -1, argv[2] );
	
	int fin = lseek(fd1, 0, SEEK_END);
	erreursi( fin == -1, argv[2]);
	lseek(fd1, 0, SEEK_SET);
	
	char c;
	int p;
	for ( p=fin-1; p > 0; p-- )
	{
		int l = lseek( fd2, p, SEEK_SET);
		erreursi( l == -1, argv[1] );
		
		int r = read( fd1, &c, 1);
		//erreursi( r != 1, argv[2] );
		
		int w = write( fd2, &c, 1);
		erreursi( w != 1, argv[1]); 
		
		l = lseek(fd2, 0, SEEK_SET);
	}
	
	close(fd1);
	close(fd2);
	return EXIT_SUCCESS;
}
