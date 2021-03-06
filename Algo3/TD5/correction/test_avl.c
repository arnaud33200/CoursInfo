/* test_avl.c */

#include "avl.h"
#include "stdio.h"

int f(void * object) { return *((int*)object); }

int main (int argc, char* argv[]) 
{
  avl m = avl_create(f);
  int a=10, b=6, c=13, d=19, e=14, f=20, g=11;

  avl_insert(m, &a);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &b);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &c);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &d);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &e);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &f);  avl_dump(m); printf("-----------------\n");
  avl_insert(m, &g);  avl_dump(m); printf("-----------------\n");

  void * fb = avl_find(m, b);
  printf("find %d: %s\n", b, (fb != NULL)?"true":"false");

  /* delete a leaf */
  // avl_delete(m,f); 
  /* delete a node with a single child */
  // ???

  /* delete a node with two children */
  // avl_delete(m,d); 
  avl_delete(m,c); 

  /* delete the root node */
  // avl_delete(m,a); 

  avl_dump(m);
  
  return 0;
  
}
