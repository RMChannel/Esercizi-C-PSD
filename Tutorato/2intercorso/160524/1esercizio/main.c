#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "list.h"

void calcHeightAndNumNodes(BTree btL, BTree btR, int *a) {
  if (!isEmptyTree(btL) || !isEmptyTree(btR)) {
    a[0]++;
    if (!isEmptyTree(btL)) {
      a[1]++;
      calcHeightAndNumNodes(getLeft(btL),getRight(btL),a);
    }
    if (!isEmptyTree(btR)) {
      a[1]++;
      calcHeightAndNumNodes(getLeft(btR),getRight(btR),a);
    }
  }
}


int *heightAndNumNodes(BTree bt) {
	int *a=malloc(sizeof(int)*2);
  a[0]=-1;
  a[1]=1;
	calcHeightAndNumNodes(getLeft(bt),getRight(bt),a);
	return a;
}

void printHeightNumNodesAndPreorder(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int *hn = heightAndNumNodes(bt);
	if(hn) printf("Altezza albero: %d\nNumero nodi albero: %d\n", hn[0], hn[1]);
	printf("\n\n");
}

int main(){
	BTree tree=newRandomTree(5);
	printHeightNumNodesAndPreorder(tree);
}

