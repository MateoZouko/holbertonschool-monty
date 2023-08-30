#include "monty.h"

int
_digit(char string[])
{
	int i;

	if (string[0] == '-')
		string[0] = '0';
	for (i = 0; string[i]; i++)
	{
		if (isdigit(string[i]) == 0)
			return (0);
	}
	return (1);
}

void
frees(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void
_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(tmp);
		*stack = NULL;
	}
	tmp = (*stack)->next;
}

