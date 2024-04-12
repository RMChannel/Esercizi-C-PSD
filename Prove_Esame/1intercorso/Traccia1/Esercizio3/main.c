#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "stack.h"

Item newItem(char *word) {
	char *a=malloc(sizeof(word));
	strcpy(a,word);
	return a;
}

void reverseStack(Stack *stackOrigin, Item param) {
	Stack stackNew=newStack();
	Item item;
	while(!(isEmptyStack(*stackOrigin))) {
		item=top(*stackOrigin);
		if(compareItem(item,param)>0) push(stackNew,item);
		pop(*stackOrigin);
	}
	*stackOrigin=stackNew;
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
	FILE *fp=fopen("input.txt","r");
	Stack stack;
	char line[100], word[20];
	Item param, wordReal;
	char *linep, *linef;
	while(fgets(line,sizeof(line),fp)) {
		stack=newStack();
		linep=line;
		for(linef=line;*linef;linef++);
		sscanf(linep,"%s",word);
		if(word[0]=='!') param=randomItem();
		else param=newItem(word);
		linep+=strlen(word)+1;
		while(linep<linef) {
			sscanf(linep,"%s ",word);
			linep+=strlen(word)+1;
			if (strlen(word)>0) {
				if(word[0]=='!') wordReal=randomItem();
				else wordReal=newItem(word);
				push(stack,wordReal);
			}
		}
		printf("Elemento parametro: %s\nStack originale: ",param);
		printStack(stack);
		printf("\nStack invertito: ");
		reverseStack(&stack,param);
		printStack(stack);
		printf("\n\n");
		free(stack);
	}
}
