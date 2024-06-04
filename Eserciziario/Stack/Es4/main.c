#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void insertStack(Stack stack,Item item) {
	if(isEmptyStack(stack)) push(stack,item);
	else {
		Item temp=top(stack);
		pop(stack);
		insertStack(stack,item);
		push(stack,temp);
	}
}

void reverseStack(Stack stack) {
	if(!isEmptyStack(stack)) {
		Item item=top(stack);
		pop(stack);
		reverseStack(stack);
		insertStack(stack,item);
	}
}

int main(){
	FILE *fp;
	if((fp=fopen("input.txt","r"))==NULL) {
		fprintf(stderr,"File non trovato\n");
		exit(EXIT_FAILURE);
	}
	char line[200];
	while(fgets(line,sizeof(line),fp)) {
		Stack stack=newStack();
		Stack temp=newStack();
		char *lineP=line, *lineF=line;
		while(*lineF) lineF++;
		while(lineP<lineF) {
			char *word=malloc(sizeof(char)*50);
			sscanf(lineP,"%s",word);
			lineP+=strlen(word)+1;
			push(temp,word);
		}
		while(!isEmptyStack(temp)) {
			Item item=top(temp);
			pop(temp);
			push(stack,item);
		}
		reverseStack(stack);
		printStack(stack);
		printf("\n");
	}
}