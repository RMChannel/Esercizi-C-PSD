#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "btree.h"

int main(){
    BTree t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11;
    int *l1=malloc(sizeof(int));
    int *l2=malloc(sizeof(int));
    int *l3=malloc(sizeof(int));
    int *l4=malloc(sizeof(int));
    int *l5=malloc(sizeof(int));
    int *l6=malloc(sizeof(int));
    int *l7=malloc(sizeof(int));
    int *l8=malloc(sizeof(int));
    int *l9=malloc(sizeof(int));
    int *l10=malloc(sizeof(int));
    int *l11=malloc(sizeof(int));
    (*l1)=50;
    (*l2)=17;
    (*l3)=76;
    (*l4)=9;
    (*l5)=23;
    (*l6)=54;
    (*l7)=14;
    (*l8)=19;
    (*l9)=72;
    (*l10)=12;
    (*l11)=67;
    t11=buildTree(NULL,NULL,l11);
    t10=buildTree(NULL,NULL,l10);
    t9=buildTree(t11,NULL,l9);
    t8=buildTree(NULL,NULL,l8);
    t7=buildTree(t10,NULL,l7);
    t6=buildTree(NULL,t9,l6);
    t5=buildTree(t7,NULL,l5);
    t4=buildTree(NULL,t7,l4);
    t3=buildTree(NULL,t6,l3);
    t2=buildTree(t4,t5,l2);
    t1=buildTree(t2,t3,l1);
    printTree(t1);
    printCharTree(t1);
}

