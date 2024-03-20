#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item inputItem() {
    char *pChar=malloc(sizeof(char));
    scanf("%c",pChar);
    return pChar;
}

void outputItem(Item item) {
    char *pChar=item;
    printf("%c",*pChar);
}

int cmpItem(Item item1, Item item2) {
    char *pChar1=item1;
    char *pChar2=item2;
    return strcmp(pChar1,pChar2);
}