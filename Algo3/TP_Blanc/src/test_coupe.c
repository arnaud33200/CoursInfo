/* test_splay.c */

#include "splay.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int f(void * object) { return *((int*)object); }

void swap(int * tab, int i, int j) 
{
  int tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

void random_permutation(int * tab, int n){
  int i;
  for(i = 0 ; i < n ; i++)
    tab[i] = i+1;
  for(i = 0 ; i < n ; i++) {
    int j = rand() % (n-i) + i;
    swap(tab,i,j);
  }
}

#define N 12
int main (int argc, char* argv[]) 
{
  printf("Test de splay_coupe\n");
  int i;
  splay A = prof_splay_create(f);
  int * objs = malloc(N*sizeof(*objs));

  random_permutation(objs, N);

  for(i = 0 ; i < N ; i++)
    prof_splay_insert(A, &objs[i]);
  splay_dump(A);
  printf("****************************************\n");

  splay R=splay_coupe(A, N/2);
  splay_dump(A);
  printf("*****************\n");
  splay_dump(R);
  

  prof_splay_destroy(A);
  prof_splay_destroy(R);

  free(objs);

  return 0;  
}
