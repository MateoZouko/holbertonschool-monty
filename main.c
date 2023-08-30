#include "monty.h"

/**
 * get_func - Searches for a function that matches an operator
 * @op: Operator to search for
 *
 * Return: Returns a pointer to the corresponding function
 */
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};
	for (i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(func[i].opcode, op) == 0)
			return (func[i].f);
	}
	return (func[i].f);
}
/**
 * main - entry point for the Monty bytecode interpreter
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 *Return: 0 upon successful completion of the program
 */
int main(int argc, char **argv)
{
	char *line = NULL, *token = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *input_file = NULL;
	size_t line_size = 0;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	input_file = fopen(argv[1], "r");
	if (!input_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_size, input_file) != -1)
	{
		line_number++;
		token = strtok(line, DELIM);
		if (!token)
			continue;

		op_func = get_func(token);
		if (!op_func)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
		op_func(&stack, line_number);
	}
	fclose(input_file), free(token), free(stack);

	return (0);
}
