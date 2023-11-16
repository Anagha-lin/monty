#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct my_operation_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: a line content
 * @lifi: flag changes stack <-> queue
 * Description: carries values through the program
 */
typedef struct my_operation_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  my_operation_t;
extern my_operation_t operation;
/**
 * struct my_instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct my_instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} my_instruction_t;
/**
 * struct my_stack_s -  doubly linked list rep of a stack (or queue)
 * @n: integer
 * @prev: points to the prev element of the stack (or queue)
 * @next: points to the nxt element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, FIFO, LIFO, ALX project
 */
typedef struct my_stack_s
{
	int n;
	struct my_stack_s *prev;
	struct my_stack_s *next;
} my_stack_t;
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void my_free_stack(stack_t *head);
void my_pstr(stack_t **head, unsigned int counter);
void my_rotl(stack_t **head, unsigned int counter);
void my_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void my_addnode(stack_t **head, int n);
void my_addqueue(stack_t **head, int n);
void my_queue(stack_t **head, unsigned int counter);
void my_stack(stack_t **head, unsigned int counter);
void my_pop(stack_t **head, unsigned int counter);
void my_swap(stack_t **head, unsigned int counter);
void my_add(stack_t **head, unsigned int counter);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void my_push(stack_t **head, unsigned int number);
void my_pall(stack_t **head, unsigned int number);
void my_pint(stack_t **head, unsigned int number);
void my_nop(stack_t **head, unsigned int counter);
void my_sub(stack_t **head, unsigned int counter);
void my_div(stack_t **head, unsigned int counter);
void my_mul(stack_t **head, unsigned int counter);
void my_mod(stack_t **head, unsigned int counter);
void my_pchar(stack_t **head, unsigned int counter);
#endif
