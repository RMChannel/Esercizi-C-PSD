#include <stdlib.h>
#include "stack.h"
#define MAXSTACK 10

struct stack{
    Item items[MAXSTACK];
    int top;
};

Stack newStack(){
    Stack s=malloc(sizeof(struct stack));
    s->top=0;
    return s;
} 

int isEmptyStack(Stack stack){
    if(stack->top==0)
        return 1;
    else
        return 0;
}

int push(Stack stack, Item item){
    if(stack->top==MAXSTACK)
        return 0;
    
    stack->items[stack->top]=item;
    stack->top++;
    
    return 1;
}

int pop(Stack stack){
    if(isEmptyStack(stack))
        return 0;

    stack->top--;    
    return 1;
}

Item top(Stack stack){
    if(isEmptyStack(stack))
        return NULL;
    else
        return stack->items[stack->top-1];
}

void printStack(Stack stack){
    for(int i=stack->top-1; i>=0; i--){
        outputItem(stack->items[i]);
    }
    
}
