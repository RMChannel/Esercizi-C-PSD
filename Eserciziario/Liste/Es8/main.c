#include <stdio.h>
#include <stdlib.h>
#include "list.h" 
#include "item.h"

int main(){
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
	printList(callMergeSort(list));
	return 0;
}