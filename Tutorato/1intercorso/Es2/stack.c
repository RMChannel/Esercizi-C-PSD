#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
	Item elements[MAXSTACK];
	int top;
};

Stack newStack() {
	Stack newStack = malloc(sizeof(struct stack));
	newStack->top = 0;

	return newStack;
}

int isEmptyStack(Stack stack) {
	return !stack->top;
}

int push(Stack stack, Item item) {
	if(stack->top == MAXSTACK)
		return 0;

	stack->elements[stack->top] = item;
	stack->top++;

	return 1;
}

int pop(Stack stack) {
	if(isEmptyStack(stack))
		return 0;

	stack->top--;
	return 1;
}

Item top(Stack stack) {
	if(isEmptyStack(stack))
		return NULL;

	return stack->elements[stack->top - 1];
}

void printStack(Stack stack) {
	int i;

	for(i = stack->top - 1; i >= 0; i--)
		outputItem(stack->elements[i]);
}
