#include "monty.h"

/**
 * pall_instruction - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file where the instruction appears.
 */
void pall_instruction(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; // Unused parameter

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

