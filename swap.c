#include "monty.h"
#include <stdio.h>

/**
 * my_swap - Swaps the top two elements of the stack.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void my_swap(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int len = 0, temp;

    current = *head;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        my_free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}

