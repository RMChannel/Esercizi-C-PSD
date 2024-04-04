#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct stack {
    List items;
};

Stack newStack() {
    Stack s=malloc(sizeof(struct stack));
    s->items=newList();
    return s;
}


int isEmptyStack(Stack s) {
    return isEmpty(s->items);
}


int push(Stack s, Item item) {
    addHead(s->items,item);
    return 1;
}


int pop(Stack s) {
    if(removeHead(s->items)==NULL) return 0;
    else return 1;
}


Item top(Stack s) {
    return getHead(s->items);
}


void printStack(Stack s) {
    printList(s->items);
}