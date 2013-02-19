#include<stdio.h>
#include<stdlib.h>

#include "sequence.h"

const int BLOCK = 10;
void grow_array(sequence s);
int real_position(sequence s, int pos);


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
	new->d = 0;
	new->f = BLOCK-1;
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
	return s->tab[pos+(s->f-s->d+1)];
}

/* insert an object between objects at position pos-1 and pos */
void sequence_insert(sequence s, void * object, int pos)
{
	if( s->size <= sequence_length(s) )
		grow_array(s);
	int rp = real_position(s, pos);

	if (sequence_length(s) <= 0)
	{
		rp = 0;
		s->d = 1;
	}

	else if( s->f <= rp )
	{
		for (int i = s->f+1; i <= rp; ++i)
		{
			s->tab[s->d] = s->tab[i];
			++s->d;
		}
		s->f = rp-1;
	}
	else if( s->d >= rp )
	{
		for (int i = s->d-1; i >= rp; --i)
		{
			s->tab[s->f] = s->tab[i];
			--s->f;
		}
		s->d = rp+1;
	}
	else
	{
		printf("ERROR dans la position\n");
		exit(1);
	}
	s->tab[rp] = object;
	s->length++;
}

/* delete the object at position pos */
void sequence_delete(sequence s, int pos)
{
	if( sequence_length(s) <= 0 )
		return;

	int rp = real_position(s, pos);
	if(rp < s->d)
	{
		for (int i = s->d-1; i > rp; --i)
		{
			s->tab[s->f] = s->tab[i];
			--s->f;
		}
		s->d = rp;
	}
	else if( s->f <= rp )
	{
		for (int i = s->f+1; i < rp; ++i)
		{
			s->tab[s->d] = s->tab[i];
			++s->d;
		}
		s->f = rp;
	}
	else if( s->length >= s->size)
	{
		s->d = pos;
		s->f = pos;
	}

	s->tab[rp] = NULL;
	--s->length;

}

/* dump the sequence as integer object */
void sequence_dump(sequence s)
{
	for (int i = 0; i < s->size; ++i)
	{
		if( i >= s->d && i <= s->f)
			printf(" \033[01;32m%d[-]\033[00m-", i);
		else if ( s->tab[i] == NULL)
			printf(" %d[]-", i);
		else
			printf(" \033[01;34m%d[%s]\033[00m-", i, s->tab[i]);
	}
	// printf(" | d:%d et f:%d\n\n", s->d, s->f);
	printf("\n\n");
}

/* return the sequence length */
int sequence_length(sequence s)
{
	return s->length;
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

	s->d = s->size;
	s->f = ns-1;
	s->size = ns;

	printf("~~ The table has been grow !\n");
}

int real_position(sequence s, int pos)
{
	int ecart = s->f - s->d + 1;
	if(pos < s->d)
		return pos;
	else
		return pos+ecart;
}