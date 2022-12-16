#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE]; // the stack
int top = -1; // top of stack
void push(int value) {
	if (top == MAX_STACK_SIZE - 1) {
		printf("Error: stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack[++top] = value;
}
void pall() {
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
}
int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Error: no opcode provided\n");
		return EXIT_FAILURE;
	}
	if (strcmp(argv[1], "push") == 0) {
		if (argc < 3) {
			printf("L%d: usage: push integer\n", 1);
			return EXIT_FAILURE;
		}
		Copy code
			int value = atoi(argv[2]); push(value);
	} else if (strcmp(argv[1], "pall") == 0) {
		pall();
	} else {
		printf("Error: invalid opcode\n");
		return EXIT_FAILURE;
	}
	return 0;
}

