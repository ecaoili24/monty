#include "monty.h"

/**
 * pstr - Prints stack values as a string
 * @stack: Double pointer to the top of the stack
 * @l: The line number currently running
 */
void pstr(stack_t **stack, unsigned int l)
{
	stack_t *s = *stack;

	(void)(l);

	while (s && s->n && isascii(s->n))
	{
		printf("%c", s->n);
		s = s->next;
	}
	printf("\n");
}
