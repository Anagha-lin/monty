#include "monty.h"

/**
 * my_pop - Removes the top element of the stack.
 * @stack: A pointer to the head of the stack.
 * @counter_numb: The line number in the file.
 */
void my_pop(stack_t **stack, unsigned int counter_numb)
{
	stack_t *temp;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", counter_numb);
	my_fclose_file();
	my_free_tokens();
	my_free_file_ptr();
	exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	(*stack)->prev = NULL;

	free(temp);
}

