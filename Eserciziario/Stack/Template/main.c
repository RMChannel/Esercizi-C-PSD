#include <stdio.h>
#include "item.h"
#include "stack.h"

int main(){

	int pos;

	Stack stack=newStack();

	for (int i=0; i<5; i++){
		Item item = inputItem();
		push (stack, item);

		printf("\nstack: ");
		printStack (stack);
	}

	for (int i=0; i<6; i++){
		printf("stiamo eliminando: ");

		Item item=top(stack);
		if(item != NULL)
			outputItem(item);
		pop (stack);

		printf("\nstack: ");
		printStack (stack);
	}
	
	
	
	return 0;
}