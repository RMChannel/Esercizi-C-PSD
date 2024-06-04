#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void searchAndFound(Stack stack, Item item) {
	if(!isEmptyStack(stack)) {
		int c=1;
		Item temp=top(stack);
		pop(stack);
		if(cmpItem(temp,item)==0) c=0;
		searchAndFound(stack,item);
		if(c) push(stack,temp);
	}
}

void filter(Stack stack, char *s) {
	char *word=malloc(sizeof(char)*50);
	strcpy(word,s);
	searchAndFound(stack, word);
}

int main(){
	Stack stack1=newStack();
	Stack stack2=newStack();
	Stack stack3=newStack();
	Stack stack4=newStack();
	char *c1=malloc(sizeof(char)*50);
	char *c2=malloc(sizeof(char)*50);
	char *c3=malloc(sizeof(char)*50);
	char *c4=malloc(sizeof(char)*50);
	strcpy(c1,"casa");
	strcpy(c2,"buongiorno");
	strcpy(c3,"testo");
	strcpy(c4,"lenzuolo");
	push(stack1,c4);
	push(stack1,c3);
	push(stack1,c2);
	push(stack1,c1);
	filter(stack1,"lenzuolo");
	printStack(stack1);
	printf("\n");
	strcpy(c1,"ciao");
	strcpy(c2,"tonno");
	strcpy(c3,"luna");
	strcpy(c4,"gatto");
	push(stack2,c4);
	push(stack2,c3);
	push(stack2,c2);
	push(stack2,c1);
	filter(stack2,"tana");
	printStack(stack2);
	printf("\n");
	strcpy(c1,"pollo");
	strcpy(c2,"punto");
	strcpy(c3,"palla");
	strcpy(c4,"mango");
	push(stack3,c4);
	push(stack3,c3);
	push(stack3,c2);
	push(stack3,c1);
	filter(stack3,"pinna");
	printStack(stack3);
	printf("\n");
	strcpy(c1,"pollo");
	strcpy(c2,"punto");
	strcpy(c3,"palla");
	push(stack4,c3);
	push(stack4,c2);
	push(stack4,c1);
	filter(stack4,"punto");
	printStack(stack4);
	printf("\n");
	return 0;
}