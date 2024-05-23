#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "key.h"
#define NUMCHAR 20

int equals(Key key1, Key key2) {
    char *c1=key1;
    char *c2=key2;
    return !strcmp(c1,c2);
}

int hashValue(Key k, int m) {
    int h=0;
    const int a=128;
    for(char *key=k;*(key)!='\0';key++) h=((h*a+(*key))%m);
    return h;
}

Key inputKey() {
    Key k=malloc(sizeof(char)*NUMCHAR);
    scanf("%s",k);
    return k;
}

void outputKey(Key key) {
    printf("%s\n",key);
}