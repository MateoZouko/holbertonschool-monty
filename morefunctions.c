#include "monty.h"

void
_swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}

