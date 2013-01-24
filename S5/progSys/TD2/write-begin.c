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
	char* path = argv[1];
	int fd;
	fd = open(path, O_WRONLY | O_CREAT, 0666);
	int val = atoi(argv[2]);
	//~ int val = htonl(argv[2]);
	erreursi( fd == -1, argv[1] );
	
	int offset = 0;		//strtoul()
	int cursor = lseek(fd, offset, SEEK_SET);
	erreursi( cursor != offset, argv[1] );
	
	int w = write( fd, &val, 1 );
	erreursi( w == -1, argv[1] );
	
	close(fd);
	return EXIT_SUCCESS;
}
