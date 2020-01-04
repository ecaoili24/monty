#include "monty.h"

/**
 * push - Pushes an item to the top of the stack
 * @num: The number to push
 */
void push(char *num)
{
	stack_t *new;

	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", gvar.lineNum);
		exit(EXIT_FAILURE);
	}

	checkNum(num);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(num);

	if (!gvar.stack)
	{
		new->next = NULL;
		new->prev = NULL;
		gvar.stack = new;
	}
	else
	{
		new->next = gvar.stack;
		new->prev = NULL;
		gvar.stack->prev = new;
		gvar.stack = new;
	}
}

/**
 * checkNum - checks if a string is a valid number
 * @str: The string to check
 */
void checkNum(char *str)
{
	int i = 0;

	if (num[0] == '-')
		i++;

	for (; num[i]; ++i)
	{
		if (!isdigit(num[i]))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
					gvar.lineNum);
			exit(EXIT_FAILURE);
		}
	}
}
