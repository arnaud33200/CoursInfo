#ifndef LIST_H
#define LIST_H

struct element_t
{
	void * value;
	element * next;
};

struct list_t
{
	element * first;
};

typedef struct element_t element;
typedef struct list_t list;


#endif // LIST_H
