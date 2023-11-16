#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;

extern bus_t bus;

typedef struct instruction_s
{
    char *opcode;
    void (*my_func)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);

void my_pop(stack_t **head, unsigned int counter);
void my_push(stack_t **head, unsigned int number);
void my_pint(stack_t **head, unsigned int number);
void my_add(stack_t **head, unsigned int counter);
void my_mod(stack_t **head, unsigned int counter);
void my_swap(stack_t **head, unsigned int counter);
void my_pchar(stack_t **head, unsigned int counter);
void my_nop(stack_t **head, unsigned int counter);
void my_sub(stack_t **head, unsigned int counter);
void my_mul(stack_t **head, unsigned int counter);
void my_pstr(stack_t **head, unsigned int counter);
void my_queue(stack_t **head, unsigned int counter);
void my_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void my_stack(stack_t **head, unsigned int counter);
void my_rotl(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void my_div(stack_t **head, unsigned int counter);
void my_pall(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);

#endif

