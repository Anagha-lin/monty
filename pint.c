#include "monty.h"

/**
 * my_pint - Print the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description: This function prints the integer value stored at the top
 * of the stack. If the stack is empty, it prints an error message to
 * standard error, frees allocated memory, and exits the program with a
 * failure status.
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free(glob.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

