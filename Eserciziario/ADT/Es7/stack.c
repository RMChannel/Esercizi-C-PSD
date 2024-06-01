#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define N 10

struct stack{
    int stack[N];
    int size;
    int init;
};

Stack newStack() {
    Stack stack=malloc(sizeof(struct stack));
    stack->size=0;
    stack->init=0;
    return stack;
}

void push(Stack stack, int n) {
    if(stack->size==N) return;
    int i=stack->size+stack->init;
    if(i>=N) i-=N;
    stack->stack[i]=n;
    stack->size++;
}

void pop(Stack stack) {
    stack->init++;
}

int peek(Stack stack) {
    return stack->stack[stack->init];
}

void printStack(Stack stack) {
    for(int i=stack->init;i<stack->size;i++) {
        if(i==N) i=0;
        printf("%d ",stack->stack[i]);
    }
}