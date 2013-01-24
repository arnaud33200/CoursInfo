#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int global_non_init;
int global_init = 1;
int global_non_init2;
int global_init2 =2;


void apres_main();

int
main(int argc, char **argv)
{

  int *pointeur;
  int local;

  char *chaine = "chaine";
   
  printf("\n");
  pointeur = (int *) malloc(sizeof(int));

  printf("\t (printf) %p, (main) %p et (apres main) %p\n", printf, 
	 main, apres_main);

  printf("\n\tvariables globales  intialisées\n");
  printf("\t %p et %p\n", &global_init, &global_init2);
  printf("\n\tvariable globales non initialisées\n");
  printf("\t %p et %p\n", &global_non_init, &global_non_init2);
  printf("\n\t %p (*pointeur) et %p (sbrk(0))\n", pointeur, sbrk(0));
  printf("\t %p (argc) et %p (argv) \n", &argc, &argv) ;
  printf("\t %p (local) et %p (pointeur) \n", &local, &pointeur) ;
   

  printf("\n\n\n Quel segment contient-il la chaîne d'adresse %p ?\n", chaine) ;

  // apres_main((char *)&global_init);

  printf("\n mon pid est %d, appuyer sur entrée\n", getpid()) ;

  getchar();

  return 0;
}

void 
apres_main(char *pt)
{
  for(;;pt--)
    *pt = 0;
}
