#ifndef MONTY_H
#define MONTY_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

extern Node* stack;

void push(int value);
void pall();

#endif /* MONTY_H */

