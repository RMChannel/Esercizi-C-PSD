#include "item.h"
#include <stdlib.h>
#include <stdio.h>

Item inputItem(){
	
	char *p=malloc(sizeof(char));
	scanf("%c",p);
	return p;
}

void outputItem(Item item){
	char *p=item;
	printf("%c ",*p);
}

int cmpItem(Item item1,Item item2){
	char *p1=item1,*p2=item2;
	
	return *p1-*p2;	
}

Item cloneItem (Item item)
{
	char *p = malloc (sizeof (char));
	char *q = item;
	*p = *q;
	return p;
}

