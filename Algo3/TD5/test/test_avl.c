/* test_avl.c */

#include "avl.h"
#include "stdio.h"

int f(void * object) { return *((int*)object); }

int main (int argc, char* argv[]) 
{
  avl m = avl_create(f);
  int a=10, b=6, c=13, d=19, e=14, f=20, g=11;
  avl_insert(m, &a); printf("\ninsertion de %d\n", a);
  avl_insert(m, &b); printf("\ninsertion de %d\n", b);
  avl_dump(m);
  avl_insert(m, &c); printf("\ninsertion de %d\n", c);
  avl_dump(m);
  avl_insert(m, &d); printf("\ninsertion de %d\n", d);
  avl_dump(m);
  avl_insert(m, &e); printf("\ninsertion de %d\n", e);
  avl_dump(m);
  avl_insert(m, &f); printf("\ninsertion de %d\n", f);
  avl_dump(m);
  avl_insert(m, &g); printf("\ninsertion de %d\n", g);
  avl_dump(m);

  void * fb = avl_find(m, c);
  printf("\nfind %d: %s\n", c, (fb != NULL)?"true":"false");

  /* delete a leaf */
  // printf("\nsuppr de %d\n", f);
  // avl_delete(m,f); 
  // avl_dump(m);
  /* delete a node with a single child */
  // ???

  /* delete a node with two children */
  printf("\nsuppr de %d\n", e);
  avl_delete(m,e); 
  avl_dump(m);
  printf("\nsuppr de %d\n", c);
  avl_delete(m,c); 

  /* delete the root node */
  // avl_delete(m,a); 

  avl_dump(m);
  
  return 0;
  
}
