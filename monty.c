#include "header.h"

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

		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else if (strcmp(opcode, "pall") == 0)
			pall(&gvar.stack, gvar.lineNum);
	}
}
