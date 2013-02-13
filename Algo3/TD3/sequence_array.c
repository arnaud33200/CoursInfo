#include<stdio.h>
#include<stdlib.h>

#include "sequence.h"

const int BLOCK = 10;
int first_empty_slot_after(sequence s, int pos);
void grow_array(sequence s);


struct sequence_t
{
	void ** tab;
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
void * sequence_find(sequence s, int pos)
{
	return sequence_length(s) <= 0 ? NULL : s->tab[pos]; 
}

/* insert an object between objects at position pos-1 and pos */
void sequence_insert(sequence s, void * object, int pos)
{
	if ( sequence_length(s) >= s->size || pos >= s->size )
		grow_array(s);

	if ( s->tab[pos] == NULL )
		s->tab[pos] = object;
	else
	{
		int nulpos = first_empty_slot_after(s, pos);
		if( nulpos == -1 )
		{
			nulpos = s->size;
			grow_array(s);
		}
		for (int i = nulpos; i>pos; --i)
			s->tab[i] = s->tab[i-1];
		s->tab[pos] = object;
	}

	++s->length;
}

/* delete the object at position pos */
void sequence_delete(sequence s, int pos)
{
	if( sequence_length(s) > 0)
	{
		s->tab[pos] = NULL;
		--s->length;
	}
}

/* dump the sequence as integer object */
void sequence_dump(sequence s)
{
	for (int i = 0; i < s->size; ++i)
	{
		if ( s->tab[i] == NULL)
			printf(" %d[]-", i);
		else
			printf(" \033[01;34m%d[%s]\033[00m-", i, s->tab[i]);
	}
	printf("\n\n");
}

/* return the sequence length */
int sequence_length(sequence s)
{
	return s->length;
}

// cherche la première case vide après une position
// retourne -1 si aucune case vide
int first_empty_slot_after(sequence s, int pos)
{
	int find = 0;
	int nulpos = -1;
	int i = pos;
	while ( find == 0 && i < s->size )
	{
		if ( s->tab[i] == NULL )
		{
			find = 1;
			nulpos = i;
		}
		++i;
	}
	return nulpos;
}

void grow_array(sequence s)
{
	int ns = s->size * 2;
	void ** newtab = malloc(sizeof(void *) * ns);
	int i;
	for(i=0; i<=s->size; i++)
		newtab[i] = s->tab[i];
	
	free(s->tab);
	s->tab = newtab;

	for (int i = s->size; i < ns; ++i)
		s->tab[i] = NULL;

	s->size = ns;


	printf("~~ The table has been grow !\n");
}