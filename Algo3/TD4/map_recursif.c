/* map.c */

#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct tree_t * tree;
struct tree_t
{
  tree father;
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
  map nm = malloc(sizeof(struct map_t));
  nm->f = f;
  nm->height = 0;
  nm->root = NULL;
  return nm;
}

void destroy_recur(tree t)
{
  if(t == NULL)
    return;
  else if(isLeaf(t))
    free(t);
  else
  {
    if ( t->left != NULL ) destroy_recur(t->left);
    if ( t->right != NULL ) destroy_recur(t->right);
    free(t);
  }
}

/* destroy a map */
void map_destroy(map f)
{
  if( f->root != NULL)
    destroy_recur(f->root);
  free(f);
}

int height_recur(tree t)
{
  if(isLeaf(t))
    return 1;
  else
  {
    int l, r;
    l = r = 0;
    if(t->left != NULL)
      l = height_recur(t->left);
    if(t->right != NULL)
      r = height_recur(t->right);
    return max(l,r) + 1;
  }
}

/* return the height of a map */
int map_height(map f)
{
  return height_recur(f->root) - 1;
}


tree find_recur(tree t, int k, keyfunc f)
{
  if ( t == NULL)
    return NULL;
  else if( f(t->object) == k )
    return t;
  else if( isLeaf(t) )
    return NULL;
  else if( f(t->object) > k )
      return t->left != NULL ? find_recur(t->left, k, f) : NULL;
  else
    return t->right != NULL ? find_recur(t->right, k, f) : NULL;
}
/* find an object in the map and return it or NULL if not found */
void * map_find(map m, int key)
{
  tree f = find_recur(m->root, key, m->f); 
  return f != NULL ? f->object : NULL;
}

tree create_tree(void * object, tree f)
{
    tree n = malloc(sizeof(struct tree_t));
    n->object = object;
    n->left = NULL;
    n->right = NULL;
    n->father = f;
    return n;
}

/* insert an object in a map and return it or NULL in case of
   failure (NULL object or object already inside the map) */
void * insert_recur(tree t, void * o, keyfunc f)
{
  if( isLeaf(t) )
  {
    if( f(o) == f(t->object) )
      return NULL;    // cas d'égalité 
    tree n = create_tree(o, t);
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
      tree n = create_tree(o, t);
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
      tree n = create_tree(o, t);
      t->right = n;
      return o;
    }
    else
      return insert_recur(t->right, o, f);
  }
  else
    return NULL; 
}

void * map_insert(map m, void * object)
{
  if( m->root == NULL )
  {
    tree n = create_tree(object, NULL);
    m->root = n;
    return object;
  }
  else
    return insert_recur(m->root, object, m->f);
}

tree find_smaller(tree t)
{
  if(isLeaf(t))
    return t;
  if( t->left != NULL)
    return find_smaller(t->left);
  else
    return t;
}

tree find_bigger(tree t)
{
  if(isLeaf(t))
    return t;
  if( t->right != NULL)
    return find_bigger(t->right);
  else
    return t;
}

/* delete an object from a map and return it or NULL in not found */
void * map_delete(map m, int key)
{
  if (m->root == NULL)return NULL;

  tree t = find_recur(m->root, key, m->f);
  if ( t == NULL ) return NULL;

  void * o = t->object;

  if ( isLeaf(t) )
  {
    if ( t->father->left == t ) t->father->left = NULL; 
    else t->father->right = NULL;
    free(t);
    return o;
  }
  else if (t->right == NULL)
  {
    t->left->father = t->father;
    if ( t->father->left == t ) t->father->left = t->left; 
    else t->father->right = t->left;
    free(t);
    return o;
  }
  else if (t->left == NULL)
  {
    t->right->father = t->father;
    if ( t->father->left == t ) t->father->left = t->right; 
    else t->father->right = t->right;
    free(t);
    return o;
  }
  else    // cas des deux fils non vide
  {
    tree replace;
    if( height_recur(t->left) >= height_recur(t->right))
    {
      replace = find_bigger(t->left);
      if ( replace->left != NULL)
        replace->father->right = replace->left;
      else
        replace->father->right = NULL;
    }
    else
    {
      replace = find_smaller(t->right);
      if ( replace->right != NULL)
        replace->father->left = replace->right;
      else
        replace->father->left = NULL;
    }

    replace->father = t->father;
    if ( t->father->left == t ) t->father->left = replace;
    else t->father->right = replace;

      replace->right = t->right;
      replace->left = t->left;
    free(t);
    return o;
  }
  return NULL;
}



//------------------AFFICHAGE D'ARBRE BINAIRE--------------

int tree_height(tree node)
{
  if(node == NULL) return 0;   /* the height of a void tree is 0. */
  return 1 + max(tree_height(node->left),tree_height(node->right));
  // if(isLeaf(node))
  //   return 1;
  // else
  // {
  //   int l, r;
  //   l = r = 0;
  //   if(node->left != NULL)
  //     l = tree_height(node->left);
  //   if(node->right != NULL)
  //     r = tree_height(node->right);
  //   return max(l,r) + 1;
  // }
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
