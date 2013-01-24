#include <argz.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char *commande_lire() ;
// lit une chaine sur stdin, alloue la memoire
 
char * nettoyer_ligne(char *ligne, bool *eperluette);
// supprime le & et \n - eperluette vaut vrai ssi ligne en contenait au moins 1

char ** creer_argv(char *cmd) ;
// crée un vecteur à la argv en tranformant la ligne

void execute_commande(char ** argv, bool *eperluette);
// execute la commande entré dans argv

int 
main()
{
  
  while (1)
    {      
      char *ligne ;
      bool eperluette ;  
 
     printf("> ");
      ligne = commande_lire();
      if (ligne == NULL)
	break; 
      nettoyer_ligne(ligne, &eperluette) ;
      char** argv = creer_argv(ligne);     
      
      //~ for(int i= 0; argv[i]; i++)
	//~ printf("|%s|\n",argv[i]);
	
	execute_commande(argv, &eperluette);
	
	int st;
	while ( waitpid(0, &st, WNOHANG) <= 0 )
	{
		// boucle pour récupérer les zombies
	}
	
  
      free(argv);
      free(ligne);
    }
  return EXIT_SUCCESS;
}

void execute_commande(char ** argv, bool *eperluette)
{
	pid_t p;
	if ( (p = fork()) == 0 )
	{
		execvp(argv[0], argv);	// ou argv + 1
		perror(argv[1]);
		exit(1);
	}
	else
	{
		if( ! *eperluette )
			waitpid(p,NULL,0); 		// utiliser l'option WNOHANG pour continue et etre avertie si un fils est récup
	}
}


char *commande_lire()
{
  if(feof(stdin))
    return NULL;

  int lg = 80 ;
  char *c = malloc(lg);
    
  while(fgets(c,lg,stdin) == NULL)
    {
      lg <<= 1;
      c = realloc(c,lg);
    }
  return c;
}

char *
nettoyer_ligne(char *ligne, bool *eperluette)
{
  char *position = strchr(ligne,'&');
  if ((*eperluette = (position != NULL)))
    *position = '\0';
  if( (position = strchr(ligne,'\n')) != NULL) 
    *position = '\0';
  return ligne;
}

char **
creer_argv(char *cmd)
{
  char **argv;
  static char *argz = NULL;
  int argc;
  size_t longueur;

  free(argz);    
  
  argz_create_sep (cmd, ' ', &argz, &longueur);
  argc = argz_count(argz, longueur); 
  argv = malloc((argc + 1) * sizeof (char *));
  argz_extract(argz, longueur, argv);

  return argv;
}

