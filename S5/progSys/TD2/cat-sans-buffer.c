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
	int fd = open(argv[1], O_RDONLY);
	erreursi( fd == -1, argv[1] );
	
	char c;
	int r;
	do
	{
		r = read(fd, &c, 1);
		erreursi( r == -1, argv[1] );
		
		int w = write(2, &c, 1);
		erreursi( w == -1, "standard output");
	}
	while( r > 0 );

	return EXIT_SUCCESS;
}
