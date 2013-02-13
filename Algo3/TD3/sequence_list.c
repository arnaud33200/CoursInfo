#include<stdio.h>
#include<stdlib.h>

#include "sequence.h"

struct element_t;
typedef struct element_t * element;

struct element_t
{
	void * val;
	element next;	
};

struct sequence_t
{
	element first;
	element last;
	int size;		// number of case
	int length;		// number element added
};


/* create an empty sequence */
sequence sequence_create()
{
	sequence new = malloc(sizeof(struct sequence_t));
	new->first = NULL;
	new->last = NULL;
	new->size = 0;
	new->length = 0;
}

/* destroy the whole sequence (not objects)*/
void sequence_destroy(sequence s)
{
	element n = s->first;
	while( n != NULL)
	{
		sequence tmp = n;
		n = n->next;
		free(tmp);
	}
	free(s);
}

/* find the object at position pos and return it or NULL if not
   found */
void * sequence_find(sequence s, int pos)
{
	if( sequence_length(s) <= 0 )
		return NULL;
	int i=0;
	element n = s->first;
	int find = 0;
	while (n != NULL && find == 0)
	{
		if (i == pos )
			find = 1;
		else
			n = n->next;
		++i;
	}
	return n->val;
}

/* insert an object between objects at position pos-1 and pos */
void sequence_insert(sequence s, void * object, int pos)
{
	int size = s->size;
	int lenght = s->length;

	if ( s->size <= 0 )
	{
		element n = malloc(sizeof(struct element_t));
		s->first = n;
		s->last = n;
		++s->size;
	}

	if ( pos >= s->size )
	{
		int i = s->size-1;
		while ( i < pos )
		{
			element n = malloc(sizeof(struct element_t));
			s->last->next = n;
			s->last = n;
			++i;
			++s->size;
		}
		s->last->val = object;
	}
	else
	{
		int i = 0;
		element p = NULL;
		element n = s->first;
		while ( i < pos)
		{
			p = n;
			n = n->next;
			++i;
		}
		if (n->val == NULL ) // si case vide dù à un agrandissement
			n->val = object;
		else
		{
			element new = malloc(sizeof(struct element_t));
			new->val = object;
			new->next = n;
			if(p != NULL)	// cas ou pos == 0
				p->next = new;
			++s->size;
		}
		
	}

	++s->length;
}

/* delete the object at position pos */
void sequence_delete(sequence s, int pos)
{
	if ( sequence_length(s) == 0 || pos >= s->size )
		return;

	element p = NULL;
	element n = s->first;
	int i = 0;
	while ( i<pos )
	{
		p = n;
		n = p->next;
		++i;
	}
	p->next = n->next;
	free(n);
	--s->size;
	--s->length;
}

/* dump the sequence as integer object */
void sequence_dump(sequence s)
{
	element n = s->first;
	int i=0;
	while( n != NULL )
	{
		if ( n->val == NULL)
			printf(" %d[]-", i);
		else
			printf(" \033[01;31m%d[%s]\033[00m-", i, n->val);

		n = n->next;
		++i;
	}
	printf("\n\n");
}

/* return the sequence length */
int sequence_length(sequence s)
{
	return s->length;
}
