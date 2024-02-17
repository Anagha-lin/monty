#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/* Function prototypes */
void my_div(stack_t **stack, unsigned int line_number);
void execute_file(stack_t **stack);
void my_swap(stack_t **stack, unsigned int line_number);
void my_add(stack_t **stack, unsigned int line_number);
void my_pstr(stack_t **stack, unsigned int line_number);
void my_mod(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_push(stack_t **stack, unsigned int line_number);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void my_pchar(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_mul(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);
void my_sub(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);

/* Stack helper functions */
stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif /* monty.h */

