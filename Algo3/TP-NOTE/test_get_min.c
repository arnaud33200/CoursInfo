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
  int objs[2*N+1];
  int i;

  objs[0]=N;
  for(i=1; i<=N;i++){
    objs[2*i-1]=N+i;
    objs[2*i]=N-i;
  }
  random_permutation(objs, 2*N+1);

  printf("Test de heap_remove_min\n");

  /********************************/
  heap h=prof_heap_create(f);

  for(i=0; i<=2*N; i++){
    h=prof_heap_insert(h, &objs[i]);
    printf("Min: %d\n", f(heap_get_min(h)));
    heap_dump(h);
  }

  prof_heap_destroy(h);

  return 0;  
}
