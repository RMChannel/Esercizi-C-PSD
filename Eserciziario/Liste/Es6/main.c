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
	removeListItem(list,n5);
	printList(list);
	return 0;
}