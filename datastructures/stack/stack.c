#include "stack.h"
#include <stdlib.h>

#define STACK_EMPTY (Stack)0

inline Stack	stack_init(t_generic value)
{
	return (Stack)(linkedList_init(value));
}

/**
 * @brief adds a value on top of the stack
 *
 * @param stack
 * @param value
 */
inline void	stack_add(Stack stack, t_generic value)
{
	linkedList_push((t_linkedlist *)&stack, value);
}

/**
 * @brief removes the top value from the stack
 *
 * @param stack
 * @param dealloc
 * @note does not deallocate the value, call stack_dealloc_element
 * @return Generic
 */
t_generic	stack_poll(Stack *stack)
{
	t_generic	out;

	if (!stack)
		return (GENERIC_NULL);
	out = linkedlist_getinfo(*stack);
	*stack = linkedlist_getnext(*stack);
	return (out);
}

/**
 * @brief deallocates the stack element
 *
 * @param stack
 * @param dealloc
 */
void	stack_dealloc_element(Stack stack, t_deallocator dealloc)
{
	if (!stack)
		return ;
	if (dealloc)
		dealloc(stack->info);
	free(stack);
}

inline void	stack_free(Stack *stack, void (*dealloc)(t_generic))
{
	linkedlist_dealloc(*stack, dealloc);
}