#ifndef AVL_H
#define AVL_H
/* Header file for the avl abstract data type (avl.h) */

struct avl_t;

typedef struct avl_t *avl;

/* avl an integer key to an object pointer */
typedef int (*keyfunc)(void *);

/* create an empty avl */
avl avl_create(keyfunc f);

/* create an empty avl */
void avl_destroy(avl f);

/* create an empty avl */
int avl_height(avl f);

/* find an object in the avl and return it or NULL if not found */
void * avl_find(avl m, int key);

/* insert an object in a avl and return it or NULL in case of
   failure (NULL object or object already inside the avl) */
void * avl_insert(avl m, void * object);

/* delete an object from a avl and return it or NULL in not found */
void * avl_delete(avl m, int key);

/* dump the underlying binary research tree */
void avl_dump(avl m);

#endif
