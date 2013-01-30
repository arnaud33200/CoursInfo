#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct element_t;
typedef struct element_t * element;

struct element_t
{
	void * value;
	element next;
};

struct queue_t
{
	element first;
	int lenght;
};

/* create an empty queue */
queue queue_create(void)
{
	queue q = malloc(sizeof(queue));
	q->first = NULL;
	q->lenght = 0;
	return q;
}

/* make a queue empty and destroy it */
void queue_destroy(queue s)
{
	element n = s->first;
	while ( n != NULL )
	{
		element o = n;
		n = o->next;
		free(o);
	}
	free(s);
}

/* return true if and only if the queue is empty */
int queue_empty(queue s)
{
	return s->lenght<=0 ? 1 : 0;
}

/* push an object on the back of the queue */
void queue_push(queue s, void *object)
{
	element new = malloc(sizeof(element));
	new->value = object;
	new->next = NULL;
	
	if ( queue_empty(s) == 1 )
		s->first = new;
	else
	{
		element cur = s->first;
		element nex = s->first->next;
		while ( nex != NULL )
		{
			cur = nex;
			nex = cur->next;
		}
		cur->next = new;
	}
	s->lenght++;	
}


/* return the front element of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void * queue_front(queue s)
{
	return queue_empty(s) == 1 ? NULL : s->first->value;
}

/* pop the front element off of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void queue_pop(queue s)
{
	element n = s->first->next;
	free(s->first);
	s->first = n;
}
