#include <stdio.h>
#include <stdlib.h>


#define NB_PTR 10
void *tab_ptr[NB_PTR];


int main(){
  
  int size = -1;
  int i=0;

/*   malloc_stats(); */

  /* Initialisation : */
  for (i=0; i<NB_PTR; i++){
    tab_ptr[i] = NULL;
  }


  /*** Allocation : ***/
  for (i=0; i<NB_PTR; i++){

    printf("\nEntrez le nombre de ko a allouer (0 pour arreter l'allocation) : \n");
    scanf("%d", &size);

    if (size == 0)
      break;
    
    if ((tab_ptr[i] = (void *)malloc(size*1024)) == NULL){
      perror("Echec de l'allocation.\n");
    }
    else {
      printf("adresse obtenue : %p\n",tab_ptr[i]);
    }
    
/*     malloc_stats(); */
  }


  /*** Liberation : ***/
 
  for(;i>0;i--)
 {
    int j;
    for (j=0; j<NB_PTR; j++){
      printf("tab_ptr[%d] = %p \n", j, tab_ptr[j]);
    }
    
    printf("Quel bloc souhaitez-vous liberer ?");
    scanf("%d", &j);
    
    free(tab_ptr[j]);
    tab_ptr[j] = NULL;
/*     malloc_stats(); */
  } 
  
  return EXIT_SUCCESS;

}




