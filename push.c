#include "monty.h"

/**
 * my_push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Current line number of the opcode in the Monty file.
 *
 * Description: This function pushes an integer element onto the stack.
 * If the argument is not a valid integer or not provided, it prints an error
 * message and exits the program.
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (glob.arg == NULL || !is_number(glob.arg))
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
	}

	n = atoi(glob.arg);
	if (add_node(stack, n) == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
	}
}

/**
 * is_number - Checks if a string is a number.
 * @str: String to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 *
 * Description: This function determines if a given string is a valid integer.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
	return (0);

	if (*str == '-' || *str == '+')
	str++;

	while (*str != '\0')
	{
	if (*str < '0' || *str > '9')
	return (0);

	str++;
	}

	return (1);
}

