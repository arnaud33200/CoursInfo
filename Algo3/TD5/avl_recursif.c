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
  tree father;
  int weight;
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

int isLeaf(tree t)
{
  return t->left == NULL && t->right == NULL ? 1 : 0;
}

void add_weight_recur(tree t, int a)
{
  if(t == NULL) return;
  t->weight += a;
  if(t->left != NULL) add_weight_recur(t->left, a);
  if(t->right != NULL) add_weight_recur(t->right, a);
}

void left_rotate(tree t)
{
  if(t->right == NULL)
    return;

  tree nr = create_tree(t->right->object, t->father);
  nr->right = t->right->right;
  nr->left = t;
  

  tree oldroot = t;
  t = oldroot->right;
  oldroot->right = t->left;
  t->left = oldroot;
  t->father = oldroot->father;
  if ( t->father->left == oldroot ) t->father->left = t; 
  else t->father->right = t;
// mise à jours hauteur
  t->weight--;
  add_weight_recur(t->right, -1);
  t->left->weight++;
  add_weight_recur(t->left->left, 1);
}

void right_rotate(tree t)
{
  if(t->left == NULL)
    return;
  tree oldroot = t;
  t = oldroot->left;
  oldroot->left = t->right;
  t->right = oldroot;
  t->father = oldroot->father;
  if ( t->father->left == oldroot ) t->father->left = t; 
  else t->father->right = t;
  t->weight--;
  add_weight_recur(t->left, -1);
  t->right->weight++;
  add_weight_recur(t->right->right, 1);
}

/* create an empty avl */
avl avl_create(keyfunc f)
{
  avl na = malloc(sizeof(struct avl_t));
  na->f = f;
  // na->height = 0;
  na->root = NULL;
  return na;
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
/* destroy a avl */
void avl_destroy(avl f)
{
  if( f->root != NULL)
    destroy_recur(f->root);
  free(f);
}

/* return the height of a avl */

int height_recur(tree t)
{
  if(t == NULL) 
    return 0;
  else if(isLeaf(t))
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

int avl_height(avl f)
{
  return 0;
}

/* find an object in the avl and return it or NULL if not found */

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

void * avl_find(avl m, int key)
{
  tree f = find_recur(m->root, key, m->f); 
  return f != NULL ? f->object : NULL;
}

/* insert an object in a avl and return it or NULL in case of
   failure (NULL object or object already inside the avl) */

void check_balance(tree t)
{
  puts("enter check");
  if( t == NULL ) return;
  int hl = height_recur(t->left);
  int hr = height_recur(t->right);
  if ( abs(hl-hr) > 1 )
  {
    puts("need balance !");
    if( hl - hr == -2  )
    {
      int bfr = height_recur(t->right->left)-height_recur(t->right->right);
      if( bfr == -1 )
        left_rotate(t);
      else if ( bfr == 1)
      {
        right_rotate(t->right);
        left_rotate(t);
      }
    }
    else
    {
      int bfl = height_recur(t->left->left)-height_recur(t->left->right);
      if( bfl == -1 )
        right_rotate(t);
      else if ( bfl == 1)
      {
        left_rotate(t->left);
        right_rotate(t);
      }
    }
  }
}

tree create_tree(void * object, tree f)
{
  tree n = malloc(sizeof(struct tree_t));
  n->object = object;
  n->left = NULL;
  n->right = NULL;
  n->father = f;
  n->weight = (f == NULL ? 1 : f->weight+1);
  return n;
}

void * insert_recur(tree t, void * o, keyfunc f)
{
  void * rtn;
  if( isLeaf(t) )
  {
    if( f(o) == f(t->object) )
      rtn = NULL;    // cas d'égalité 
    tree n = create_tree(o, t);
    if( f(o) > f(t->object) )
      t->right = n;
    else
      t->left = n;
    rtn = o;
  }
  else if( f(o) < f(t->object) )
  {
    if ( t->left == NULL )
    {
      tree n = create_tree(o, t);
      t->left = n;
      rtn = o;
    }
    else
      rtn = insert_recur(t->left, o, f);
  }
  else if( f(o) > f(t->object) )
  {
    if ( t->right == NULL )
    {
      tree n = create_tree(o, t);
      t->right = n;
      rtn = o;
    }
    else
      rtn = insert_recur(t->right, o, f);
  }
  else
    rtn = NULL;
  check_balance(t);
  return rtn;
}

void * avl_insert(avl m, void * object)
{
  if( m->root == NULL )
  {
    tree n = create_tree(object, m->root);
    m->root = n;
    return object;
  }
  else
    return insert_recur(m->root, object, m->f);
}

/* delete an object from a avl and return it or NULL in not found */
void * avl_delete(avl m, int key)
{
  return NULL;
}



//------------------AFFICHAGE D'ARBRE BINAIRE--------------

int tree_height(tree node)

{
  if(node == NULL) return 0;   /* the height of a void tree is 0. */
  return 1 + max(tree_height(node->left),tree_height(node->right));
}

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