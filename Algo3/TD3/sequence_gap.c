#include<stdio.h>
#include<stdlib.h>

#include "sequence.h"

const int BLOCK = 10;
int first_empty_slot_after(sequence s, int pos);
void grow_array(sequence s);


struct sequence_t
{
	void ** tab;
	int d;
	int f;
	int length;
	int size;
};

/* create an empty sequence */
sequence sequence_create()
{
	sequence new = malloc( sizeof(struct sequence_t));
	new->tab = malloc(sizeof(void *) * BLOCK);
	for (int i = 0; i < new->size; ++i)
		new->tab[i] = NULL;
	new->length = 0;
	new->size = BLOCK;
}

/* destroy the whole sequence (not objects)*/
void sequence_destroy(sequence s)
{
	free(s->tab);
	free(s);
}

/* find the object at position pos and return it or NULL if not
   found */
void * sequence_find(sequence s, int pos);

/* insert an object between objects at position pos-1 and pos */
void sequence_insert(sequence s, void * object, int pos);

/* delete the object at position pos */
void sequence_delete(sequence s, int pos);

/* dump the sequence as integer object */
void sequence_dump(sequence s);

/* return the sequence length */
int sequence_length(sequence s);