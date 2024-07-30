#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"
#include "stack.h"

int searchRoute(BTree t, Stack stack) {
    if(isEmptyTree(getLeft(t)) && isEmptyTree(getRight(t))) {
        return 1;
    }
    else {
        int n1=1000;
        int n2=1000;
        if(!isEmptyTree(getLeft(t))) n1=searchRoute(getLeft(t),stack);
        if(!isEmptyTree(getRight(t))) n2=searchRoute(getRight(t),stack);
        if(n1<n2) {
            return n1+1;
        }
        else {
            return n2+1;
        }
    }
}

void realMinRoute(BTree t, Stack stack) {
    int n1=1000;
    int n2=1000;
    if(!isEmptyTree(getLeft(t))) n1=searchRoute(getLeft(t),stack);
    if(!isEmptyTree(getRight(t))) n2=searchRoute(getRight(t),stack);
    if(n1==1000 && n2==1000) return;
    else if(n1<n2) {
        realMinRoute(getLeft(t),stack);
        push(stack,getBTreeRoot(getLeft(t)));
    }
    else {
        realMinRoute(getRight(t),stack);
        push(stack,getBTreeRoot(getRight(t)));
    }
}

void minRoute(BTree t) {
    Stack stack=newStack();
    realMinRoute(t,stack);
    push(stack,getBTreeRoot(t));
    printf("Stack: ");
    printStack(stack);
    printf("\n");
}

int main(){ //NON METTO TUTTI GLI ALBERI PERCHE' NON HO VOGLIA, MA FUNZIONA
    int *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11, *n12, *n13, *n14;
    n1=malloc(sizeof(int));
    n2=malloc(sizeof(int));
    n3=malloc(sizeof(int));
    n4=malloc(sizeof(int));
    n5=malloc(sizeof(int));
    n6=malloc(sizeof(int));
    n7=malloc(sizeof(int));
    n8=malloc(sizeof(int));
    n9=malloc(sizeof(int));
    n10=malloc(sizeof(int));
    n11=malloc(sizeof(int));
    n12=malloc(sizeof(int));
    n13=malloc(sizeof(int));
    n14=malloc(sizeof(int));
    *(n1)=1;
    *(n2)=2;
    *(n3)=3;
    *(n4)=4;
    *(n5)=5;
    *(n6)=6;
    *(n7)=7;
    *(n8)=8;
    *(n9)=9;
    *(n10)=10;
    *(n11)=11;
    *(n12)=12;
    *(n13)=13;
    *(n14)=14;
    BTree t9=buildTree(NULL,NULL,n13);
    BTree t8=buildTree(NULL,NULL,n7);
    BTree t7=buildTree(NULL,NULL,n4);
    BTree t6=buildTree(NULL,NULL,n1);
    BTree t5=buildTree(t7,t8,n6);
    BTree t4=buildTree(t9,NULL,n14);
    BTree t3=buildTree(NULL,t4,n10);
    BTree t2=buildTree(t6,t5,n3);
    BTree t1=buildTree(t2,t3,n8);
    printTree(t1);
    minRoute(t1);
}