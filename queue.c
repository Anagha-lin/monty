#include "monty.h"

/**
 * my_queue - Sets the queue mode.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void my_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * my_addqueue - Adds a node to the tail of the stack.
 * @n: New value.
 * @head: Head of the stack.
 * Return: No return.
 */
void my_addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }

    if (!aux)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        aux->next = new_node;
        new_node->prev = aux;
    }
}

