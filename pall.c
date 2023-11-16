#include "monty.h"

/**
 * my_pall - prints all the values on the head_stack, starting
 * from the top of the head_stack
 * @stack: stack head
 * @counter_numb: not used
 * Return: no return
 */
void my_pall(stack_t **stack, unsigned int counter_numb)
{
	stack_t *h;
	(void)counter_numb;

	h = *stack;
	if (h == NULL)
	return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

