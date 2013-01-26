#include "stack.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>

struct element_t
{
	void * value;
	element * next;
};

struct list_t
{
	element * first;
};

struct stack_t
{
	list l;
	int length;
};

/* create an empty stack */
stack stack_create(void)
{
	stack s = malloc(sizeof(stack));
	
	//~ void ** values = malloc(sizeof(void*)*BLOCK);
	//~ element * elements = malloc(sizeof(element)*BLOCK);
	//~ int i=0;
	//~ for (i; i<BLOCK; i++)
	//~ {
		//~ elements[i]->value = &values[i];
		//~ if( i == BLOCK -1 )
			//~ elements[i]->next = NULL;
		//~ else
			//~ elements[i]->next = &elements[i+1];
	//~ }
	//~ s->list.first = &elements[0];
	s->l.first = NULL;
	s->length = 0;
	return s;
}

void stack_push(stack s, void *object)
{
	element * n = malloc(sizeof(element));
	n->value = object;
	n->next = s->l.first;
	s->l.first = n;
	s->length++;
}

int stack_empty(stack s)
{
	return s->length<=0? 1:0;
}

void * stack_top(stack s)
{
	if ( stack_empty(s) == 0 )
		return s->l.first->value;
	return NULL;
}

void stack_pop(stack s)
{
	if ( stack_empty(s) == 0 )
	{
		element * n = s->l.first->next;
		free(s->l.first);
		s->l.first = n;
		s->length--;
		//~ if ( s->last-s->length > 2*BLOCK )
			//~ stack_shrink(s);
	}
}
