#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "queue.h"
#include "btree.h"

void printArray(int a[], int n) {
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}

void copyArray(Stack stack, int a[], int *n) {
	if(!isEmptyStack(stack)) {
		Item temp=top(stack);
		pop(stack);
		int *Pn=temp;
		a[(*n)]=(*Pn);
		(*n)++;
		copyArray(stack,a,n);
		push(stack,temp);
	}
}

void copiaArray(Stack stack) {
	int a[100];
	int n=0;
	copyArray(stack,a,&n);
	printf("Array: ");
	printArray(a,n);
}

void copyStack(Stack stack, Stack stack2) {
	if(!isEmptyStack(stack)) {
		Item temp=top(stack);
		pop(stack);
		copyStack(stack,stack2);
		push(stack,temp);
		push(stack2,temp);
	}
}

void copiaStack(Stack stack) {
	Stack stack2=newStack();
	printf("Stack: ");
	copyStack(stack,stack2);
	printStack(stack2);
	printf("\n");
}

void copyQueue(Stack stack, Queue queue) {
	if(!isEmptyStack(stack)) {
		Item temp=top(stack);
		pop(stack);
		enqueue(queue,temp);
		copyQueue(stack,queue);
		push(stack,temp);
	}
}

void copiaQueue(Stack stack) {
	Queue queue=newQueue();
	copyQueue(stack,queue);
	printf("Queue: ");
	printQueue(queue);
	printf("\n");
}

void copyTree(Stack stack, BTree t) {
	if(!isEmptyStack(stack)) {
		BTree left=getLeft(t);
		BTree right=getRight(t);
		Item temp1=top(stack);
		pop(stack);
		Item temp2;
		if(!isEmptyStack(stack)) {
			temp2=top(stack);
			pop(stack);
			setRight(t,buildTree(NULL,NULL,temp2));
		}
		setLeft(t,buildTree(NULL,NULL,temp1));
		copyTree(stack,getLeft(t));
	}
}

void copiaTree(Stack stack) {
	BTree tree=buildTree(NULL,NULL,top(stack));
	pop(stack);
	copyTree(stack,tree);
	printTree(tree);
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
	copiaArray(stack);
	copiaStack(stack);
	copiaQueue(stack);
	copiaTree(stack);
	printf("\n");
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
	copiaArray(stack);
	copiaStack(stack);
	copiaQueue(stack);
	copiaTree(stack);
	printf("\n");
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
	copiaArray(stack);
	copiaStack(stack);
	copiaQueue(stack);
	copiaTree(stack);
}

int main(){
	test1();
	test2();
	test3();
	return 0;
}