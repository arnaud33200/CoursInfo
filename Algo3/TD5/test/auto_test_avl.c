/* test_avl.c */

#include "avl.h"
#include <stdbool.h>
#include <stdio.h>

#include "avl_recursif.c"

int f(void * object) { return *((int*)object); }

/* verify if a tree respect the binary search tree conditions */
bool test_searchtree(tree t, keyfunc f) {

  bool check = true;
  if(t == NULL) {
    return check;
  }
  
  if(t->left != NULL) {
    check = check && (f(t->left->object) < f(t->object));
    check = check && test_searchtree(t->left, f);
  }
  
  if(t->right != NULL) {
    check = check && (f(t->right->object) > f(t->object));
    check = check && test_searchtree(t->right, f);
  }
  
  return check;
}

int tree_size(tree t) {
  int s = 0;
  
  if (t != NULL) {
    s += 1;
    s += tree_size(t->left);
    s += tree_size(t->right);
  }
  
  return s; 
}

/* Test if insertion generates a tree of correct size */
bool test_insertsize(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[k];
  for (int i = 0; i < k; i++) {
    objs[i] = i;
    avl_insert(a, &objs[i]);
    check = check && tree_size(a->root) == i+1;
  }
  avl_destroy(a);
  
  return check;
}


/* Test if insertion keeps the search tree conditions */
bool test_insert0(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[k];
  for (int i = 0; i < k; i++) {
    objs[i] = i;
    avl_insert(a, &objs[i]);
    check = check && test_searchtree(a->root, a->f);
  }  
  avl_destroy(a);
  
  return check;
}

/* Test if find works ok */
bool test_find0(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[2*k];
  for (int i = 0; i < 2*k; i++) {
    objs[i] = i;
    if (i < k) {
      avl_insert(a, &objs[i]);
    }
  }  
  
  for (int i = 0; i < 2*k; i++) {
    void* found = avl_find(a, f(&objs[i]));
    if (i >= k) {
      check = check && (found == NULL);
    } else {
      check = check && (found != NULL);
    }
  }
  avl_destroy(a);
  
  return check;
}

/* Test if deletion generates a tree of correct size */
bool test_del_size(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[k];
  for (int i = 0; i < k; i++) {
    objs[i] = i;
    avl_insert(a, &objs[i]);
  }  
  check = check && tree_size(a->root) == k;

  for (int i = 0; i < k; i++) {
    avl_delete(a, f(&objs[i]));
    check = check && tree_size(a->root) == k-i-1;
  }  
  avl_destroy(a);
  
  return check;
}

/* Test if deletion (with misses) generates a tree of correct size */
bool test_del2_size(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[2*k];
  for (int i = 0; i < 2*k; i++) {
    objs[i] = i;
    if (i < k) {
      avl_insert(a, &objs[i]);
    }
  }  
  check = check && tree_size(a->root) == k;

  for (int i = 0; i < 2*k; i++) {
    int i2 = i/2;
    if (i % 2 == 0) {
      avl_delete(a, f(&objs[i2]));
    }
    else {
      avl_delete(a, f(&objs[i2+k]));
    }
    int correct_size = k - i2 - 1;
    check = check && tree_size(a->root) == correct_size;
  }  
  avl_destroy(a);
  
  return check;
}

/* Test if deletion generates a tree of correct size */
bool test_del3_size(int k) {
  
  bool check = true;
  
  avl a = avl_create(f);
  int objs[k];
  for (int i = 0; i < k; i++) {
    objs[i] = i;
    avl_insert(a, &objs[i]);
  }  
  check = check && tree_size(a->root) == k;

  for (int i = 0; i < k; i++) {
    avl_delete(a, f(&objs[i]));
    avl_delete(a, f(&objs[i]));
    avl_delete(a, f(&objs[i]));
    check = check && tree_size(a->root) == k-i-1;
  }  
  avl_destroy(a);
  
  return check;
}

int main (int argc, char* argv[]) 
{

  int k = 10;
  
  if (test_insertsize(k)) { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if insertion generates a tree of correct size");
  
  if (test_insert0(k))    { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if insertion keep the binary search structure");

  if (test_find0(k))      { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if find finds the correct keys");
  
  if (test_del_size(k))   { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if deletion generates a tree of correct size");
  
  if (test_del2_size(k))  { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if deletion (with non-existent keys) generates a tree of correct size");

  if (test_del3_size(k))  { printf("[\033[1;32mPASS\033[0m] "); } 
  else                    { printf("[\033[1;31mFAIL\033[0m] "); }
  puts("Test if multiple deletions generate a tree of correct size");

  
  return 0;
  
}
