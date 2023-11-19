#include "monty.h"

/**
 * my_pop - Remove the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description: This function removes the top element from the stack. If
 * the stack is empty, it prints an error message to standard error, frees
 * allocated memory, and exits the program with a failure status.
 */
void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	 if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free(glob.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

    /* Set temp to point to the next node in the stack */
	temp = (*stack)->next;

    /* Free the memory allocated for the current top node of the stack */
	free(*stack);

    /* Update the head pointer to point to the new top node */
	*stack = temp;

    /* Update the prev pointer of the new top node to NULL */
    /* to indicate that it is now the top of the stack. */
	if (*stack != NULL)
	(*stack)->prev = NULL;
}

