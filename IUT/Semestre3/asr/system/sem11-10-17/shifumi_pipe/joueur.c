#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
	srand(time(NULL)+getpid());
	int alea = (int)(4.0 * rand() / RAND_MAX)+1;	// valeur aléatoire entre 1 et 4
	write(1,&alea,1);		// ecrit sur la sortie standard, qui est redirigé vers le pipe
	return 0;
}
