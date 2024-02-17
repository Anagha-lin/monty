#include "monty.h"

/**
 * push_instruction - Pushes an integer onto the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file where the instruction appears.
 */
void push_instruction(stack_t **stack, unsigned int line_number)
{
    int n, i = 0;
    char *arg = bus.arg;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if (arg[0] == '-')
        i++;

    while (arg[i] != '\0')
    {
        if (arg[i] < '0' || arg[i] > '9')
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    n = atoi(arg);

    if (bus.lifo == 0)
        push(stack, n);
    else
        enqueue(stack, n);
}

