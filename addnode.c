#include "monty.h"
#include <stdio.h>

/**
 * my_addnode - Adds a node to the head of the stack.
 * @head: Head of the stack.
 * @n: New value.
 * Return: No return.
 */
void my_addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error\n");
	exit(EXIT_FAILURE);
	}

	if (aux)
	aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

