#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void filter(Stack stack, char f) {
	if(!isEmptyStack(stack)) {
		char *s=top(stack);
		pop(stack);
		filter(stack,f);
		if((*s)!=f) push(stack,s);
	}
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
	filter(stack1,'b');
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
	filter(stack2,'t');
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
	filter(stack3,'p');
	printStack(stack3);
	printf("\n");
	strcpy(c1,"pollo");
	strcpy(c2,"punto");
	strcpy(c3,"palla");
	push(stack4,c3);
	push(stack4,c2);
	push(stack4,c1);
	filter(stack4,'p');
	printStack(stack4);
	printf("\n");
	return 0;
}