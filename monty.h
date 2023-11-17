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
 * struct global_s - Structure holding program-wide variables.
 * @arg: Value associated with the instruction.
 * @line: Content of the current input line.
 * @file: Pointer to the Monty file being processed.
 *
 * Description: This structure carries values essential for the
 * program's execution throughout its runtime.
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/**
 * struct stack_s - Doubly linked list node representing a stack (or queue).
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element in the stack (or queue).
 * @next: Pointer to the next element in the stack (or queue).
 *
 * Description: This structure defines a node in a doubly linked list,
 * serving as the foundation for stack and queue operations with LIFO and FIFO
 * characteristics.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	 struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Struct def an opcode and its handling func.
 * @opcode: The opcode string.
 * @f: Function pointer to the opcode's handling function.
 *
 * Description: This structure associates an opcode with its corresponding
 * func for exec
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);
void my_add(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);
void my_sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void my_mul(stack_t **stack, unsigned int line_number);
void my_mod(stack_t **stack, unsigned int line_number);
void my_pchar(stack_t **stack, unsigned int line_number);
void my_pstr(stack_t **stack, unsigned int line_number);
void execute_file(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

/* Stack helper functions */
stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif /* MONTY_H */

