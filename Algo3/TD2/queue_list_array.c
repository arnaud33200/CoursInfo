#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

const int BLOCK = 10;

struct element_t;
typedef struct element_t *element;

struct element_t
{
	element next;
	void ** tab;
	int back;
	int front;
};

struct queue_t
{
	element first;
	element last;
};

/* create an empty queue */
queue queue_create(void)
{
	queue new = malloc(sizeof(struct queue_t));
	new->first = NULL;
	new->last = NULL;
	return new;
}

/* create an empty queue */
void queue_destroy(queue s)
{
	element tmp = s->first;
	while (tmp != NULL)
	{
		free(tmp->tab);
		element n = tmp->next;
		free(tmp);
		tmp = n;
	}
	free(s);
}

/* return true if and only if the queue is empty */
int queue_empty(queue s)
{
	return s->first == NULL ? 1 : 0;
}

/* push an object on the back of the queue */
void queue_push(queue s, void *object)
{
	if( s->last == NULL || s->last->front >= BLOCK-1 )
	{
		element ne = malloc(sizeof(struct element_t));
		ne->tab = malloc(sizeof(void *) * BLOCK);
		ne->next = NULL;
		ne->back = 0;
		ne->front = 0;

		if( queue_empty(s) == 1 )
		{	
			s->last = ne;
			s->first = ne;
		}
		else
		{
			s->last->next = ne;
			s->last = ne;
		}
	}

	s->last->tab[s->last->front] = object;
	++s->last->front;
}


/* return the front element of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void * queue_front(queue s)
{
  return queue_empty(s) == 0 ? s->first->tab[s->first->back] : NULL;
}

/* pop the front element off of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void queue_pop(queue s)
{
	if( queue_empty(s) == 0)
	{
		++s->first->back;
		if(s->first->back >= BLOCK)
		{
			element tmp = s->first->next;
			free(s->first->tab);
			free(s->first);
			s->first = tmp;
		}
	}
}
