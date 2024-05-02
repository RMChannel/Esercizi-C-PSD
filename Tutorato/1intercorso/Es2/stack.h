#include "item.h"
#define MAXSTACK 50

typedef struct stack *Stack;

Stack newStack(); 
int isEmptyStack(Stack); 
int push(Stack, Item);
int pop(Stack);
Item top(Stack);
void printStack(Stack);
