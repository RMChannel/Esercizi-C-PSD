#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack stack=newStack();
    push(stack,2);
    push(stack,3);
    push(stack,4);
    pop(stack);
    printStack(stack);
    pop(stack);
    printf("\n%d\n",peek(stack));
}