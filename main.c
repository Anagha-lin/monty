#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    unsigned int line_number = 1;

    bus_t bus;
    bus.file = fopen("example.m", "r");
    if (bus.file == NULL)
    {
        fprintf(stderr, "Error: Can't open file\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, bus.file)) != -1)
    {
        bus.content = clean_line(line);
        if (bus.content)
        {
            if (execute(bus.content, &stack, line_number, bus.file) == EXIT_FAILURE)
            {
                free(line);
                my_free_stack(stack);
                fclose(bus.file);
                exit(EXIT_FAILURE);
            }
            line_number++;
        }
    }

    free(line);
    my_free_stack(stack);
    fclose(bus.file);
    return EXIT_SUCCESS;
}

