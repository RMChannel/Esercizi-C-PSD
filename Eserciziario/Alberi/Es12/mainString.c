#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
#include "stack.h"
#include "btree.h"

int realMaxRoute(BTree t, Stack stack) {
    if(isEmptyTree(getLeft(t)) && isEmptyTree(getRight(t))) return 1;
    else {
        int n1=0;
        int n2=0;
        if(!isEmptyTree(getLeft(t))) n1=realMaxRoute(getLeft(t),stack);
        if(!isEmptyTree(getRight(t))) n2=realMaxRoute(getRight(t),stack);
        if(n1>n2) {
            push(stack,getBTreeRoot(getLeft(t)));
            return n1+1;
        }
        else {
            push(stack,getBTreeRoot(getRight(t)));
            return n2+1;
        }
    }
}

void maxRoute(BTree t) {
    Stack stack=newStack();
    int n=realMaxRoute(t,stack);
    push(stack,getBTreeRoot(t));
    printf("STACK: ");
    for(int i=0;i<n;i++) {
        Item temp=top(stack);
        pop(stack);
        outputItem(temp);
    }
    while(!isEmptyStack(stack)) pop(stack);
    free(stack);
}


int main() {
    char *e0=malloc(sizeof(char)*5);
    char *e1=malloc(sizeof(char)*5);
    char *e2=malloc(sizeof(char)*5);
    char *e3=malloc(sizeof(char)*5);
    char *e4=malloc(sizeof(char)*5);
    char *e5=malloc(sizeof(char)*5);
    char *e6=malloc(sizeof(char)*5);
    char *e7=malloc(sizeof(char)*5);
    char *e8=malloc(sizeof(char)*5);
    char *e9=malloc(sizeof(char)*5);
    strcpy(e0,"A");
    strcpy(e1,"B");
    strcpy(e2,"C");
    strcpy(e3,"D");
    strcpy(e4,"E");
    strcpy(e5,"F");
    strcpy(e6,"G");
    strcpy(e7,"H");
    strcpy(e8,"I");
    strcpy(e9,"L");
    BTree t9=buildTree(NULL,NULL,e9);
    BTree t8=buildTree(NULL,NULL,e8);
    BTree t7=buildTree(NULL,NULL,e6);
    BTree t6=buildTree(t8,t9,e7);
    BTree t5=buildTree(NULL,t6,e4);
    BTree t4=buildTree(NULL,NULL,e5);
    BTree t3=buildTree(NULL,t7,e3);
    BTree t2=buildTree(t4,t5,e2);
    BTree t1=buildTree(t3,NULL,e1);
    BTree t0=buildTree(t1,t2,e0);
    maxRoute(t0);
}

