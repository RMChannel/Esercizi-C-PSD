#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main(int argc, char *argv[]) {
    int *a=malloc(sizeof(int));
	int *b=malloc(sizeof(int));
	int *c=malloc(sizeof(int));
	int *d=malloc(sizeof(int));
	int *e=malloc(sizeof(int));
	*(a)=7;
	*(b)=3;
	*(c)=9;
	*(d)=1;
	*(e)=5;
	BTree at, bt, ct, dt, et;
	et=buildTree(NULL,NULL,e);
	dt=buildTree(NULL,NULL,d);
	ct=buildTree(dt,et,c);
	bt=buildTree(NULL,NULL,b);
	at=buildTree(bt,ct,a);
	printTree(at);
}