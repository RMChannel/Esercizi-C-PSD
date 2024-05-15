#include<stdio.h>
#include<stdlib.h>
#include "item.h"

Item inputItem(){
	int *pInt=malloc(sizeof(int));
	scanf("%d",pInt);
	return pInt;
}

void outputItem(Item item){
	int *pInt=item;
	printf("%d ", *pInt);
}

int cmpItem(Item item1, Item item2){
	int *pInt1=item1, *pInt2=item2;
	return *pInt1-*pInt2;
}