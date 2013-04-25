/* test_splay.c */

#include "heap1.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int f(void * object) { return *((int*)object); }

#define N 6
int main (int argc, char* argv[]) 
{
  printf("Test de heap_create\n");

  heap h=heap_create(f);

  int a=1;
  h=prof_heap_insert(h, &a);

  heap_dump(h);

  prof_heap_destroy(h);
  return 0;  
}
