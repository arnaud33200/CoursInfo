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

#define N 6
int main (int argc, char* argv[]) 
{
  printf("Test de splay_destroy\n");
  int i;
  splay m = prof_splay_create(f);
  int * objs = malloc(N*sizeof(*objs));

  random_permutation(objs, N);

  for(i = 0 ; i < N ; i++) {
    prof_splay_insert(m, &objs[i]);
  }    
  splay_dump(m);

  splay_destroy(m);

  free(objs);

  return 0;  
}
