#include "monty.h"
/**
 * my_pall - prints a stack
 * @head: stack head
 * @counter: not used
 * Return: no return
*/
void my_pall(stack_t **stack, unsigned int counter_numb);
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
