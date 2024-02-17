#include "monty.h"

/**
 * my_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description: This function swaps the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits the program with a failure status.
 */
void my_swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free(glob.line);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Swap the values of the top two elements */
    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

