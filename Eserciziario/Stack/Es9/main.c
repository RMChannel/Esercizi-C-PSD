#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

int count(Stack stack, int n) {
	if(!isEmptyStack(stack)) {
		Item item=top(stack);
		pop(stack);
		int n1=count(stack,n+1);
		push(stack,item);
		return n1;
	}
	else return n;
}

void contaStack(Stack stack) {
	int n=count(stack,0);
	if((n%3)==0) printf("%d (OK)\n",n);
	else if(((n-1)%3)==0) printf("%d (RIMUOVERE)\n",n);
	else if(((n+1)%3)==0) printf("%d (AGGIUNGERE)\n",n);
}


void test1() {
	Stack stack=newStack();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	int *p6=malloc(sizeof(int));
	(*p1)=6;
	(*p2)=8;
	(*p3)=3;
	(*p4)=1;
	(*p5)=2;
	(*p6)=10;
	push(stack,p1);
	push(stack,p2);
	push(stack,p3);
	push(stack,p4);
	push(stack,p5);
	push(stack,p6);
	contaStack(stack);
}

void test2() {
	Stack stack=newStack();
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
	contaStack(stack);
}

void test3() {
	Stack stack=newStack();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	int *p6=malloc(sizeof(int));
	int *p7=malloc(sizeof(int));
	(*p1)=2;
	(*p2)=7;
	(*p3)=1;
	(*p4)=10;
	(*p5)=6;
	(*p6)=8;
	(*p7)=9;
	push(stack,p1);
	push(stack,p2);
	push(stack,p3);
	push(stack,p4);
	push(stack,p5);
	push(stack,p6);
	push(stack,p7);
	contaStack(stack);
}

int main(){
	test1();
	test2();
	test3();
	return 0;
}