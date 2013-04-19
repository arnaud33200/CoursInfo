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

void random_permutation(int * tab, int start, int n){
  int i;
  for(i = 0 ; i < n ; i++)
    tab[i] = start+i;
  for(i = 0 ; i < n ; i++) {
    int j = rand() % (n-i) + i;
    swap(tab,i,j);
  }
}

#define N 12
int main (int argc, char* argv[]) 
{
  printf("Test de splay_union\n");
  int i;
  splay A = prof_splay_create(f);
  splay B = prof_splay_create(f);
  int * objsA = malloc(N*sizeof(*objsA));
  int * objsB = malloc(N*sizeof(*objsB));

  random_permutation(objsA, 1, N);
  random_permutation(objsB, N+10, N);


  for(i = 0 ; i < N ; i++)
    prof_splay_insert(A, &objsA[i]);
  splay_dump(A);
  printf("****************************************\n");
  for(i = 0 ; i < N ; i++)
    prof_splay_insert(B, &objsB[i]);
  splay_dump(B);
  printf("**********************************************************************************\n");

  splay C=splay_union(A, B);
  splay_dump(C);

  if(C == NULL){
    prof_splay_destroy(A);
    prof_splay_destroy(B);
  }
  else
    prof_splay_destroy(C);

  free(objsA);
  free(objsB);

  return 0;  
}
