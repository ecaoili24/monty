#include "monty.h"

/**
 * pint - Prints the int at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The number of the current line being processed
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", lineNum);
		cleanup();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
