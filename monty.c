#include "monty.h"

gvar_t gvar;

/**
 * main - Main function the program enters in
 * @argc: The number of arguments passed to the program
 * @argv: Pointer to array of pointers each pointing to an argument passed to
 * the program
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	gvar.stack = NULL;
	gvar.line = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	process();
	cleanup(gvar.stack, gvar.file);
	return (0);
}

/**
 * openfile - Opens the monty file passed by the user
 * @name: The name of the file
 */
void openfile(char *name)
{
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	gvar.file = file;
}

/**
 * process - processes the monty file line by line
 */
void process(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;

	while ((read = getline(&gvar.line, &len, gvar.file)) != -1)
	{
		gvar.lineNum++;

		opcode = strtok(gvar.line, " \t\n");
		if (!opcode)
			continue;

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			runopcode(opcode, gvar.lineNum);
	}
}

/**
 * runopcode - Runs a given opcode, unless it is invalid
 * @opcode: The opcode to run
 * @lineNum: The line number the opcode is on
 */
void runopcode(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&gvar.stack, lineNum);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lineNum, opcode);
	cleanup(gvar.stack, gvar.file);
	exit(EXIT_FAILURE);
}

/**
 * cleanup - Function to clean up stack and file
 * @stack: Pointer to the stack
 * @f: Pointer to the open file
 */
void cleanup(stack_t *stack, FILE *f)
{
	stack_t *item;

	while (stack)
	{
		item = stack->next;
		free(stack);
		stack = item;
	}

	free(gvar.line);

	fclose(f);
}
