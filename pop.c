#include "monty.h"
#include <stdio.h>

/**
 * my_pop - Removes the top element of the stack.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void my_pop(stack_t **head, unsigned int counter)
{
    stack_t *current;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(bus.file);
        free(bus.content);
        my_free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    *head = current->next;
    free(current);
}

