#include "monty.h"

/**
 * execute_file - reads and executes opcodes from a file
 * @stack: pointer to the top of the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&bus.content, &len, bus.file)) != -1)
	{
	line_number++;
	opcode = strtok(bus.content, " \t\r\n\a");
	bus.arg = strtok(NULL, " \n\t");
	if (opcode == NULL || *opcode == '#')
	continue;
	execute_opcode(opcode, stack, line_number);
	}
}

/**
 * execute_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
	{"push", my_push},
	{"pall", my_pall},
	{"pint", my_pint},
	{"pop", my_pop},
	{"swap", my_swap},
	{"nop", my_nop},
	{"add", my_add},
	{"sub", my_sub},
	{"div", my_div},
	{"mul", my_mul},
	{"mod", my_mod},
	{"pchar", my_pchar},
	{"pstr", my_pstr},
	{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
	if (strcmp(opcode, instructions[i].opcode) == 0)
	{
	instructions[i].my_func(stack, line_number);
	return;
	}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	my_free_stack(*stack);
	fclose(bus.file);
	free(bus.content);
	exit(EXIT_FAILURE);
}

