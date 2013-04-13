/* splay.c */

#include "splay.h"
#include <stdlib.h>
#include <assert.h>

/**********************************************************/
tree rotate_left(tree node){
  assert(node!=NULL && node->right!=NULL);
  
  tree right=node->right;
  node->right=right->left;
  right->left=node;
  return right;
}

tree rotate_right(tree node){
  assert(node!=NULL && node->left!=NULL);
  
  tree left=node->left;
  node->left=left->right;
  left->right=node;
  return left;
}

tree splay_tree(tree root, keyfunc f, int key){
  if(root == NULL)
    return NULL;

  int localkey = f(root->object);  

  if(key == localkey)
    return root;

  else if(key < localkey){
    tree left=root->left;

    if(left == NULL)
      return root;

    int leftkey=f(left->object);
    if(key == leftkey)
      return rotate_right(root);

    else if(key < leftkey){
      if(left->left == NULL)
	return rotate_right(root);

      root->left->left=splay_tree(root->left->left, f, key);
      return rotate_right(rotate_right(root));
    }
    else{
      if(left->right == NULL)
	return rotate_right(root);

      root->left->right=splay_tree(root->left->right, f, key);
      root->left=rotate_left(root->left);
      return rotate_right(root);
    }
  }
  else{
    tree right=root->right;

    if(right == NULL)
      return root;

    int rightkey=f(right->object);
    if(key == rightkey)
      return rotate_left(root);

    else if(key > rightkey){
      if(right->right == NULL)
	return rotate_left(root);

      root->right->right=splay_tree(root->right->right, f, key);
      return rotate_left(rotate_left(root));
    }
    else{
      if(right->left == NULL)
	return rotate_left(root);

      root->right->left=splay_tree(root->right->left, f, key);
      root->right=rotate_right(root->right);
      return rotate_left(root);
    }
  }  
}


void splay_splay(splay m, int key){
  if(m == NULL)
    return;
  m->root=splay_tree(m->root, m->f, key);
}
