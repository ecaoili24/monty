#include "monty.h"

/**
 * rotl - The opcode rotl rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @l: The line number currently being run
 */
void rotl(stack_t **stack, unsigned int l)
{
	int temp;
	stack_t *new = *stack, *next;

	(void)l;

	if (new)
	{
		next = new->next;
		temp = new->n;

		while (new->next)
		{
			new->n = next->n;
			new = next;
			next = new->next;
		}
		new->n = temp;
	}
}
