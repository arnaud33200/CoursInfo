/* dekker.c ; dernière modif. le 24/11/99 */  
/* Implémentation de l'algorithme de Dekker V. 1
   Usage : dekker (qui lance ses deux fils p_dek)  */
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void Init_Process_Number();
void Init_Var_Partagee();

/*------------------------------------------*/
main()
{
     int  *pt_mem;          /* adresse memoire partagee        */
     int  *var_partage;     /* la variable partagee            */
     int  Mem_Number ;      /* identificateur memoire partagee */
     int  p1, p2, c;        /* variables pour wait             */
     int  *process_number;  /* numero processus ayant le       */
                            /* privilege                       */
     char  arg1[10];        /* pour exec arg1 : numero memoire */
     /*     char  arg2[10];              arg2 : num memoire    */


/* création memoire partagee */
     Mem_Number = shmget(IPC_PRIVATE,2*sizeof(int),600); 
     if ( Mem_Number == -1 ) {
           fprintf(stderr,"pb : pas de creation de memoire partagee \n");
           exit(-1);
     }

		/* acces memoire partagee (on attache la zone memoire partagee au */
     /*                           processus)                           */

     pt_mem = shmat( Mem_Number,0,0);
     if (((int)pt_mem) == -1 ) {
           fprintf(stderr,"pb memoire partagee , shmat \n");
           exit(-2);
     }

     /* les variables partagees  */
     process_number = pt_mem;
     var_partage    = pt_mem + sizeof(int) ;

     /* initialisation des variables partagees */
     Init_Process_Number (process_number);
     Init_Var_Partagee (var_partage);

     printf (" Dekker a ecrit dans la memoire partagee %d\n", Mem_Number);


     if ( fork() == 0 ) 
	 {
		/* lancement process_un ...  */
		sprintf(arg1,"%d",Mem_Number);
		execl("p_dek","p_dek1",arg1,"1",0);
		fprintf(stderr,"pb lancement dek1\n");
		exit(-3);
    }
    if ( fork() == 0 ) 
	{
               /* lancement process_deux ...  */
              sprintf(arg1,"%d",Mem_Number);
              execl("p_dek","p_dek2",arg1,"2",0);
              fprintf(stderr,"pb lancement dek2\n");
              exit(-4);
    } 
    /* on attend la fin des fils */
    
    p1 = wait(&c);
    p2 = wait(&c);
    printf("fin du test version algorithme dekker\n");


    /* on de-attache et on detruit la memoire partagee */
    if(shmdt(pt_mem) == -1){
        fprintf(stderr,"dekker segment indetachable\n");
        exit(-5);
    }
    if(shmctl(Mem_Number,IPC_RMID,0)==-1) {
        fprintf(stderr,"dekker segment indestructible\n");
        exit(-6);
    }      
        
    exit(0);
}
/*-------------------------------*/

void Init_Var_Partagee (int *v)
{
   *v = 0 ;  /* par exemple */
}   

/*-------------------------------*/

void Init_Process_Number (int *v)
{
   *v = 1 ;  /* processus num 1 a le privilege au debut  */
}   

/*-------------------------------*/

