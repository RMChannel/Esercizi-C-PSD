#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack{
    List items;
};

Stack newStack(){
    Stack s=malloc(sizeof(struct stack));
    s->items=newList();
    return s;
} 

int isEmptyStack(Stack stack){
    return isEmpty(stack->items);
}

int push(Stack stack, Item item){
    addHead(stack->items, item);
    return 1;
}

int pop(Stack stack){
    if(removeHead(stack->items)==NULL) 
        return 0;
    else 
        return 1;
}

Item top(Stack stack){
    return getHead(stack->items);
}

void printStack(Stack stack){
    printList(stack->items);
}