/* splay.c */

#include "splay.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**********************************************************/

int isLeaf(tree t)
{
  return t->left == NULL && t->right == NULL ? 1 : 0;
}

tree createTree(void * o)
{
  tree newTree = malloc(sizeof(struct tree_t));
  newTree->left = NULL;
  newTree->right = NULL;
  newTree->object = o;
  return newTree;
}

tree left_rotate(tree t)
{
  if(t->right == NULL)
    return t;

  tree newroot = t->right;
  t->right = newroot->left;
  newroot->left = t;
  t = newroot;

  return t;
}

tree right_rotate(tree t)
{
  if(t->left == NULL)
    return t;
  
  tree newroot = t->left;
  t->left = newroot->right;
  newroot->right = t;
  t = newroot;
  return t;
}

tree splay_splay_recur(tree node, int key, keyfunc f)
{
  if( f(node->object) == key || isLeaf(node) )
    return node;
  else if( node->left != NULL && key < f(node->object) ) 
  {
    node->left = splay_splay_recur(node->left, key, f);
    node = right_rotate(node); 
    return node;
  }
  else if( node->right != NULL && key > f(node->object) ) 
  {
    node->right = splay_splay_recur(node->right, key, f);
    node = left_rotate(node);
    return node; 
  }
  else
    return node;
}

void splay_splay(splay m, int key)
{
  m->root = splay_splay_recur( m->root, key, m->f);
}

void splay_cheap_splay(splay m, int key)
{
  prof_splay_cheap_splay(m, key);
}

/* create an empty splay */
splay splay_create(keyfunc f)
{
  splay newsplay = malloc(sizeof(struct splay_t));
  newsplay->root = NULL;
  newsplay->f = f;
  return newsplay;
}

/* find an object in the splay and return it or NULL if not found */

tree find_recure(tree node, int key, keyfunc f)
{
  if( f(node->object) == key || isLeaf(node))
    return node;
  else if( f(node->object) > key )
    return node->left != NULL ? find_recure(node->left, key, f) : node;
  else
    return node->right != NULL ? find_recure(node->right, key, f) : node;
}
tree find_recure_sup(tree node, int key, keyfunc f)
{
  if( f(node->object) == key || isLeaf(node) || node->right == NULL )
    return node;
  else if( node->right != NULL && f(node->right->object) > key )
    return node;
  else
    return find_recure(node->right, key, f);
}

void * splay_find(splay m, int key)
{
  splay_splay(m, key);
  return m->f(m->root->object) == key ? m->root->object : NULL;
}

/* insert an object in a splay and return it or NULL in case of
   failure (NULL object or object already inside the splay) */

void * splay_insert(splay m, void * object)
{
  if( m->root ==  NULL)
  {
    tree newTree = createTree(object);
    m->root = newTree;
    return object;
  }
  splay_splay(m, m->f(object)); 
  if( m->root->object == object )
    return NULL;
  else
  {
    tree newTree = createTree(object);
    if( m->f(object) > m->f(m->root->object)  )
    {
      printf("mis à gauche : %d > %d\n", m->f(object), m->f(m->root->object) );
      newTree->left = m->root;
    }
    else
      newTree->right = m->root;
    m->root = newTree;
    return object;
  }
}

splay splay_union(splay A, splay B)
{
  return prof_splay_union(A, B);
}

/* delete an object from a splay and return it or NULL in not found */
void * splay_delete(splay m, int key)
{
  return prof_splay_delete(m, key);
}

splay splay_coupe(splay m, int key)
{
  printf("key ask : %d\n", key);
  printf("root before : %d \n", m->f(m->root->object) );
  splay_splay(m, key);
  printf("root after : %d \n", m->f(m->root->object) );
  splay newsplay = malloc(sizeof(struct splay_t));
  newsplay->root = m->root->right;
  newsplay->f = m->f;
  m->root->right = NULL;
  return newsplay;
}

void destroy_recur(tree node)
{
  if(node == NULL)
    return;
  else if(isLeaf(node))
    free(node);
  else
  {
    if ( node->left != NULL ) destroy_recur(node->left);
    if ( node->right != NULL ) destroy_recur(node->right);
    free(node);
  }
}

void splay_destroy(splay m)
{
  if(m->root != NULL)
    destroy_recur(m->root);
  free(m);
}

