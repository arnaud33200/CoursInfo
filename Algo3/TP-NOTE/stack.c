#include<stdlib.h>
#include"stack.h"


struct stack_t{
  void* *tab;
  int nb_elements;
  int size;
};

/* create an empty stack */
stack stack_create(void){
  stack s= malloc(sizeof(*s));

  s->tab = malloc(10*sizeof(void*));
  s->size= 10;
  s->nb_elements=0;

  return s;
}

void stack_destroy(stack s){
  free(s->tab);
  free(s);
}

void* *resize(void* *tab, int size){
  void* *newTab=malloc(2*size*sizeof(void*));

  int i;
  for(i=0; i<size; i++)
    newTab[i]=tab[i];
  free(tab);
  return newTab;
}

/* push an object on a stack */
void stack_push(stack s, void *object){
  if(s == NULL)
    return;

  if(s->nb_elements == s->size){
    s->tab=resize(s->tab, s->size);
    s->size *=2;
  }

  s->tab[s->nb_elements]=object;
  s->nb_elements++;
}

/* return true if and only if the stack is empty */
int stack_empty(stack s){
  if(s == NULL)
    return 0;

  return(s->nb_elements == 0);
}

/* return the top element of the stack.
   The stack must not be empty (as reported by stack_empty()) */
void * stack_top(stack s){
  if(s == NULL)
    return NULL;

  if(stack_empty(s))
    return NULL;

  return s->tab[s->nb_elements-1];
}

/* pop an element off of the stack.
   The stack must not be empty (as reported by stack_empty()) */
void stack_pop(stack s){
  if(s == NULL)
    return;

  if(stack_empty(s))
    return;

  s->nb_elements--;
}
