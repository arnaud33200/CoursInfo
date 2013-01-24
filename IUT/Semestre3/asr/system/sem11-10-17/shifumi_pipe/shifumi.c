#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int compare( int a, int b );

int sp[2];			// shifumi pipe
int nbjoueur;		// le nombre de joueur dans la partie
int rfork;			// le retour de la fonction fork
int pidfils;		// le pid du fils
int i, j;			// variable pour faire un parcours de matrice

int main( int argc, char* argv[] )
{
	
// traitement des arguments : definit le nombre de joueur
// biensure il faut au minimum deux joueurs
	if ( argc == 2 && atoi(argv[1]) >= 2 )
		nbjoueur = atoi(argv[1]);
	else
		nbjoueur = 2; 	// initialise le nombre de joueur à 2 si non precisé
	
// creation du pipe commun à tous les joueurs
	if ( pipe(sp) != 0 )
	{
		printf("Erreur d'ouverture du pipe sp\n");
		return 1;
	}		
		
// creation des N joueurs
	i = 0;
	while( i < nbjoueur && (rfork=fork()) > -1 ) 	// si il n'y a plus de processus possible	
	{	
		if( rfork == 0 )	// SI C'EST LE FILS
		{
	// on duplique l'ecriture du pipe sur la sortie standard
			close(1);		// fermeture de la sortie standard
			dup(sp[1]);		// duplique l'ecriture du pipe vers la sortie standard
			close(sp[1]);	// fermeture du pipe ecriture	
			close(sp[0]);	// fermeture du pipe lecture
			execl( "joueur", "joueur", 0);  // executer le programme "joueur"
		}
		
		i++;
	}
	
// une matrice ou on enregistre le score
// score[i][0] : pid du joueur		
// score[i][1] : choix du joueur ( 1, 2, 3, 4 )
// score[i][2] : score du joueur		
	int score[nbjoueur][2];
	int reponse;		// la reponse envoyé par un fils	
	
// on duplique la lecture du pipe sur l'entrée standard
	close(0);		// fermeture de l'entrée standard
	dup(sp[0]);		// duplique le pipe lecture vers l'entré standard
	close(sp[0]);	// fermeture du pipe lecture
	close(sp[1]);	// fermeture du pipe ecriture

 // on attend la reponse de tous les joueurs
 	i=0;
	while( i<nbjoueur && read(0,&reponse,1) > 0 )
	{
		score[i][0] = reponse;			// on enregistre son choix
		score[i][1] = 0;				// score initialisé a 0 pour tout le monde
		
	// on affiche l'action du joueur pour garder une trace
		printf("le joueur N° %d a choisi ", i+1);
		switch ( reponse )
		{
			case 1 : { printf("PIERRE\n"); break; }
			case 2 : { printf("FEUILLE\n"); break; }
			case 3 : { printf("SCISEAU\n"); break; }
			case 4 : { printf("PUIT\n"); break; }
		}
		
// on peut comparé au moins deux joueurs
		if ( i+1 >= 2 ) 
	// on fait le calcule des points gagné par le arrivant dans la partie
	// et on calcule aussi les points des joueurs deja dans la partie
			for( j=0; j<i; j++ )
			{
				score[j][1] += compare( score[j][0], score[i][0] ); // les autres joueurs regardent les points gagné avec le nouveau joueur
				score[i][1] += compare( score[i][0], score[j][0] );	// le nouveau joueur regarde les points gagné avec l'ancien joueur
			}
		i++;
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

	return 0;
}

/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ **/


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
