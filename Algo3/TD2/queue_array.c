#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

const int BLOCK = 10;
void queue_grow(queue s);

struct queue_t
{
	void ** tab;
	int back;
	int front;
	int lenght;
	int nbElement;
};

void queue_grow(queue s)
{
	int ns = s->lenght * 2;
	void ** newtab = malloc(sizeof(void *) * ns);
	int i;
	for(i=0; i<ns; i++)
		newtab[i] = s->tab[i];
	void ** old = s->tab;
	
}

/* create an empty queue */
queue queue_create(void)
{
	queue s = malloc(sizeof(queue));
	s->tab = malloc(sizeof(void *)*BLOCK);
	s->back = s->front = 0;
	s->lenght = BLOCK;
	s->nbElement = 0;
	return s;
}

void queue_destroy(queue s)
{
	free(s->tab);
	free(s);
}

/* return true if and only if the queue is empty */
int queue_empty(queue s)
{
  return nbElement <= 0 ? 1 : 0;
}

/* push an object on the back of the queue */
void queue_push(queue s, void *object)
{
	if( s->nbElement >= s->lenght )
		grow
}


/* return the front element of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void * queue_front(queue s){
  return NULL;
}

/* pop the front element off of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void queue_pop(queue s){
}
