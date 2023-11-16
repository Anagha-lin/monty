#include "monty.h"

/**
 *my_pint - prints value at the head_stack
 *
 * @head_stack: a ptr to the head_stack struct
 * @counter_numb: the line num of each line in the file
 */

void my_pint(stack_t **head_stack, unsigned int counter_numb)
{
	stack_t *the_current;
	(void) *head_stack;

	the_current = file_ptr->head;
	if (the_current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, head_stack empty\n", counter_numb);
		my_fclose_file();
		my_free_tokens();
		my_free_file_ptr();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", the_current->n);
}
