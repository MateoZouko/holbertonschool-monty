#include "monty.h"

void
_push(stack_t **stack, unsigned int line_number)
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
	if (!token || _digit(token) == 0 || !stack)
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

void
_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *line = *stack;
	(void)line_number;
	while (line)
	{
		printf("%d\n", line->n);
		line = line->next;
	}
}

/**
 *	_pint - prints the value at the top of the stack
 *	@stack: doble pointer to the head of the stack
 *	@line_number: line number of the opcode in the Monty bytecodes file
 *	Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *line = *stack;
	(void)line_number;
	printf("%d\n", line->n);
}

