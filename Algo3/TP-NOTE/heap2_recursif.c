/* heap.c */

#include "heap2.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>



/*********************************************************/
heap heap_create(keyfunc f)
{
  heap nh = malloc(sizeof(*nh));
  nh->f = f;
  nh->root = NULL;
  return nh;
}

/* insert an element in the heap or NULL if object is NULL */
heap heap_insert(heap h, void* object)
{
	if( object == NULL) return NULL;

	tree nt = malloc(sizeof(*nt));
	nt->left = NULL;
	nt->right = NULL;
	nt->object = object;

	heap tmph = heap_create(h->f);
	tmph->root = nt;
	h = heap_merge(h, tmph );
	// free(tmph);
	return h;
}

/* get the element of minimum weight of NULL in case of empty heap */
void* heap_get_min(heap h)
{
  return h->root == NULL?NULL:h->root->object;
}

/* removes the element of minimum weight or does nothing in case of empty heap */
heap heap_remove_min(heap h)
{
	if( h->root == NULL ) return NULL;

	tree sl = h->root->left;
	tree sr = h->root->right;
	free(h->root);
	h->root = sl;
	heap tmph = heap_create(h->f);
	tmph->root = sr;
	h = heap_merge(h, tmph);
	// free(tmph);
	return h;
}

void permute(tree node)
{
	if(node == NULL) return;
	else
	{
		// puts("permutation");
		tree tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}

/* return a heap which contains all the elements of A and B and destroys A and B in the process*/
heap heap_merge(heap A, heap B)
{
	heap rtn;
	tree roota = A->root;
	tree rootb = B->root;

	if(roota == NULL) rtn = B;
	else if(rootb == NULL) rtn = A;
	else
	{
		if(A->f(roota->object) <= B->f(rootb->object))
		{
			A->root = roota->right;
			rtn = heap_merge(A, B);
			roota->right = rtn->root;
			A->root = roota;
			rtn = A;
		}
		else
		{
			B->root = rootb->right;
			rtn = heap_merge(B, A);
			rootb->right = rtn->root;
			B->root = rootb;
			rtn = B;
		}
	}

	permute(rtn->root);	
	return rtn;

  // return prof_heap_merge(A, B);
}

void destroy_recur(tree node)
{
	if(node != NULL)
	{
		destroy_recur(node->left);
		destroy_recur(node->right);
		free(node);
	}
}

void heap_destroy(heap m)
{
	destroy_recur(m->root);
	free(m);  
}

#include"heap_dump.c"
