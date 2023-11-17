#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* stack = NULL;

void push(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack;
    stack = newNode;
}

void pall() {
    Node* curr = stack;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[100];
    char opcode[100];
    int value;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d", opcode, &value);

        if (strcmp(opcode, "push") == 0) {
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error: unknown instruction %s\n", opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);

    return 0;
}

