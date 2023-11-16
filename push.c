#include "monty.h"

/**
 * my_push - prints all the values on the head_stack, starting
 * from the top of the head_stack
 * @head_stack: the stack head
 * @counter_numb: the line number of each line in the file
 */

void my_push(stack_t **head_stack, unsigned int counter_numb)
{
	if (file_ptr->num_tokens <= 1 || !(check_digit_(file_ptr->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter_numb);
		my_fclose_file();
		my_free_tokens();
		my_free_file_ptr();
		exit(EXIT_FAILURE);
	}
	/*printf("in push DEBUG: Token[1]: %s\n", file_ptr->tokens[1]);*/
	*head_stack = malloc(sizeof(stack_t));
	if (*head_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		my_fclose_file();
		my_free_tokens();
		my_free_file_ptr();
		exit(EXIT_FAILURE);
	}

	(*head_stack)->next = (*head_stack)->prev = NULL;
	(*head_stack)->n = (int) atoi(file_ptr->tokens[1]);
	if (file_ptr->head != NULL)
	{
		(*head_stack)->next = file_ptr->head;
		file_ptr->head->prev = *head_stack;
	}
	file_ptr->head = *head_stack;
}

/**
 * my_check_digit_ - checks if a string is a digit
 * @str: the string o check
 * Return: 0 on success
 */

int my_check_digit_(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		if (a == 0 && str[a] == '-' && str[a + 1])
		{
			a++;
			continue;
		}
		if (str[a] < '0' || str[i] > '9')
		{
			return (0);
		}
		a++;
	}
	return (1);
}

/**
 * my_free_stack -  free all the stacks created
 * @head: a pointer to the head of the node
 */

void my_free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

/**
 * my_free_head - frees the head pointer
 */

void my_free_head(void)
{
	if (file_ptr->head)
		free_stack(file_ptr->head);
	file_ptr->head = NULL;
}
