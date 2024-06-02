#include <stdio.h>
#include <stdlib.h>
#include "list.h" 
#include "item.h"

void test1() {
	List list=newList();
	int *n1=malloc(sizeof(int));
	int *n2=malloc(sizeof(int));
	int *n3=malloc(sizeof(int));
	int *n4=malloc(sizeof(int));
	int *n5=malloc(sizeof(int));
	(*n1)=6;
	(*n2)=8;
	(*n3)=13;
	(*n4)=2;
	(*n5)=10;
	addHead(list,n1);
	addHead(list,n2);
	addHead(list,n3);
	addHead(list,n4);
	addHead(list,n5);
	massimoLista(list);
	printList(list);
}

void test2() {
	List list=newList();
	int *n1=malloc(sizeof(int));
	int *n2=malloc(sizeof(int));
	int *n3=malloc(sizeof(int));
	int *n4=malloc(sizeof(int));
	int *n5=malloc(sizeof(int));
	(*n1)=2;
	(*n2)=9;
	(*n3)=5;
	(*n4)=4;
	(*n5)=1;
	addHead(list,n1);
	addHead(list,n2);
	addHead(list,n3);
	addHead(list,n4);
	addHead(list,n5);
	massimoLista(list);
	printList(list);
}

void test3() {
	List list=newList();
	int *n1=malloc(sizeof(int));
	int *n2=malloc(sizeof(int));
	int *n3=malloc(sizeof(int));
	int *n4=malloc(sizeof(int));
	int *n5=malloc(sizeof(int));
	(*n1)=1;
	(*n2)=10;
	(*n3)=6;
	(*n4)=8;
	(*n5)=9;
	addHead(list,n1);
	addHead(list,n2);
	addHead(list,n3);
	addHead(list,n4);
	addHead(list,n5);
	massimoLista(list);
	printList(list);
}

int main(){
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	printf("\n");
	return 0;
}