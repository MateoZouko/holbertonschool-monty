#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 1;
	int value;
	char *opcode;
	char *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: montyfile file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &line_size, file) != -1)
	{
		line[strcspn(line, "\n")] = '\0';

		opcode = strtok(line, " ");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				arg = strtok(NULL, " ");
				if (arg == NULL)
				{
					printf("L%u: usage: push integer\n", line_number);
					continue;
				}

				value = atoi(arg);
				if (value == 0 && strcmp(arg, "0") != 0)
				{
					printf("L%u: usage: push integer\n", line_number);
					continue;
				}

				push(&stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_number);
			}
		}

		line_number++;
	}

	fclose(file);
	if (line)
		free(line);
	return (EXIT_SUCCESS);
}
