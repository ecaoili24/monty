#include "monty.h"

/**
 * pchar - Prints the top item of the stack as a character
 * @stack: Double pointer to the head of the stack
 * @l: The line number currently being run
 */
void pchar(stack_t **stack, unsigned int l)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	if (!isascii((*stack)->n))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
