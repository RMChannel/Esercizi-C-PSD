#include <stdlib.h>
#include "list.h"
#include "stack.h"
#define MAXSTACK 10

struct stack {
    Item items[MAXSTACK];
    int top;
};

Stack newStack() {
    Stack s=malloc(sizeof(struct stack));
    s->top=0;
    return s;
}


int isEmptyStack(Stack s) {
    if (s->top==0) return 1;
    else return 0;
}


int push(Stack s, Item item) {
    if (s->top==MAXSTACK) return 0;
    else {
        s->items[s->top]=item;
        s->top++;
        return 1;
    }
}


int pop(Stack s) {
    if (isEmptyStack(s)) return 0;
    else {
        s->top--;
        return 1;
    }
}


Item top(Stack s) {
    if (isEmptyStack(s)) return NULL;
    else return s->items[s->top-1];
}


void printStack(Stack s) {
    for (int i=s->top-1;i>=0;i--) outputItem(s->items[i]);
}