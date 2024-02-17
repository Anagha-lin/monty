#include "monty.h"

/**
 * my_push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number of the opcode in the Monty file.
 *
 * Description: This function pushes an integer element onto the stack.
 * If the argument is not a valid integer or not provided, it prints an error
 * message and exits the program with a failure status.
 */
void my_push(stack_t **stack, unsigned int line_number)
{
    int n;

    if (glob.arg == NULL || !is_number(glob.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_stack(*stack);
        fclose(glob.file);
        free(glob.line);
        exit(EXIT_FAILURE);
    }

    n = atoi(glob.arg);
    if (add_node(stack, n) == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        fclose(glob.file);
        free(glob.line);
        exit(EXIT_FAILURE);
    }
}

/**
 * my_pall - Print all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description: This function prints all the integer values stored
 * in the nodes of the stack.
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        (void)line_number;
    }
}

