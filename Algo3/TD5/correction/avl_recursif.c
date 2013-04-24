/* avl.c */

#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct tree_t * tree;
struct tree_t
{
  tree left;
  tree right;
  int height;
  void * object;
};

struct avl_t
{
  keyfunc f;
  tree root;
};

int max(int x, int y)
{
  if(x<y)
    return y;
  else
    return x;
}


/* create an empty avl */
avl avl_create(keyfunc f)
{
  avl m=malloc(sizeof(*m));
  m->root=NULL;
  m->f=f;
  return m;
}

/* destroy a avl */
void tree_destroy(tree node)
{
  if(node == NULL)
    return;

  tree_destroy(node->left);
  tree_destroy(node->right);
  free(node);
}

void avl_destroy(avl m)
{
  tree_destroy(m->root);
  free(m);
}

/* return the height of a avl */
int tree_height(tree node)
{
  if(node == NULL)
    return 0;   /* the height of a void tree is 0. */
  return node->height;
}

void fix_height(tree node)
{
  assert( node != NULL );
  node->height = 1+max(tree_height(node->left), tree_height(node->right));
}

int avl_height(avl m)
{
  return tree_height(m->root);
}


/* find an object in the avl and return it or NULL if not found */
void* tree_find(tree node, keyfunc f, int key)
{
  if(node == NULL)
    return NULL;

  int localkey=f(node->object);

  if(key == localkey)
    return node->object;
  else if(key < localkey)
    return tree_find(node->left, f, key);
  else
    return tree_find(node->right, f, key);
}

void * avl_find(avl m, int key)
{
  return tree_find(m->root, m->f, key);
}

/* insert an object in a avl and return it or NULL in case of
   failure (NULL object or object already inside the avl) */

tree rotate_left(tree A)
{
  assert(A != NULL);
  assert(A->right != NULL);

  tree B= A->right;
  A->right = B->left;
  B->left = A;
  fix_height(A);
  fix_height(B);
  return B;
}

tree rotate_right(tree B)
{
  assert(B != NULL);
  assert(B->left != NULL);

  tree A= B->left;
  B->left = A->right;
  A->right = B;
  fix_height(B);
  fix_height(A);
  return A;
}

tree reequilibrage(tree node)
{
  assert(node != NULL);

  if(tree_height(node->left) == tree_height(node->right) +2)
  {
    if(tree_height(node->left->left) < tree_height(node->left->right))
      node->left=rotate_left(node->left);
    return rotate_right(node);
  }

  if(tree_height(node->left) +2 == tree_height(node->right))
  {
    if(tree_height(node->right->right) < tree_height(node->right->left))
      node->right=rotate_right(node->right);
    return rotate_left(node);
  }

  fix_height(node);
  return node;
}


tree tree_insert(tree node, keyfunc f, int key, void * object)
{
  if(node == NULL)
  {
    tree new=malloc(sizeof(*new));
    new->left=NULL;
    new->right=NULL;
    new->height = 1;
    new->object=object;
    return new;
  }

  if(key < f(node->object))
    node->left=tree_insert(node->left, f, key, object);
  else
    node->right=tree_insert(node->right, f, key, object);    

  return reequilibrage(node);
}

void * avl_insert(avl m, void * object)
{
  if(object == NULL)
    return NULL;
  if(avl_find(m, m->f(object)) != NULL)
    return NULL;

  m->root=tree_insert(m->root, m->f, m->f(object), object);

  return object;
}

/* delete an object from a avl and return it or NULL in not found */

void * tree_get_max(tree node)
{
  if(node->right == NULL)
    return node->object;
  return tree_get_max(node->right);
}

tree tree_delete_max(tree node)
{
  if(node->right == NULL)
  {
    tree tmp=node->left;
    free(node);
    return tmp;
  }
  node->right=tree_delete_max(node->right);

  return reequilibrage(node);
}

tree tree_delete(tree node, int key, keyfunc f)
{
  if(key < f(node->object))
    node->left=tree_delete(node->left, key, f);
  else if(key > f(node->object))
    node->right=tree_delete(node->right, key, f);
  else
  {
    if(node->left == NULL)
    {
      tree res=node->right;
      free(node);
      return res;
    }
    else
    {
      node->object=tree_get_max(node->left);
      node->left=tree_delete_max(node->left);
      
    }
  }
  return reequilibrage(node);
}

void * avl_delete(avl m, int key)
{
  void * obj=avl_find(m, key);

  if(obj == NULL)
    return NULL;

  m->root=tree_delete(m->root, key, m->f);
  return obj;
}


//------------------AFFICHAGE D'ARBRE BINAIRE--------------

void tree_traverse_and_mark(avl m,
			    tree node,   /* current node */
			    int height,  /* tree height */
			    int * array, /* 2d array of marks */
			    int h,       /* node depth */
			    int w)       /* node lateral position */

{
  // traverse...
  if(node->left != NULL) 
    tree_traverse_and_mark(m,node->left,height,array,h+1,2*w);    
  if (node->right != NULL) 
    tree_traverse_and_mark(m,node->right,height,array,h+1,w*2+1);
  
  // mark...
  int width = (2 << (height-1)) - 1; /* width = 2^height - 1*/
  int j = h;
  int delta = (2 << (height-h-1)); /* delta =  2^(height-h) */
  int offset = delta/2-1;          /* offset = 2^(height-h-1) - 1*/
  int i = w*delta+offset; 
  int key = (*m->f)(node->object);   
  assert(key > 0); /* we assume it is > 0 */
  array[j*width+i] = key;
  // printf("mark: h=%d, w=%d, delta=%d, offset=%d\n", h, w, delta, offset); 
}

void avl_dump(avl m) 

{
  int height = tree_height(m->root);
  int width = (2 << (height-1)) - 1; /* width = 2^height - 1*/
  // printf("tree height: %d\n", height);
  // printf("tree width: %d\n", width);
  
  int array[height][width];
  int i, j;
  
  // reset array
  for(j = 0 ; j < height ; j++)
    for(i = 0 ; i < width ; i++) 
      array[j][i] = -1;
  
  // traverse tree and mark nodes
  if(m->root != NULL) 
    tree_traverse_and_mark(m,m->root,height,(int*)array,0,0);
  
  // dump array
  for(j = 0 ; j < height ; j++) 
  {    
    printf("|");
    for(i = 0 ; i < width ; i++) 
    {
      if(array[j][i] < 0) printf("  ");
      else printf("%.2d",array[j][i]);
    }
    printf("|\n");
  }
  
}
