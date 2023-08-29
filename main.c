#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number being processed.
 *
 * Description: This function adds a new integer element to the top of the stack.
 * If the value provided is not a valid integer, an error message is displayed.
 */

void push(stack_t **stack, unsigned int line_number)
{
    int value;

    if (scanf("%d", &value) == 1)
    {
        stack_t *new_Node = malloc(sizeof(stack_t));
        if (!new_Node)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        new_Node->n = value;
        new_Node->prev = NULL;
        new_Node->next = *stack;

        if (*stack != NULL)
        {
            (*stack)->prev = new_Node;
        }

        *stack = new_Node;
    }
    else
    {
        fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}

/**
 * pall - Prints all elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number being processed.
 *
 * Description: This function prints all the integer elements in the stack,
 * starting from the top. If the stack is empty, nothing is printed.
 * Each element is printed on a new line.
 */

void pall( stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

