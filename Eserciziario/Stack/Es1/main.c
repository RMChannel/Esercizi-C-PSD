#include <stdio.h>
#include "item.h"
#include "stack.h"

int main(){
	Stack stack=newStack();
	if(isEmptyStack(stack)) printf("Lo stack e' vuoto\n");
}