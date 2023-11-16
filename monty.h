#ifndef MONTY_H
#define MONTY_H

/* MY HEADER FILES*/

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* MY DATA STRUCTURES */
/**
 * struct my_stack_s - doubly linked list rep of a stack (or queue)
 * @n: integer value
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct my_stack_s
{
	int n;
	struct my_stack_s *prev;
	struct my_stack_s *next;
} stack_t;

/**
 * struct my_instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: func to handle the opcode
 *
 * Description: Opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct my_instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int counter_numb);
} my_instruction_t;

/**
 * struct _File_content - struct holding item of a line
 * @file: pointer to the file
 * @line: a pointer to the line (read by getline)
 * @opcode_my_instruction: array holding an instruction_t struct
 * @head: pointer to the head
 * @counter_numb: line number being read
 * @num_tokens: number of tokens passed
 * @tokens: holds the tokenized string
 */

typedef struct _File_content
{
	FILE *file;
	char *line;
	unsigned int counter_numb;
	int num_tokens;
	char **tokens;
	my_instruction_t *opcode_my_instruction;
	stack_t *head;
} _File_content;

extern _File_content *file_ptr;


/* MY  FUNCTION PROTOTYPES */
void my_pall(stack_t **stack, unsigned int counter_numb);
void my_pint(stack_t **stack, unsigned int counter_numb);
void my_pop(stack_t **stack, unsigned int counter_numb);
void my_swap(stack_t **stack, unsigned int counter_numb);
void my_count_arguments(int argc);
int main(int argc, char **argv);
void my_handle_file_opening(const char *name_of_file, FILE **file);
_File_content *allocated_file_content(void);
void my_parse_line(void);
void my_get_opcode_func(void);
void my_invalid_instruction(void);
void my_fclose_file(void);
void my_free_tokens(void);
void my_free_file_ptr(void);
void my_execute_opcode(void);
void my_push(stack_t **stack, unsigned int counter_numb);
void my_free_stack(stack_t *head);
int my_check_digit_(char *str);
void my_free_head(void);
void my_nop(stack_t **stack, unsigned int counter_numb);
int my_count_stacks(stack_t *stack);
void my_add(stack_t **stack, unsigned int counter_numb);
void sub(stack_t **stack, unsigned int counter_numb);
void my_mod(stack_t **stack, unsigned int counter_numb);
void my_handle_hash(void);
void my_pchar(stack_t **stack, unsigned int counter_numb);
void my_pstr(stack_t **stack, unsigned int counter_numb);
void my_div(stack_t **stack, unsigned int counter_numb);
void my_mul(stack_t **stack, unsigned int counter_numb);
void my_rotl(stack_t **stack, unsigned int counter_numb);
void my_rotr(stack_t **stack, unsigned int counter_numb);
#endif /* MONTY_H */
