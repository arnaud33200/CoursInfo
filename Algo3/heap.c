#include <stdio.h>
#include <stdlib.h>

typedef struct tree_t * tree;
typedef struct heap_t * heap;

struct tree_t
{
	tree left, right;
	int object;
	int svalue;
};

struct heap_t
{
	tree root;
};

int min(int a, int b)
{
	return a < b ? a : b;
}

heap create_heap()
{
	heap newheap = malloc(sizeof(*newheap));
	newheap->root = NULL;
	return newheap;
}

void update_s_value(tree node)
{
	if (node->left != NULL && node->right != NULL)
		node->svalue = min(node->right->svalue, node->left->svalue) +1;
	else
		node->svalue = 0;
	printf("node(%d) svalue = %d\n", node->object, node->svalue);
}

void check_leftist(tree node)
{
	// if( node->left == NULL && node->right == NULL) return;
	if( node->left == NULL || node->left->svalue < node->right->svalue)
	{
		puts("permutation");
		tree tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}

tree recure_merge(tree a, tree b)
{
	tree rtn;
	if( a == NULL )  rtn = b;
	else if( b == NULL ) rtn = a;
	else
	{
		// printf("choix de merge entre : %d - %d\n", a->object, b->object);
		if( a->object < b->object)
		{
			a->right = recure_merge(a->right, b);
			// printf("fils droit a: %d\n", a->right->object);
			rtn = a;
		}
		else
		{
			b->right = recure_merge(b->right, a);
			// printf("fils droit b: %d\n", b->right->object);
			rtn = b;
		}
	}
	update_s_value(rtn);
	check_leftist(rtn);
	// printf("retourne ");
	// printf("noeud(%d) : %d  -- %d\n", rtn->object,(rtn->left == NULL?-1:rtn->left->object),(rtn->right == NULL?-1:rtn->right->object));
	return rtn;
}

void add_heap(heap t, int key)
{
	tree newnode = malloc(sizeof(*newnode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->svalue = 0;
	newnode->object = key;

	t->root = recure_merge( t->root, newnode);
	// printf("### new root ");
	// printf("noeud(%d) : %d  -- %d\n", t->root->object,(t->root->left == NULL?-1:t->root->left->object),(t->root->right == NULL?-1:t->root->right->object));
}

void print_tree(tree node)
{
	if(node == NULL) return;
	printf("noeud(%d) : %d  -- %d\n", node->object,(node->left == NULL?-1:node->left->object),
		(node->right == NULL?-1:node->right->object));
	print_tree(node->left);
	print_tree(node->right);
}

int main(int argc, char const *argv[])
{
	heap mh = create_heap();
	add_heap(mh, 5);
	add_heap(mh, 7);
	add_heap(mh, 9);
	add_heap(mh, 14);
	add_heap(mh, 3);
	add_heap(mh, 40);
	add_heap(mh, 1);
	add_heap(mh, 33);
	print_tree(mh->root);
	return 0;
}