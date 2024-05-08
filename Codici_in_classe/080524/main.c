#include <stdio.h>
#include "bst.h"
#include "item.h"

int main(){
	BST tree=newBST();
	int test=70;
	int elements[]={20,10,30,5,15,25,40,3,6,13,35};
	for(int i=0;i<11;i++) {
		insertBST(&tree,&elements[i]);
	}
	printf("Min= ");
	outputItem(min(tree));
	printf("\nMax= ");
	outputItem(max(tree));
	printf("\n");
	if(search(tree,&tree)==NULL) printf("Non presente\n");
	else printf("Presente\n");
	printLevel(tree);
	printf("\n");
}