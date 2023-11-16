#include "monty.h"

/**
 * my_push - Pushes a value onto the stack.
 * @stack: A pointer to the head of the stack.
 * @counter_numb: The line number in the file.
 */
void my_push(stack_t **stack, unsigned int counter_numb)
{
	if (file_ptr->num_tokens <= 1 || !(my_check_digit_(file_ptr->tokens[1])))
	{
	fprintf(stderr, "L%d: usage: push integer\n", counter_numb);
	my_fclose_file();
	my_free_tokens();
	my_free_file_ptr();
	exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	my_fclose_file();
	my_free_tokens();
	my_free_file_ptr();
	exit(EXIT_FAILURE);
	}

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int)atoi(file_ptr->tokens[1]);

	if (file_ptr->head != NULL)
	{
	(*stack)->next = file_ptr->head;
	file_ptr->head->prev = *stack;
	}
	file_ptr->head = *stack;
}

