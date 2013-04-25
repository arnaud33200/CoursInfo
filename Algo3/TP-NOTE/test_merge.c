/* test_splay.c */

#include "heap1.h"
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
  for(i = 0 ; i < n ; i++) {
    int j = rand() % (n-i) + i;
    swap(tab,i,j);
  }
}

#define N 6
int main (int argc, char* argv[]) 
{
  int objs[2*N];
  int i;

  for(i=0; i<2*N;i++)
    objs[i]=i;

  random_permutation(objs, 2*N);

  heap A=prof_heap_create(f);
  heap B=prof_heap_create(f);

  printf("Test de heap_merge\n");

  for(i=0; i<N; i++)
    A=prof_heap_insert(A, &objs[i]);

  for(i=N; i<2*N; i++)
    B=prof_heap_insert(B, &objs[i]);

  heap_dump(A);
  heap_dump(B);

  A=heap_merge(A, B);
  heap_dump(A);

  prof_heap_destroy(A);
  prof_heap_destroy(B);

  return 0;  
}
