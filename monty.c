#include "monty.h"

gvar_t gvar;

int main(int argc, char **argv)
{
	gvar.stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	process();
	/** TODO: Cleanup **/
	return (0);
}

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

void process(void)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL;
	char *opcode;

	while ((read = getline(&line, &len, gvar.file)) != -1)
	{
		gvar.lineNum++;

		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			runopcode(opcode, gvar.lineNum);
	}
}

void runopcode(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
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
	exit(EXIT_FAILURE);
}
