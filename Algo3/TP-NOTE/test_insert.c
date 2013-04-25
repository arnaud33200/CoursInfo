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

#define N 5
int main (int argc, char* argv[]) 
{
  int objs[2*N+1];
  int i;

  objs[0]=N;
  for(i=1; i<=N;i++){
    objs[2*i-1]=N+i;
    objs[2*i]=N-i;
  }

  printf("Test de heap_insert\n");

  heap h=prof_heap_create(f);

  for(i=0; i<=2*N; i++){
    printf("Insert %d\n", objs[i]);
    h=heap_insert(h, &objs[i]);
    heap_dump(h);
    getchar();
  }

  heap_dump(h);
  prof_heap_destroy(h);

  /********************************/
  random_permutation(objs, 2*N+1);
  h=prof_heap_create(f);

  for(i=0; i<=2*N; i++){
    printf("Insert %d\n", objs[i]);
    h=heap_insert(h, &objs[i]);
    heap_dump(h);
  }

  prof_heap_destroy(h);

  return 0;  
}
