#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int compare( int a, int b );

int nbjoueur;		// le nombre de joueur dans la partie
int rfork;			// le retour de la fonction fork
int pidfils;		// le pid du fils
int i, j;			// variable pour faire un parcours de matrice

int num_memoire;		// identifiant pour la mémoire partager

int * share_mem;		// mémoire partager
int * num_proc;			// le numéro de joueur autorisé à enregistrer dans la variable
int * val_share;

char arg1[];
char arg2[10];

int main( int argc, char* argv[] )
{

/// ~~~~~~~~~~~~~~~~~~~~ traitement des arguments : definit le nombre de joueur ~~~~~~~~~~~~~~~~~~

// il faut au minimum deux joueurs
	if ( argc == 2 && atoi(argv[1]) >= 2 )
		nbjoueur = atoi(argv[1]);
	else
		nbjoueur = 2; 	// initialise le nombre de joueur à 2 si non precisé


	num_memoire = shmget(IPC_PRIVATE,2*sizeof(int),0600);
	if ( num_memoire < 0 ) // erreur de creation mémoire partarger
	{
		printf("erreur de création mémoire partarger dans le programme s shifumi\n");
		exit(1);
	}

	share_mem = shmat(num_memoire,0,0);		// attache de la mem_partager au processeur
	if ( ((int)share_mem) == -1 )
	{
		printf("erreur d'atribution mémoire partarger dans le programme shifumi\n");
		exit(1);
	}

	num_proc = share_mem;
	val_share = share_mem + sizeof(int);

/// ~~~~~~~~~~ creation des N joueurs ~~~~~~~~~~~~~~~~~~


	for( i=1; i <= nbjoueur; i++ ) 	// si il n'y a plus de processus possible
	{
		if( fork() == 0 )	// SI C'EST LE FILS
		{
			sprintf(arg1,"%d",num_memoire);
			sprintf(arg2,"%d",i);
			execl( "joueur", "joueur", arg1, arg2, 0);  // executer le programme "joueur"
			exit(0);
		}
	}

// une matrice ou on enregistre le score
// score[i][0] : choix du joueur i ( 1, 2, 3, 4 )
// score[i][0] : score du joueur i
	int score[nbjoueur][2];
	int reponse;		// la reponse envoyé par un fils

// on attend la reponse de tous les joueurs
// c'est le père qui va choisir lequel des fils parle
// ici on fait dans l'ordre croissant des joueurs 
	for( i=1; i <= nbjoueur; i++)
	{
		*num_proc = i;					// le père autorise le joueur i à écrire dans la variable
		pidfils = wait(&reponse);
		while ( *num_proc != -1 );
		score[i-1][0] = *val_share;		// on enregistre son choix depuis la variable partagé
		score[i-1][1] = 0;				// score initialisé a 0 pour tout le monde

	// on affiche l'action du joueur pour garder une trace
		printf("le joueur N° %d a choisi ", i);
		switch ( *val_share )
		{
			case 1 : { printf("PIERRE\n"); break; }
			case 2 : { printf("FEUILLE\n"); break; }
			case 3 : { printf("SCISEAU\n"); break; }
			case 4 : { printf("PUIT\n"); break; }
			defaut : { printf("INCONNUE\n"); }
		}

// on peut comparé au moins deux joueurs
		if ( i >= 2 )
		{ 
			for( j=0; j<i-1; j++ )
			{
				score[j][1] += compare( score[j][0], score[i-1][0] ); // les autres joueurs regardent les points gagné avec le nouveau joueur
				score[i-1][1] += compare( score[i-1][0], score[j][0] );	// le nouveau joueur regarde les points gagné avec l'ancien joueur
			}
		}
	}

// affichage du résultat
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("  JOUER  - REPONSE - SCORE \n");
	printf("---------------------------\n");
	for( i=0; i<nbjoueur; i++ )
	{
		printf("  %d   |    %d    |    %d \n", i+1, score[i][0], score[i][1]);
		printf("-------|----------|-------\n");
	}
	

	return EXIT_SUCCESS;
}

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ **/


int compare( int a, int b )
{
	if( a == 1 && b == 4 )						// pierre contre sciseau
		return 1;			
	else if( a == 2 && ( b == 1 || b == 4 )  )	// feuille contre caillou & puit
		return 1;	
	else if( a == 3 && b == 2 )					// sciseau contre feuille
		return 1;	
	else if( a == 4 && ( b == 1 || b == 3 ) )	// puit contre caillou et sciseau
		return 1;	
	else 
		return 0;
}
