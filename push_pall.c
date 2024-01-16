#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack[++top] = value;
}

void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    char opcode[100];
    int value, line_number = 0;

    while (scanf("%s", opcode) != EOF) {
        line_number++;

        if (strcmp(opcode, "push") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error: L%d: unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

