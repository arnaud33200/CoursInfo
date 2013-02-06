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
	for(i=0; i<=s->back; i++)
		newtab[i] = s->tab[i];

// si il reste encore un morceau de l'ancien tableau
// copier le reste à la fin du nouveau tableau
	if ( s->front > s-> back )
	{
		int p = ns - s->lenght;
		for(i=s->front; i<s->lenght; i++)
			newtab[i+p] = s->tab[i];
	}
	
	free(s->tab);
	s->tab = newtab;
	s->lenght = ns;
	printf("~~ The table has been grow !\n");
}

/* create an empty queue */
queue queue_create(void)
{
	queue s = malloc(sizeof(struct queue_t));
	s->tab = malloc(sizeof(void *)*BLOCK);
	s->back = 0;
	s->front = 0;
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
  return s->nbElement <= 0 ? 1 : 0;
}

/* push an object on the back of the queue */
void queue_push(queue s, void *object)
{
	if( s->nbElement >= s->lenght )
		queue_grow(s);

	s->tab[s->back] = object;
	++s->back;
	if(s->back >= s->lenght)
		s->back = 0;
	
	++s->nbElement;
}


/* return the front element of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void * queue_front(queue s)
{
  return queue_empty(s) == 0 ? s->tab[s->front] : NULL;
}

/* pop the front element off of the queue.
   The queue must not be empty (as reported by queue_empty()) */
void queue_pop(queue s)
{
	if( queue_empty(s) == 0 )
	{
		++s->front;
		if ( s->front >= s->lenght)
			s->front = 0;
		--s->nbElement;
	}
	else
		printf("## Pop impossible : table is empty\n");
}
