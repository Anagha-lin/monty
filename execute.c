#include "monty.h"
#include <stdio.h>

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", my_push}, {"pall", my_pall}, {"pint", my_pint},
        {"pop", my_pop},
        {"swap", my_swap},
        {"add", my_add},
        {"nop", my_nop},
        {"sub", my_sub},
        {"div", my_div},
        {"mul", my_mul},
        {"mod", my_mod},
        {"pchar", my_pchar},
        {"pstr", my_pstr},
        {"rotl", my_rotl},
        {"rotr", my_rotr},
        {"queue", my_queue},
        {"stack", my_stack},
        {NULL, NULL}};

    unsigned int i = 0;
    char *op;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;
    bus.arg = strtok(NULL, " \n\t");
    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].my_func(stack, counter);
            return 0;
        }
        i++;
    }
    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return 1;
}

