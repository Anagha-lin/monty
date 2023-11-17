#include "monty.h"
#include <stdio.h>

/**
 * my_pall - Prints the elements of the stack.
 * @head: Stack head.
 * @counter: Unused parameter.
 * Return: No return.
 */
void my_pall(stack_t **head, unsigned int counter)
{
    stack_t *current;
    (void)counter;

    current = *head;

    if (current == NULL)
        return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

