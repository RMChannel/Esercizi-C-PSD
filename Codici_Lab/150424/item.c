#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#define MAX 100

Item inputItem (int n) {
  int *a=malloc(sizeof(int));
  *a=n;
  return a;
}

void outputItem (Item a) {
  int *number=a;
  printf("%d\t",*number);
}

int compareItem (Item a1, Item a2){
  int *n1=a1;
  int *n2=a2;
  return *n1==*n2;
}
