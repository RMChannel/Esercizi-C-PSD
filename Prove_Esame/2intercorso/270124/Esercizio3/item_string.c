#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"

#define NCHAR 20+1

Item inputItem(){
	char *pString=malloc(NCHAR*sizeof(char));
	scanf("%s",pString);
	return pString;
}

void outputItem(Item item){
	char *pString=item;//puntiamo all'inizio della stringa e non la stiamo copiando
	printf("%s ", pString);
}

int cmpItem(Item item1, Item item2){
	char *pString1=item1, *pString2=item2;
	return strcmp(pString1,pString2);
}

Item randomItem() {
	char *a = calloc(3, sizeof(char));
	a[0] = 'a' + rand() % 26;
	char c = 'a' + rand() % 28;
	if(c > 'z') return a;
	a[1] = c;
 	c = 'a' + rand() % 28;
	if(c > 'z') return a;
	a[2] = c;
	return a;
}

void outputItemLen(Item it, int len){
	char *pt = it;
	int length = snprintf(NULL, 0, "%s", *pt);
	char str[length + 1];
	snprintf(str, length + 1, "%s", *pt);

	printf("%.*s", len, str);
}