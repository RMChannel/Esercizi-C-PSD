#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "list.h"

int main(){
	BTree tree=newRandomTree(5);
	printTree(tree);
  int *n=malloc(sizeof(int));
  (*n)=3;
  insertNode(tree,n);
  printf("\n\n");
  printTree(tree);
}