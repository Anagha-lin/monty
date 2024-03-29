#include "monty.h"

glob_t glob;

int main(int argc, char *argv[]) {
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    glob.file = fopen(argv[1], "r");
    if (glob.file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    execute_file(&stack);

    fclose(glob.file);
    free(glob.line);
    free_stack(stack);
    exit(EXIT_SUCCESS);
}

