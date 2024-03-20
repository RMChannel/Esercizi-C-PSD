#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#define NCAHR 20

Item inputItem() {
    char *pString=malloc(sizeof(char)*NCAHR);
    scanf("%s",pString);
    return pString;
}

void outputItem(Item item) {
    char *pString=item;
    printf("%s ", pString);
}

int cmpItem(Item item1, Item item2) {
    char *pString1=item1;
    char *pString2=item2;
    return strcmp(pString1,pString2);
}