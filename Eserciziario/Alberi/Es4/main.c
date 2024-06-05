#include <stdio.h>
#include <stdlib.h>
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
    int *lt=malloc(sizeof(int));
    (*l1)=17;
    (*l2)=10;
    (*l3)=21;
    (*l4)=5;
    (*l5)=13;
    (*l6)=20;
    (*l7)=33;
    (*l8)=2;
    (*l9)=7;
    (*lt)=9;
    t5=buildTree(NULL,NULL,l5);
    t6=buildTree(NULL,NULL,l6);
    t7=buildTree(NULL,NULL,l7);
    t8=buildTree(NULL,NULL,l8);
    t9=buildTree(NULL,NULL,l9);
    t4=buildTree(t8,t9,l4);
    t2=buildTree(t4,t5,l2);
    t3=buildTree(t6,t7,l3);
    t1=buildTree(t2,t3,l1);
    printTree(t1);
    insertNode(t1,lt);
    printTree(t1);
}

