#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

void findMassimo(Stack stack, Item *max) {
	if(!isEmptyStack(stack)) {
		Item item=top(stack);
		if(cmpItem((*max),top(stack))<0) (*max)=item;
		pop(stack);
		findMassimo(stack,max);
		if(item!=(*max)) push(stack,item);
	}
	else push(stack,*max);
}

void findMinimo(Stack stack, Item *min) {
	if(!isEmptyStack(stack)) {
		Item item=top(stack);
		if(cmpItem((*min),top(stack))>0) (*min)=item;
		pop(stack);
		findMinimo(stack,min);
		if(item!=(*min)) push(stack,item);
	}
}

void massimoStack(Stack stack) {
	Item item=top(stack);
	findMassimo(stack,&item);
}

void minimoStack(Stack stack) {
	Item item=top(stack);
	findMinimo(stack,&item);
	push(stack,item);
}


void test1() {
	Stack stack=newStack();
	Stack stack2=newStack();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	(*p1)=6;
	(*p2)=8;
	(*p3)=13;
	(*p4)=2;
	(*p5)=10;
	push(stack,p1);
	push(stack,p2);
	push(stack,p3);
	push(stack,p4);
	push(stack,p5);
	push(stack2,p1);
	push(stack2,p2);
	push(stack2,p3);
	push(stack2,p4);
	push(stack2,p5);
	printf("Con max: ");
	massimoStack(stack);
	printStack(stack);
	printf("\nCon min: ");
	minimoStack(stack2);
	printStack(stack2);
	printf("\n\n");
}

void test2() {
	Stack stack=newStack();
	Stack stack2=newStack();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	(*p1)=2;
	(*p2)=9;
	(*p3)=5;
	(*p4)=4;
	(*p5)=1;
	push(stack,p1);
	push(stack,p2);
	push(stack,p3);
	push(stack,p4);
	push(stack,p5);
	push(stack2,p1);
	push(stack2,p2);
	push(stack2,p3);
	push(stack2,p4);
	push(stack2,p5);
	printf("Con max: ");
	massimoStack(stack);
	printStack(stack);
	printf("\nCon min: ");
	minimoStack(stack2);
	printStack(stack2);
	printf("\n\n");
}

void test3() {
	Stack stack=newStack();
	Stack stack2=newStack();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	(*p1)=1;
	(*p2)=10;
	(*p3)=6;
	(*p4)=8;
	(*p5)=9;
	push(stack,p1);
	push(stack,p2);
	push(stack,p3);
	push(stack,p4);
	push(stack,p5);
	push(stack2,p1);
	push(stack2,p2);
	push(stack2,p3);
	push(stack2,p4);
	push(stack2,p5);
	printf("Con max: ");
	massimoStack(stack);
	printStack(stack);
	printf("\nCon min: ");
	minimoStack(stack2);
	printStack(stack2);
	printf("\n\n");
}

int main(){
	test1();
	test2();
	test3();
	return 0;
}