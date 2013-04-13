#ifndef SPLAY_H
#define SPLAY_H

typedef int (*keyfunc)(void*);

typedef struct tree_t *tree;
struct tree_t{
  tree left;
  tree right;
  void * object;
};

typedef struct splay_t * splay;
struct splay_t{
  tree root;
  keyfunc f;
};


void splay_cheap_splay(splay m, int key);

void splay_splay(splay m, int key);

/* create an empty splay tree */
splay splay_create(keyfunc f);

/* find an object in the splay tree and return it or NULL if not found */
void * splay_find(splay m, int key);

/* insert an integer in a splay and return it or -1 in case of
   failure (integer already inside the splay) */
void * splay_insert(splay m, void* object);

/* delete an object from a splay and return it or -1 if not found */
void * splay_delete(splay m, int key);

splay splay_union(splay A, splay B);
splay splay_coupe(splay m, int key);

/* destroy the splay */
void splay_destroy(splay m);


/* dump the underlying binary research tree */
void splay_dump(splay m);


/****************************************/
void prof_splay_cheap_splay(splay m, int key);
void prof_splay_splay(splay m, int key);
splay prof_splay_create(keyfunc f);
void * prof_splay_find(splay m, int key);
void * prof_splay_insert(splay m, void* object);
splay prof_splay_coupe(splay A, int key);
void * prof_splay_delete(splay m, int key);
splay prof_splay_union(splay A, splay B);
void prof_splay_destroy(splay m);


#endif
