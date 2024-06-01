typedef struct stack *Stack;

Stack newStack();
void push(Stack stack, int n);
void printStack(Stack stack);
void pop(Stack stack);
int peek(Stack stack);