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