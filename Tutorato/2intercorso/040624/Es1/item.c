#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#define MAX 100

Item inputItem () {
  char *a=malloc(sizeof(char));
  (*a)=getchar();
  return a;
}

void outputItem (Item a) {
  char *b=a;
  printf("%c",*b);
}

int compareItem (Item a1, Item a2){
  char *n1=a1;
  char *n2=a2;
  return *n1==*n2;
}
