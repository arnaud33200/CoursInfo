/* map.c */

#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct tree_t * tree;
struct tree_t
{
  tree left;
  tree right;
  void * object;
};

struct map_t
{
  keyfunc f;
  tree root;
  int height;
};

int max(int x, int y)
{
  if(x<y) return y;
  else return x;
}

int isLeaf(tree t)
{
  return t->left == NULL && t->right == NULL ? 1 : 0;
}

/* create an empty map */
map map_create(keyfunc f)
{
  map new = malloc(sizeof(struct map_t));
  new->f = f;
  new->height = 0;
  return new;
}

void destroy_recur(tree t)
{
  if(isLeaf(t))
    free(t);
  else
  {
    destroy_recur(t->left);
    destroy_recur(t->right);
    free(t);
  }
}

/* destroy a map */
void map_destroy(map f)
{
  destroy_recur(f->root);
  free(f);
}

int height_recur(tree t)
{
  if(isLeaf(t))
    return 1;
  else
    return ( max(height_recur(t->left), height_recur(t->right)) + 1 );
}

/* return the height of a map */
int map_height(map f)
{
  return height_recur(f->root) - 1;
}


void * find_recur(tree t, int k, keyfunc f)
{
  if( f(t->object) == k )
    return t->object;
  else if( isLeaf(t) )
    return NULL;
  else if( f(t->object) < k )
    return find_recur(t->left, k, f);
  else
    return find_recur(t->right, k, f);
}
/* find an object in the map and return it or NULL if not found */
void * map_find(map m, int key)
{
  return find_recur(m->root, key, m->f);
}

/* insert an object in a map and return it or NULL in case of
   failure (NULL object or object already inside the map) */
void * insert_recur(tree t, void * o, keyfunc f)
{
  if( isLeaf(t) )
  {
    if( f(o) == f(t->object) )
      return NULL;    // cas d'égalité 
    tree n = malloc(sizeof(struct tree_t));
    n->object = o;
    if( f(o) > f(t->object) )
      t->right = n;
    else
      t->left = n;
    return o;
  }
  else if( f(o) < f(t->object) )
  {
    if ( t->left == NULL )
    {
      tree n = malloc(sizeof(struct tree_t));
      n->object = o;
      t->left = n;
      return o;
    }
    else
    return insert_recur(t->left, o, f);
  }
  else if( f(o) > f(t->object) )
  {
    if ( t->right == NULL )
    {
      tree n = malloc(sizeof(struct tree_t));
      n->object = o;
      t->right = n;
      return o;
    }
    else
    return insert_recur(t->right, o, f);
  }
  else
    return NULL; // cas d'égalité 
}

void * map_insert(map m, void * object)
{
  if( m->root == NULL )
  {
    tree n = malloc(sizeof(struct tree_t));
    n->object = object;
    m->root = n;
    return object;
  }
  else
    return insert_recur(m->root, object, m->f);
}

/* delete an object from a map and return it or NULL in not found */
void * map_delete(map m, int key)
{
  return NULL;
}



//------------------AFFICHAGE D'ARBRE BINAIRE--------------

int tree_height(tree node)
{
  if(node == NULL) return 0;   /* the height of a void tree is 0. */
  return 1 + max(tree_height(node->left),tree_height(node->right));
}

void tree_traverse_and_mark(map m,
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

void map_dump(map m) 
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
    for(j = 0 ; j < height ; j++) {    
      printf("|");
      for(i = 0 ; i < width ; i++) {
        if(array[j][i] < 0) printf("  ");
        else printf("%.2d",array[j][i]);
      }
      printf("|\n");
    }

  }
