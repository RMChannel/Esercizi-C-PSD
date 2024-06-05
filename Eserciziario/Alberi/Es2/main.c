#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "btree.h"

int main(){
    BTree t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
    char *l1=malloc(sizeof(char)*5);
    char *l2=malloc(sizeof(char)*5);
    char *l3=malloc(sizeof(char)*5);
    char *l4=malloc(sizeof(char)*5);
    char *l5=malloc(sizeof(char)*5);
    char *l6=malloc(sizeof(char)*5);
    char *l7=malloc(sizeof(char)*5);
    char *l8=malloc(sizeof(char)*5);
    char *l9=malloc(sizeof(char)*5);
    char *l10=malloc(sizeof(char)*5);
    strcpy(l1,"A");
    strcpy(l2,"B");
    strcpy(l3,"C");
    strcpy(l4,"D");
    strcpy(l5,"F");
    strcpy(l6,"E");
    strcpy(l7,"G");
    strcpy(l8,"H");
    strcpy(l9,"I");
    strcpy(l10,"L");
    t9=buildTree(NULL,NULL,l9);
    t10=buildTree(NULL,NULL,l10);
    t8=buildTree(t9,t10,l8);
    t5=buildTree(NULL,NULL,l5);
    t6=buildTree(NULL,t8,l6);
    t7=buildTree(NULL,NULL,l7);
    t4=buildTree(NULL,t7,l4);
    t2=buildTree(t4,NULL,l2);
    t3=buildTree(t5,t6,l3);
    t1=buildTree(t2,t3,l1);
    printCharTree(t1);
}

