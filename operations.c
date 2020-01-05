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
	(*stack)->n = sum;
}

/**
 * sub - the opcode that subtracts the top element of the stack from the second
 * top element of the stack.
 * @stack: double pointer to the head of the stack
 * @l: the line number currently being run
 */
void sub(stack_t **stack, unsigned int l)
{
	int x, y, difference;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;

	difference = y - x;

	pop(stack, l);
	(*stack)->n = difference;
}

/**
 * divide - The opcode div, divides the second top element of the stack by the
 * top element of the stack.
 * @stack: double pointer to the head of the stack
 * @l: the line number currently being run
 */
void divide(stack_t **stack, unsigned int l)
{
	int x, y, quotient;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;

	if (x == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	quotient = y / x;

	pop(stack, l);

	(*stack)->n = quotient;
}
/**
 * mul - the opcode mul, multiplies the the second top element of the stack
 * with the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @l: the line number currently being run
 */
void mul(stack_t **stack, unsigned int l)
{
	int x, y, product;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;
	product = x * y;

	pop(stack, l);

	(*stack)->n = product;
}
/**
 * mod - mod computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @l: the line number currently being run
 */
void mod(stack_t **stack, unsigned int l)
{
	int x, y, mod;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;

	if (x == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", l);
		cleanup();
		exit(EXIT_FAILURE);
	}

	mod = y % x;

	pop(stack, l);

	(*stack)->n = mod;
}
