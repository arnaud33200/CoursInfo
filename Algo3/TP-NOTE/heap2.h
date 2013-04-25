#ifndef HEAP_H
#define HEAP_H

typedef int (*keyfunc)(void*);

typedef struct tree_t *tree;

struct tree_t{
  tree left;
  tree right;
  void * object;
};

typedef struct heap_t * heap;
struct heap_t{
  tree root;
  keyfunc f;
};


/* create an empty heap tree */
heap heap_create(keyfunc f);

/* destroy the heap */
void heap_destroy(heap h);

/* insert an element in the heap or NULL if object is NULL */
heap heap_insert(heap h, void* object);

/* get the element of minimum weight of NULL in case of empty heap */
void* heap_get_min(heap h);

/* removes the element of minimum weight or does nothing in case of empty heap */
heap heap_remove_min(heap h);

/* return a heap which contains all the elements of A and B and destroys A and B in the process*/
heap heap_merge(heap A, heap B);

/* dump the underlying binary research tree */
void heap_dump(heap h);

/****************************************************/
heap prof_heap_create(keyfunc f);
void prof_heap_destroy(heap h);
heap prof_heap_insert(heap h, void* object);
void* prof_heap_get_min(heap h);
heap prof_heap_remove_min(heap h);
heap prof_heap_merge(heap A, heap B);
void prof_heap_dump(heap h);


#endif
