#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "btree.h"

int main(){
    BTree t1,t2,t3,t4,t5,t6,t7,t8,t9;
    int *l1=malloc(sizeof(int));
    int *l2=malloc(sizeof(int));
    int *l3=malloc(sizeof(int));
    int *l4=malloc(sizeof(int));
    int *l5=malloc(sizeof(int));
    int *l6=malloc(sizeof(int));
    int *l7=malloc(sizeof(int));
    int *l8=malloc(sizeof(int));
    int *l9=malloc(sizeof(int));
    (*l1)=8;
    (*l2)=3;
    (*l3)=10;
    (*l4)=1;
    (*l5)=6;
    (*l6)=14;
    (*l7)=4;
    (*l8)=7;
    (*l9)=13;
    t9=buildTree(NULL,NULL,l9);
    t8=buildTree(NULL,NULL,l8);
    t7=buildTree(NULL,NULL,l7);
    t6=buildTree(t9,NULL,l6);
    t5=buildTree(t7,t8,l5);
    t4=buildTree(NULL,NULL,l4);
    t3=buildTree(NULL,t6,l3);
    t2=buildTree(t4,t5,l2);
    t1=buildTree(t2,t3,l1);
    printTree(t1);
    printCharTree(t1);
}

