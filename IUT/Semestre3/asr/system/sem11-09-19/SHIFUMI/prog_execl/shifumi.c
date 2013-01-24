#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

int compare( int a, int b );


int main( int argc, char* argv[] )
{
	int nbjoueur;		// le nombre de joueur dans la partie
	int rfork;			// le retour de la fonction fork
	int pidfils;		// le pid du fils
	int reponse;		// la reponse envoyé par un fils	
	int i, j;			// variable pour faire un parcours de matrice

// traitement des arguments : definit le nombre de joueur
// biensure il faut au minimum deux joueurs
	if ( argc == 2 && argv[1] >= 2 )
		nbjoueur = atoi(argv[1]);
	else
		nbjoueur = 2;

// une matrice ou on enregistre le score
// score[i][0] : pid du joueur		
// score[i][1] : choix du joueur ( 1, 2, ou 4 )
// score[i][2] : score du joueur		
	int score[nbjoueur][3]; 

// creation des N joueurs	
	for (i=0; i<nbjoueur; i++) 		
	{	
		if( rfork = fork() == 0 )		// SI C'EST LE FILS
		{
			execl( "joueur", "joueur", 0);  // executer le programme "joueur"
		}
	}

 // on attend la reponse de tous les joueurs	
	for ( i=0; i<nbjoueur; i++) 
	{
		score[i][0]=wait(&reponse);		// on enregistre son pid
		score[i][1] = reponse/256;		// on enregistre son choix
		score[i][2] = 0;				// score initialisé a 0 pour tout le monde
	// on affiche l'action du joueur pour gardé une trace
		printf("le joueur de pid %d a choisi ", score[i][0]);		
		switch ( reponse/256 )
		{
			case 1 : { printf("PIERRE\n"); break; }
			case 2 : { printf("FEUILLE\n");	break; }
			case 3 : { printf("SCISEAU\n"); break; }
			case 4 : { printf("PUIT\n"); break; }
		}
		
// on peut comparé au moins deux joueurs
		if ( i+1 >= 2 ) 
	// on fait le calcule des points gagné par le arrivant dans la partie
	// et on calcule aussi les points des joueurs deja dans la partie
			for( j=0; j<i; j++ )
			{
				score[j][2] += compare( score[j][1], score[i][1] ); // les autres joueurs regardent les points gagné avec le nouveau joueur
				score[i][2] += compare( score[i][1], score[j][1] );	// le nouveau joueur regarde les points gagné avec l'ancien joueur
			}
	}
	
// affichage du résultat
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("  JOUER  - REPONSE - SCORE \n");
	printf("---------------------------\n");
	for( i=0; i<nbjoueur; i++ )
	{
		printf("  %d   |    %d    |    %d \n", score[i][0], score[i][1], score[i][2]);
		printf("---------|---------|-------\n");
	}

	return 0;
}

//~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int compare( int a, int b )
{
	if( a == 1 && b == 4 )		// pierre contre sciseau
		return 1;			
	else if( a == 2 && ( b == 1 || b == 4 )  )	// feuille contre caillou & puit
		return 1;	
	else if( a == 3 && b == 2 )	// sciseau contre feuille
		return 1;	
	else if( a == 4 && ( b == 1 || b == 3 ) )	// puit contre caillou et sciseau
		return 1;	
	else 
		return 0;
}
