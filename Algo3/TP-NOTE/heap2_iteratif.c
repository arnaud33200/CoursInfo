/* heap.c */

#include "heap2.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"



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
// Pile pour les appels descandants
	stack da = stack_create();
	stack_push(da, A);
	stack db = stack_create();
	stack_push(db, B);

// Pile pour les appels remontants
	stack r = stack_create();

	while( stack_empty(r) )
	{
		heap pa = stack_top(da);
		heap pb = stack_top(db);

		tree roota = pa->root;
		tree rootb = pb->root;
		if(roota == NULL) 
		{
			stack_push(r, pb);
			stack_pop(da);
			stack_pop(db);
		}
		else if(rootb == NULL)
		{
			stack_push(r, pa);
			stack_pop(da);
			stack_pop(db);
		}
		else
		{
			if(pa->f(roota->object) <= pb->f(rootb->object))
			{
				pa->root = roota->right;
				stack_push(db, pa);
				stack_push(da, pb);
			}
			else
			{
				pb->root = rootb->right;
				stack_push(da, pa);
				stack_push(db, pb);
			}
		}

	}
	while( !stack_empty(da) || !stack_empty(db) )
	{
		heap pa = stack_top(da);
		heap pb = stack_top(db);
		// printf("node A :%d\n", *(int*)pa->root->object);
		// printf("node B :%d\n", *(int*)pb->root->object);
		stack_pop(da);	
		stack_pop(db);

		tree roota = pa->root;

		heap rtn = stack_top(r);
		stack_pop(r);
		// printf("retourn = %d\n",*(int*)rtn->root->object );
		roota->right = rtn->root;
		pa->root = roota;
		stack_push(r, pa);
		permute(rtn->root);	
	}
	
	heap rtn = stack_top(r);
	stack_pop(r);
	permute(rtn->root);

	stack_destroy(da);
	stack_destroy(db);
	stack_destroy(r);

	return rtn;
}

void heap_destroy(heap m)
{
	stack p = stack_create();
	stack_push(p, m->root);
	while( !stack_empty(p))
	{
		tree node = stack_top(p);
		stack_pop(p);
		if( node->left != NULL )
			stack_push(p, node->left);
		if( node->right != NULL )
			stack_push(p, node->right);
		free(node);
	}
	free(m);  
	stack_destroy(p);
	puts("suppression reussit");
}


#include"heap_dump.c"
