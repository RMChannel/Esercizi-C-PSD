#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

int main(){
	Stack stack1=newStack();
	Stack stack2=newStack();
	Stack stack3=newStack();
	char *c1=malloc(sizeof(char)*50);
	char *c2=malloc(sizeof(char)*50);
	char *c3=malloc(sizeof(char)*50);
	char *c4=malloc(sizeof(char)*50);
	char *c5=malloc(sizeof(char)*50);
	char *c6=malloc(sizeof(char)*50);
	char *c7=malloc(sizeof(char)*50);
	char *c8=malloc(sizeof(char)*50);
	char *c9=malloc(sizeof(char)*50);
	char *c10=malloc(sizeof(char)*50);
	char *c11=malloc(sizeof(char)*50);
	strcpy(c1,"ciao");
	strcpy(c2,"gente");
	strcpy(c3,"gente");
	strcpy(c4,"bella");
	strcpy(c5,"ciao");
	strcpy(c6,"come");
	strcpy(c7,"va");
	strcpy(c8,"ei");
	strcpy(c9,"fu");
	strcpy(c10,"siccome");
	strcpy(c11,"immobile");
	push(stack1,c2);
	push(stack1,c1);
	push(stack2,c7);
	push(stack2,c6);
	push(stack2,c5);
	push(stack2,c4);
	push(stack2,c3);
	push(stack3,c11);
	push(stack3,c10);
	push(stack3,c9);
	push(stack3,c8);
	printStack(stack1);
	printf("\n");
	printStack(stack2);
	printf("\n");
	printStack(stack3);
	printf("\n");
	return 0;
}