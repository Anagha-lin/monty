#include "monty.h"
#include <stdio.h>

/**
 * my_add - Adds the top two elements of the stack.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void my_add(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int len = 0, result;

    current = *head;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    result = current->n + current->next->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}

