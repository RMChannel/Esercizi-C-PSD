#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "btree.h"
#include "item.h"
#include "list.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree(){

	return NULL;
}

int isEmptyTree(BTree t){
	if(t==NULL)
		return 1;
	return 0;
}

BTree buildTree(BTree l, BTree r, Item value){
	BTree t=malloc(sizeof(struct node));
	t->left=l;
	t->right=r;
	t->value=value;
	return t;
}

Item getBTreeRoot(BTree t){
	if(!isEmptyTree(t))
		return t->value;
	return NULL;
}

BTree getLeft(BTree t){
	if(!isEmptyTree(t))
		return t->left;
	return NULL;
}

BTree getRight(BTree t){
	if(!isEmptyTree(t))
		return t->right;
	return NULL;

}

BTree newRandomTree(int nNodes) {
	if(nNodes <= 0)
		return NULL;

	srand(time(NULL));

	BTree root = calloc(1, sizeof(struct node));
	root->value = randomItem();

	BTree freeNodes[nNodes];
	int freeSize = 1;
	freeNodes[0] = root;
	for(int i = 1; i < nNodes; i++) {
		BTree node = calloc(1, sizeof(struct node));
		node->value = randomItem();
	
		int r = rand() % freeSize;
		if(freeNodes[r]->left == NULL && freeNodes[r]->right == NULL) {
			if(rand() % 2) {
				freeNodes[r]->left = node;
			} else {
				freeNodes[r]->right = node;
			}
		} else {
			if(freeNodes[r]->right) {
				freeNodes[r]->left = node;
			} else if(freeNodes[r]->left) {
				freeNodes[r]->right = node;
			} else {
				printf("non dovrei mai finire qui\n");
			}

			freeSize--;
			for(int j = freeSize; j > r; j--) {
				freeNodes[j - 1] = freeNodes[j];
			}
		}

		freeNodes[freeSize++] = node;
	}
	return root;
}


void printTree(BTree bt){
	if (isEmptyTree(bt))
		return;

	int height = 0, ndsLastLv = 0, qsize = 0, qsizeNoNulls = 0;

	List items = newList();
	List q = newList();
	addListTail(q, bt);
	qsize++;
	qsizeNoNulls++;
	while(qsizeNoNulls > 0) { 
		for (ndsLastLv = qsize; ndsLastLv > 0; ndsLastLv--) {
			BTree left, right;
			BTree node = removeHead(q);
			qsize--;
			if(node) {
				addListTail(items, node->value);
				qsizeNoNulls--;
			} else {
				addListTail(items, NULL);
			}
			
			left = getLeft(node);
			addListTail(q, left);
			qsize++;
			if(left)
				qsizeNoNulls++;
			
			right = getRight(node);
			addListTail(q, right);
			qsize++;
			if(right)
				qsizeNoNulls++;
		}
		height++;
	}

	int n = sizeList(items);
	if(n == 1) {
		outputItemLen(removeHead(items), 1);
		printf("\n");
		return;
	}
	for(int i = 1, pad = n / 2; i < n; i *= 2, pad /= 2) {
		Item lv[i];
		
		if(i == 1) {
			lv[0] = removeHead(items);
		} else {
			for(int j = 0; j < i; j++) {
				lv[j] = removeHead(items);
				if(lv[j]) {
					printf("%*s", pad, "");
					printf("%c", j % 2 ? '\\' : '/');
					printf("%*s", pad, "");				
				} else {
					printf("%*s", (pad*2)+1, "");
				}
				printf(" ");
			}
			printf("\n");
		}
		
		for(int j = 0; j < i; j++) {
			if(lv[j]) {
				printf("%*s", (pad+1)/2, "");
				for(int k = pad/2; k > 0; k--)
					printf("_");
				outputItemLen(lv[j], 1);
				for(int k = pad/2; k > 0; k--)
					printf("_");
				printf("%*s", (pad+1)/2, "");
			} else {
				printf("%*s", (pad*2)+1, "");
			}
			printf(" ");
		}
		printf("\n");
	}
}

