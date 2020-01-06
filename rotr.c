#include "monty.h"

/**
 * rotr - The opcode rotr rotates the stack to the bottom
 * @stack: pointer to the head of the list
 * @l: line number of instruction
 */
void rotr(stack_t **stack, unsigned int l)
{
	int temp;
	stack_t *new = *stack, *prev;

	(void)l;

	if (new)
	{
		while (new->next)
			new = new->next;
		prev = new->prev;
		temp = new->n;
		while (new->prev)
		{
			new->n = prev->n;
			new = prev;
			prev = new->prev;
		}
		new->n = temp;
	}
}
