#include "monty.h"

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

int main(int argc, char *argv[])
{
    
}