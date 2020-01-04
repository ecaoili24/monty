#include "monty.h"

/**
 * swap - Swaps the top two items on the stack
 * @stack: Double pointer to the head of the stack
 * @l: The number of the line currently being run
 */
void swap(stack_t **stack, unsigned int l)
{
	stack_t *nitem;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	nitem = (*stack)->next;
	(*stack)->next = nitem->next;
	nitem->next = (*stack);
	(*stack)->prev = nitem;
	nitem->prev = NULL;
	*stack = nitem;
}
