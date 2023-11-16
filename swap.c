#include "monty.h"

/**
 * my_swap - Swaps the values of the top two elements on the stack.
 * @stack:  A pointer to the head of the stack.
 * @counter_numb: The line number in the file.
 */
void my_swap(stack_t **stack, unsigned int counter_numb)
{
	stack_t *temp_node = NULL;
	int temp_value;

	(void) *stack;

	if (file_ptr->head == NULL || file_ptr->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter_numb);
		my_fclose_file();
		my_free_tokens();
		my_free_file_ptr();
		exit(EXIT_FAILURE);
	}

	temp_node = file_ptr->head;
	temp_value = temp_node->n;
	temp_node->n = temp_node->next->n;
	temp_node->next->n = temp_value;
}

