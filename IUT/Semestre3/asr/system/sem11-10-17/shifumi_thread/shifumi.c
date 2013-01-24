#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int **tableau_score = NULL;			// matrice pour contenir les scores
pthread_mutex_t ecriture_std;			// gerer la concurence quand joueur affiche leur choix

	// Fonctions 
int compare( int a, int b );
void afficherChoix( int c, int n );
void reallocTabScore( int tailleAvant, int tailleApres );


// fonction lancé par le fils thread
// fait le choix aléatoire
void *faireSonChoix( void *num )
{
	int n = (int)num;
	int choix = (int)(4.0 * rand() / RAND_MAX)+1;	// valeur aléatoire entre 1 et 4
	tableau_score[n][0] = choix;					// inscrit le resultat dans sa case
													// aucune concurence possible sur l'écriture
	
	// il y a une concurence sur l'écriture de l'entrée standard
	// un mutex pour eviter des defauts d'affichage
	pthread_mutex_lock(&ecriture_std);						
	afficherChoix(choix, n);
	pthread_mutex_unlock(&ecriture_std);
	return 0;
}

///##################################################################

int main( int argc, char* argv[] )
{
	int i, j;			// variable de parcours de tableau
	int nbjoueur;		// nombre de joueur dans la partie
	int nballoue;		// nombre de case à allouer pour la matrice
	srand(time(NULL));
	
///~~~~~~~~ prise en compte des arugments ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
// traitement des arguments : definit le nombre de joueur
// biensure il faut au minimum deux joueurs
	if ( argc == 2 && atoi(argv[1]) >= 2 )
		nbjoueur = atoi(argv[1]);
	else
		nbjoueur = 2; 	// initialise le nombre de joueur à 2 si non precisé

///~~~~~~~~ instanciation des variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	pthread_t joueur[nbjoueur];				// déclartion des joueurs threads
	pthread_mutex_init(&ecriture_std, NULL );	// initalisation du mutex ecriture_std
	
	nballoue = nbjoueur;
	tableau_score = malloc( nballoue * sizeof(int*) );
	for ( i=0; i<nballoue; i++ )
		tableau_score[i] = malloc( 2 * sizeof(int) );
		
///~~~~~~~~ creation des fils threads ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	int rt; 	// variable de retour lors de la creation des threads
	// creation des threads
	for ( i=0; i<nbjoueur; i++ )
	{
		rt = pthread_create(&joueur[i], NULL, faireSonChoix, (void *)i);
		if(rt)
		{
			fprintf(stderr, "\n\t\033[01;31mImpossible de créer le thread %d\n", i);
			fprintf(stderr, "\tle nombre de joueur est changé à %d\033[00m\n", i);
			
			reallocTabScore( nballoue, i );
			nbjoueur = i;
			nballoue = i;
		}
	}

///~~~~~~~~ processus père et comptage des scores ~~~~~~~~~~~~~~~~~~~~~	
	
	for ( i=0; i<nbjoueur; i++ )
	{
		pthread_join( joueur[i], NULL);			// attente du fils n° i
		tableau_score[i][1] = 0;				// score initialisé
		
		// on peut comparé au moins deux joueurs
		if ( i+1 >= 2 )
		{ 
	// on fait le calcule des points gagné par le arrivant dans la partie
	// et on calcule aussi les points des joueurs deja dans la partie
			for( j=0; j<i; j++ )
			{
				tableau_score[j][1] += compare( tableau_score[j][0], tableau_score[i][0] ); // les autres joueurs regardent les points gagné avec le nouveau joueur
				tableau_score[i][1] += compare( tableau_score[i][0], tableau_score[j][0] );	// le nouveau joueur regarde les points gagné avec l'ancien joueur
			}
		}		
	}
	
///~~~~~~~~ affichage des scores finaux ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	// affichage du résultat
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("    JOUER    -   REPONSE   -  SCORE \n");
	printf("-----------------------------------\n");
	for( i=0; i<nbjoueur; i++ )
	{
		printf("    %-6d   |     %-4d    |    %-4d \n", i+1, tableau_score[i][0], tableau_score[i][1]);
		printf("-------------|-------------|---------\n");
	}
	
///~~~~~~~~~ desalocation des variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	pthread_mutex_destroy(&ecriture_std);
	
	for ( i=0; i<nballoue; i++ )
		free(tableau_score[i]);
	free(tableau_score);
	
	return 0;
}

///##################################################################

int compare( int a, int b )
{
	if( a == 1 && b == 4 )						// pierre contre sciseau
		return 1;			
	else if( a == 2 && ( b == 1 || b == 4 )  )	// feuille contre caillou et puit
		return 1;	
	else if( a == 3 && b == 2 )					// sciseau contre feuille
		return 1;	
	else if( a == 4 && ( b == 1 || b == 3 ) )	// puit contre caillou et sciseau
		return 1;	
	else 
		return 0;
}

void afficherChoix( int c, int n )
{
	printf("le Joueur %d a choisi ", n);
	switch ( c )
		{
			case 1 : { printf("PIERRE\n"); break; }
			case 2 : { printf("FEUILLE\n"); break; }
			case 3 : { printf("SCISEAU\n"); break; }
			case 4 : { printf("PUIT\n"); break; }
		}
}

// reallocation de la mémoire du tableau_score en cas de changement
void reallocTabScore( int tailleAvant, int tailleApres )
{
	int i, j;
	
	int **newtab = malloc( tailleApres * sizeof(int) );
	for ( i=0; i< tailleApres; i++ )
		newtab[i] = malloc( 2 * sizeof(int) );
		
	for ( i=0; i<tailleApres; i++ )
		for ( j=0; j<2; j++ )
			if ( tableau_score != NULL )
				newtab[i][j] = tableau_score[i][j];
	
	for ( i=0; i<tailleAvant; i++ )
		free(tableau_score[i]);
	free(tableau_score);
	
	tableau_score = newtab;
	printf("Le tableau des scores a maintenant une taille de %d sur 2\n", tailleApres);
}
