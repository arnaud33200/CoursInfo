#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>


int main( int argc, char* argv[] )
{
	srand(time(NULL)+getpid());
	return (int)(4.0 * rand() / RAND_MAX)+1;	// valeur aléatoire entre 1 et 4
}

