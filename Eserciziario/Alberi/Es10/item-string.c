#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#define MAX 100

Item inputItem () {
  char *a=malloc(sizeof(char)*MAX);
  scanf("%s",a);
  return a;
}

void outputItem (Item a) {
  char *stringa=a;
  printf("%s\t",stringa);
}

int compareItem (Item a1, Item a2){
  char *stringa1=a1;
  char *stringa2=a2;
  return strcmp(stringa1,stringa2);
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