#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void searchAndFound(Stack stack, Item item, int *c) {
	if(!isEmptyStack(stack)) {
		Item temp=top(stack);
		pop(stack);
		if(cmpItem(temp,item)==0) (*c)=1;
		searchAndFound(stack,item,c);
		push(stack,temp);
	}
}

int search(Stack stack, char *s) {
	int control=0;
	char *word=malloc(sizeof(char)*50);
	strcpy(word,s);
	searchAndFound(stack, word, &control);
	return control;
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
	printf("%d\n",search(stack1,"lenzuolo"));
	strcpy(c1,"ciao");
	strcpy(c2,"tonno");
	strcpy(c3,"luna");
	strcpy(c4,"gatto");
	push(stack2,c4);
	push(stack2,c3);
	push(stack2,c2);
	push(stack2,c1);
	printf("%d\n",search(stack2,"tana"));
	strcpy(c1,"pollo");
	strcpy(c2,"punto");
	strcpy(c3,"palla");
	strcpy(c4,"mango");
	push(stack3,c4);
	push(stack3,c3);
	push(stack3,c2);
	push(stack3,c1);
	printf("%d\n",search(stack3,"pinna"));
	strcpy(c1,"pollo");
	strcpy(c2,"punto");
	strcpy(c3,"palla");
	push(stack4,c3);
	push(stack4,c2);
	push(stack4,c1);
	printf("%d\n",search(stack4,"punto"));
	return 0;
}