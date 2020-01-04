#include "monty.h"
#define UNUSED __attribute__((unused))

void parse(char *fileName, stack_t **head UNUSED)
{
	FILE *fp;
	char *line = NULL, *op;
	size_t len = 0;
	unsigned int lineNum = 1;
	ssize_t read;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
/*dropnl(line);*/
		lineNum++;
		op = strtok(line, " \t\n");
		if (op != NULL)
			exe_operation(op, head, lineNum);
	}

	fclose(fp);
	if (line)
		free(line);
}

void drop_newLine(char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		if (src[i] == '\n')
		{
			*(src + i) = '\0';
			return;
		}
	}
}
