#include "monty.h"

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
