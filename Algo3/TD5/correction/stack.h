/* Header file for the stack abstract data type (stack.h) */
#ifndef STACK_H
#define STACK_H 

struct stack_t;

typedef struct stack_t *stack;

/* create an empty stack */
stack stack_create(void);

/* push an object on a stack */
void stack_push(stack s, void *object);

/* return true if and only if the stack is empty */
int stack_empty(stack s);

/* return the top element of the stack.
   The stack must not be empty (as reported by stack_empty()) */
void * stack_top(stack s);

/* pop an element off of the stack.
   The stack must not be empty (as reported by stack_empty()) */
void stack_pop(stack s);

void stack_destroy(stack s);

#endif
