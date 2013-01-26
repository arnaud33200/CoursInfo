#include "stack.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>

const int BLOCK = 10;
void stack_grow(stack s);

struct element_t
{
	void ** value;
	int last;
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
	
	void ** v = malloc(sizeof(void*) * BLOCK);
	s->l.first = malloc(sizeof(element));
	s->l.first->value = v;
	s->l.first->last = -1;
	s->l.first->next = NULL;
	
	s->length = 0;
	return s;
}

void stack_grow(stack s)
{
	void ** v = malloc(sizeof(void*) * BLOCK);
	element * n = s->l.first;
	s->l.first = malloc(sizeof(element));
	s->l.first->value = v;
	s->l.first->last = -1;
	s->l.first->next = n;
}

void stack_push(stack s, void *object)
{
	if ( s->l.first->last >= BLOCK -1 )
		stack_grow(s);
	s->l.first->last++;
	s->l.first->value[s->l.first->last] = object;
	s->length++;
}

int stack_empty(stack s)
{
	return s->length<=0? 1:0;
}

void * stack_top(stack s)
{
	if ( stack_empty(s) == 0 )
		return s->l.first->value[s->l.first->last];
	return NULL;
}

void stack_pop(stack s)
{
	if ( stack_empty(s) == 0 )
	{
		s->l.first->value[s->l.first->last] = NULL;
		s->l.first->last--;
		s->length--;
		if ( s->l.first->last < 0 )
		{
			element * f = s->l.first->next;
			free(s->l.first);
			s->l.first = f;
		}
	}
}
