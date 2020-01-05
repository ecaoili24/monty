#include "monty.h"

/**
 * to_stack - Sets the mode to stack (default)
 * @stack: Double pointer to the head of the stack (or queue)
 * @l: The current line number being run
 */
void to_stack(stack_t **stack, unsigned int l)
{
	(void)(stack);
	(void)(l);
	gvar.isStack = 1;
}

/**
 * to_queue - Sets the mode to queue
 * @stack: Double pointer to the head of the stack (or queue)
 * @l: The current line number being run
 */
void to_queue(stack_t **stack, unsigned int l)
{
	(void)(stack);
	(void)(l);
	gvar.isStack = 0;
}
