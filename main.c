#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char line[100];
    unsigned int line_number = 1;

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';

        char *opcode = strtok(line, " ");
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, " ");
                if (arg == NULL)
                {
                    printf("L%u: usage: push integer\n", line_number);
                    return (EXIT_FAILURE);
                }

                int value = atoi(arg);
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
