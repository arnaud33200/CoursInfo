/* p_dek.c ; derni�re modif. le 24/11/99 */ 
/* Chacun des DEUX processus p_dek , lanc� par dekker incr�mente 
   une variable partag�e (ici, point�e par var_partagee)         */
 
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


/*------------------------------------------*/
main(int argc,char *argv[])
{
  int  *pt_mem;          	/* adresse memoire partagee        */
  int  *var_partagee;    	/* la variable partagee            */
  int  Mem_Number ;      	/* identificateur memoire partagee */
  int  process_number;   	/* numero processus courant        */
  int  *privilege_number; 	/* numero processus ayant le       */
							/* privilege                       */
  int  autre;            	/* numero autre processus          */
  int  i;                	/* pour la boucle                  */


  /* r�cup�ration des arguments */

  if (argc != 3) 
    {
      fprintf(stderr,"erreur utilisation de p_dek\n");
      exit(-1);
    } 
  sscanf(argv[1],"%d",&Mem_Number);       /* pour num�ro m�moire partag�e */
  sscanf(argv[2],"%d",&process_number);   /* pour num�ro processus courant*/

  printf("p_dek : Mem number :%d , processnumber :%d\n", Mem_Number,
	 process_number);

  /* acces m�moire partag�e (on attache la zone m�moire partag�e au */
  /*                           processus)                           */
  
  pt_mem = shmat( Mem_Number,0,0);
  if (((int)pt_mem) == -1 ) 
    {
      fprintf(stderr,"pb m�moire partag�e , shmat pour dekker num: %d\n",
	      process_number);
      exit(-2);
    }
  /* recuperation variable partag�es  */
  privilege_number = pt_mem;
  var_partagee     = pt_mem + sizeof(int) ;

  /* calcul de autre */
  
  if (process_number == 1) autre = 2;
  else if (process_number == 2) autre = 1;
  else  
    {
      fprintf(stderr,
	      "cet exemple ne peut s'utiliser que pour deux processus\n");
      exit(-3);
    }
	
/* boucle pour l'exemple */
  for (i=0;i<5;i++)
    {
		while (*privilege_number == autre);
		/* section critique */
		(*var_partagee)++;
		printf("je suis %2d, la variable vaut: %d\n",
		 process_number,*var_partagee);
		/* fin section critique */
		*privilege_number = autre;
    }
  /* on de-attache la memoire partagee */
  if (shmdt(pt_mem) == -1) 
    {
      fprintf(stderr,"pb shmdt pour dek numero %d\n",process_number); 
      exit(-4);
    }
  
  printf("fin processus dek num�ro : %d\n",process_number);
  exit(0);
}           



