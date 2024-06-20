#include "Stack.h"

#define STACK_EMPTY (Stack)0

inline Stack	stack_init(Generic value)
{
	return (Stack)(LinkedList_Init(value));
}

/**
 * @brief adds a value on top of the stack
 *
 * @param stack
 * @param value
 */
inline void	stack_add(Stack stack, Generic value)
{
	LinkedList_Push((LinkedList *)&stack, value);
}

/**
 * @brief removes the top value from the stack
 *
 * @param stack
 * @param dealloc
 * @note does not deallocate the value, call stack_dealloc_element
 * @return Generic
 */
Generic	stack_poll(Stack *stack)
{
	Generic	out;

	if (!stack)
		return (GENERIC_NULL);
	out = LinkedList_GetInfo(*stack);
	*stack = LinkedList_GetNext(*stack);
	return (out);
}

/**
 * @brief deallocates the stack element
 *
 * @param stack
 * @param dealloc
 */
void	stack_dealloc_element(Stack stack, Deallocator dealloc)
{
	if (!stack)
		return ;
	if (dealloc)
		dealloc(stack->info);
	free(stack);
}

inline void	stack_free(Stack *stack, void (*dealloc)(Generic))
{
	LinkedList_Dealloc(*stack, dealloc);
}