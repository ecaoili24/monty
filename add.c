#include "monty.h"

/**
 * add - Pops the top two items from the stack and pushes their sum
 * @stack: Double pointer to the head of the stack
 * @l: The line number currently being run
 */
void add(stack_t **stack, unsigned int l)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, l);
	pop(stack, l);
	pushInt(sum);
}
