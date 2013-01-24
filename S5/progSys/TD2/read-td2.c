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
	fd = open(path, O_RDONLY);
	int val = atoi(argv[3]);
	erreursi( fd == -1, argv[1] );
	
	int offset = atoi( argv[2] ) * sizeof(val);		//strtoul()
	int cursor = lseek(fd, offset, SEEK_SET);
	erreursi( cursor != offset, argv[1] );
	
	int r = read( fd, &val, sizeof(val) );
	erreursi( r == -1, argv[1] );
	
	printf("%d\n", ntohl(val));
	
	close(fd);
	return EXIT_SUCCESS;
}
