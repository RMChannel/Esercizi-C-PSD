#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"

#define NCHAR 20+1

Item inputItem(char *s){
	char *pString=malloc(NCHAR*sizeof(char));
	strcpy(pString,s);
	return pString;
}

void outputItem(Item item){
	char *pString=item;
	printf("%s ", pString);
}

int cmpItem(Item item1, Item item2){
	char *pString1=item1, *pString2=item2;
	//printf("%s %s %d\n",pString1,pString2,strcmp(pString1,pString2));
	return strcmp(pString1,pString2);
}