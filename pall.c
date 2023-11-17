#include "monty.h"

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

