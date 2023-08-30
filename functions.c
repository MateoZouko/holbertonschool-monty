#include "monty.h"

/**
 * _push - Adds a new node at the beginning of a stack_t stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *token = strtok(NULL, DELIM);
	stack_t *line;
	int n2 = 0;

	line = malloc(sizeof(stack_t));
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!token || isdigit(token) == 0 || !stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n2 = atoi(token);

	line->n = n2;
	line->prev = NULL;
	line->next = *stack;

	if (line->next != NULL)
	{
		(line->next)->prev = line;
	}
	*stack = line;
}

/**
 * _pall - prints all the elements in the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty bytecodes file
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *line = *stack;
	(void)line_number;
	while (line)
	{
		printf("%d\n", line->n);
		line = line->prev;
	}
}
