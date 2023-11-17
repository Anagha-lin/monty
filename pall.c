#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack();
void push(Stack* stack, int value);
void pall(Stack* stack);
void freeStack(Stack* stack);

int main(void) {
    Stack* stack = createStack();

   
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    pall(stack);

    freeStack(stack);

    return 0;
}

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;

    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pall(Stack* stack) {
    Node* current = stack->top;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void freeStack(Stack* stack) {
    Node* current = stack->top;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(stack);
}

