#ifndef STACK_H
# define STACK_H

# include "../linkedlist/linkedlist.h"

/*
	Stack is a FIFO data structure that allows for the addition and removal of elements
*/

typedef t_linkedlist	Stack;

Stack					stack_init(t_generic value);
void					stack_add(Stack stack, t_generic value);
t_generic				stack_poll(Stack *stack);
void					stack_dealloc_element(Stack stack,
							t_deallocator dealloc);
void					stack_free(Stack *stack, void (*dealloc)(t_generic));

#endif