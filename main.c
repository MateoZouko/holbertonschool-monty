#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char line[100];
    unsigned int line_number = 1;
    int value;
    char *opcode;
    char *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n", argv[0]);
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error: Can't open file <file>");
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
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
                    return (EXIT_FAILURE);
                }

                value = atoi(arg);
                if (value == 0 && strcmp(arg, "0") != 0)
                {
                    printf("L%u: usage: push integer\n", line_number);
                    return (EXIT_FAILURE);
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
    return (EXIT_SUCCESS);
}
