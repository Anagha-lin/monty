#include "monty.h"

/**
 * my_rotl - Rotates the stack to the top.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void my_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *current = *head, *aux;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    aux = (*head)->next;
    aux->prev = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;
    (*head)->next = NULL;
    (*head)->prev = current;
    (*head) = aux;
}

