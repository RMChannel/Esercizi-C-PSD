#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"

int main(){
	BTree t=newTree();
	if(isEmptyTree(t)) printf("L'albero e' vuoto\n");
	Item item=inputItem();
	t=buildTree(NULL,NULL,item);
	if(!isEmptyTree(t)) printf("L'albero non e' vuoto\n");
}

