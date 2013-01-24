#include "stack.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>

const int BLOCK = 10;
void stack_grow(stack s);


struct stack_t
{
	list l;
	int length;
	int last;
};

/* create an empty stack */
stack stack_create(void)
{
	stack s = malloc(sizeof(stack));
	
	element * f;
	int i=0;
	for (i; i<BLOCK; i++)
	{
		
	}
	
	s->length = BLOCK;
	s->last = -1;
	return s;
}

void stack_push(stack s, void *object)
{
	if(s->last == s->length - 1)
		stack_grow(s);
	s->last++;
	s->array[s->last] = object;
}

void stack_grow(stack s)
{
	int i;
	int ns = s->length * 2;
	void ** na = malloc(sizeof(void*) * ns);
	for(i=0; i<s->length; i++)
		na[i] = s->array[i];
	free(s->array);
	
	s->array = na;
	s->length = ns;
}

int stack_empty(stack s)
{
	return s->last<0? 1:0;
}

void * stack_top(stack s)
{
	if ( stack_empty(s) == 0 )
		return s->array[s->last];
	return NULL;
}

void stack_pop(stack s)
{
	if ( stack_empty(s) == 0 )
	{
		s->array[s->last] = NULL;
		s->last--;
		//~ if ( s->last-s->length > 2*BLOCK )
			//~ stack_shrink(s);
	}
}
