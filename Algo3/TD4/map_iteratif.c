/* map.c */

#define DEBUG 1
#define print_debug(fmt,...)\
  do { if(DEBUG) fprintf(stderr, "%s;%d:%s " fmt, __FILE__, __LINE__,\
   __func__, __VA_ARGS__ );} while(0)

#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct tree_t * tree;
struct tree_t{
  tree left;
  tree right;
  void * object;
};

struct map_t{
  keyfunc f;
  tree root;
  int height;
};

int max(int x, int y){
  if(x<y)
    return y;
  else
    return x;
}

int isLeaf(tree t)
{
  return t->left == NULL && t->right == NULL ? 1 : 0;
}

/* create an empty map */
map map_create(keyfunc f)
{
  map nm = malloc(sizeof(struct map_t));
  nm->f = f;
  nm->height = 0;
  nm->root = NULL;
  return nm;
}

/* destroy a map */
void map_destroy(map f)
{

}

/* return the height of a map */
int map_height(map f)
{
  return 0;
}

/* find an object in the map and return it or NULL if not found */
void * map_find(map m, int key)
{
  tree t = m->root;
  while( t != NULL )
  {
    if (key == m->f(t->object))
      return t->object;
    else if(key < m->f(t->object))
      t = (t->left != NULL ? t->left : NULL);
    else if(key > m->f(t->object))
      t = (t->right != NULL ? t->left : NULL);
    else
      return NULL;
  }
  return NULL;
}

tree create_tree(void * object, tree f)
{
  tree n = malloc(sizeof(struct tree_t));
  n->object = object;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/* insert an object in a map and return it or NULL in case of
   failure (NULL object or object already inside the map) */
void * map_insert(map m, void * object)
{
  
  tree t = m->root;

  if(t == NULL)
  {
    m->root = create_tree(object, t);
    return object;
  }

  // print_debug("test");

  while( t != NULL )
  {
    if( m->f(t) == m->f(object) )
      return NULL;
    else if (isLeaf(t))
    {
      tree n = create_tree(object, t);
      if( m->f(object) < m->f(t) )
        t->left = n;
      else t->right = n;
      return object;
    }
    else if( m->f(object) < m->f(t) )
    {
      printf("cle objet inf\n");
      if( t->left == NULL )
      {
        tree n = create_tree(object, t);
        t->left = n;
        return object;
      }
      else
        t = t->right;
    }
    else if( m->f(object) > m->f(t) )
    {
      printf("cle objet sup\n");
      if( t->right == NULL )
      {
        tree n = create_tree(object, t);
        t->right = n;
        return object;
      }
      else
        t = t->left;
    }
    else
      return NULL;
  }
  return NULL;
}

/* delete an object from a map and return it or NULL in not found */
void * map_delete(map m, int key){
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
