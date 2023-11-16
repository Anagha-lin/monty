#include "monty.h"
/**
 * my_push - bringing node to the stack
 * @head: first to be loaded
 * @counter: line_number
 * Return: no return
*/
void my_push(stack_t **head, unsigned int counter)
{
	int m, k = 0, flag = 0;

	if (operation.arg)
	{
		if (operation.arg[0] == '-')
			k++;
		for (; operation.arg[k] != '\0'; k++)
		{
			if (operation.arg[k] > 57 || operation.arg[k] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(operation.file);
			free(operation.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(operation.file);
		free(operation.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(operation.arg);
	if (operation.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
