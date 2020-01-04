#include "monty.h"

void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *item;

	(void)(lineNum);

	if (!stack)
		return;

	for (item = *stack; item; item = item->next)
		printf("%d\n", item->n);
}
