#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(char c) {
    char *s=malloc(sizeof(char));
    (*s)=c;
    return s;
}

void outputItem(Item item) {
    char *s=item;
    printf("%c ",*s);
}

int cmpItem(Item i1, Item i2) {
    char *s1=i1, *s2=i2;
    return (*s1)-(*s2);
}