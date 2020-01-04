#include "monty.h"

void push(char *num)
{
	int i = 0;
	stack_t *new;

	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", gvar.lineNum);
		exit(EXIT_FAILURE);
	}

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
