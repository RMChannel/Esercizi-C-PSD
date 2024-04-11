#include <stdio.h>
#include "btree.h"

// scrivere *in questo file*:
// - heightAndNumNodes
// - preorder

void printHeightNumNodesAndPreorder(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int *hn = heightAndNumNodes(bt);
	if(hn) printf("Altezza albero: %d\nNumero nodi albero: %d\n", hn[0], hn[1]);
	printf("Visita preorder iterativa: ");
	preorder(bt);
	printf("\n\n");
}

int main(){
	// printHeightNumNodesAndPreorder(aTree);
	// da scrivere
}

