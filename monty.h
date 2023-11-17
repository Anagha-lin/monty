#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element of the stack (or queue).
 * @next: Pointer to the next element of the stack (or queue).
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its associated function
 * @opcode: The operation code.
 * @my_func: The function associated with the opcode.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*my_func)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - global variables
 * @file: Pointer to the Monty file.
 * @content: Content of the current line.
 * @arg: Argument passed to the opcode.
 * @lifi: 0 if stack mode, 1 if queue mode.
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;


/* Function prototypes */
void my_add(stack_t **head, unsigned int counter);
void my_addnode(stack_t **head, int n);
void my_div(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void my_free_stack(stack_t *head);
void my_mod(stack_t **head, unsigned int counter);
void my_mul(stack_t **head, unsigned int counter);
void my_nop(stack_t **head, unsigned int counter);
void my_pall(stack_t **head, unsigned int counter);
void my_pchar(stack_t **head, unsigned int counter);
void my_pint(stack_t **head, unsigned int counter);
void my_pop(stack_t **head, unsigned int counter);
void my_pstr(stack_t **head, unsigned int counter);
void my_push(stack_t **head, unsigned int counter);
void my_queue(stack_t **head, unsigned int counter);
void my_addqueue(stack_t **head, int n);
void my_rotl(stack_t **head, unsigned int counter);
void my_rotr(stack_t **head, unsigned int counter);
void my_stack(stack_t **head, unsigned int counter);
void my_sub(stack_t **head, unsigned int counter);
void my_swap(stack_t **head, unsigned int counter);
char *clean_line(char *line);
int execute_opcode(opcode, stack, line_number);

#endif /* MONTY_H */

