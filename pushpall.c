#include "monty.h"

void push(stack_t **stack, int value);
void pall(stack_t **stack);

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        return EXIT_FAILURE;
    }
    
    // Open and read the Monty byte code file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Initialize stack
    stack_t *stack = NULL;

    // Read and execute instructions from file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;

        // Parse opcode and argument from line
        
        // Execute opcode based on parsed information
        
    }

    // Free resources and close file
    fclose(file);
    if (line)
        free(line);
    free_stack(stack);

    return EXIT_SUCCESS;
}

void push(stack_t **stack, int value) {
    // Implement push opcode
}

void pall(stack_t **stack) {
    // Implement pall opcode
}

