#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main( int argc, char* argv[] )
{
	printf("LANCE DUN JOUEUR\n~~~~~~~~~~~~~~~~~~~~~~\n\n");
	int numjoueur;			// numero du joueur

	int num_memoire;		// identifiant pour la mémoire partager
	int * share_mem;		// mémoire partager	
	int * num_proc;			// le numéro de joueur autorisé à enregistrer dans la variable
	int * val_share;		// variable partager qui contiendra la combinaison choisite			

	if ( argc != 3 )
	{
		printf("besoin de 2 arguments pour le fils : num_processeur_autorisé et variable_partagé");
		exit(1);
	}

	sscanf(argv[1],"%d", &num_memoire);
	sscanf(argv[2],"%d", &numjoueur);

	share_mem = shmat( num_memoire, 0, 0);
	if( (int)share_mem == -1 )
	{
		printf("erreur dans l'alocation mémoire paratager dans le programme joueur\n");
		exit(1);
	}

	num_proc = share_mem;
	val_share = share_mem + sizeof(int);

	while( *num_proc != numjoueur );		/

	srand(time(NULL)+getpid());
	int alea = (int)(4.0 * rand() / RAND_MAX)+1;	// valeur aléatoire entre 1 et 4
	*val_share = alea;
	*num_proc = -1;

	return 0;
}
