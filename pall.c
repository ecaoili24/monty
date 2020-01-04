#include "monty.h"

/**
 * pall - Prints all items on the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The current line numer being processed
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *item;

	(void)(lineNum);

	if (!stack)
		return;

	for (item = *stack; item; item = item->next)
		printf("%d\n", item->n);
}
