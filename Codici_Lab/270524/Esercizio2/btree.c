#include "btree.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  Item value;
  struct node* left;
  struct node* right;
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree tree){
  if(tree==NULL)
    return 1;
  else
    return 0;
}

BTree buildTree(BTree left, BTree right, Item i){
  BTree tree=malloc(sizeof(struct node));
  tree->left=left;
  tree->right=right;
  tree->value=i;
  return tree;
}

Item getBTreeRoot(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->value;
}

BTree getLeft(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->left;
}

BTree getRight(BTree tree){
  if(isEmptyTree(tree))
    return NULL;
  else
    return tree->right;
}

void preOrder(BTree tree){
  if(!isEmptyTree(tree)){
    outputItem(tree->value);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void postOrder(BTree tree){
  if(!isEmptyTree(tree)){
    postOrder(tree->left);
    postOrder(tree->right);
    outputItem(tree->value);
  }
}

void inOrder(BTree tree){
  if(!isEmptyTree(tree)){
    inOrder(tree->left);
    outputItem(tree->value);
    inOrder(tree->right);
  }
}

// not in btree.h
int tta(BTree b, int p, char **a, int h, int *ml) {
	if(isEmptyTree(b)) return h;
	a[p] = itemToString(b->value);
	int l = strlen(a[p]);
	if(l > *ml) *ml = l;
	int lh = tta(b->left, 2 * p + 1, a, h + 1, ml);
	int rh = tta(b->right, 2 * p + 2, a, h + 1, ml);
	return lh > rh ? lh : rh;
}

// not in btree.h
void prt(char *a, int sp, char cfl, char cfr) {
	if(a) {
		int l = sp - strlen(a);
		int ll = l / 2, lr = (l + 1) / 2;
		if(cfl) {
			for(int k = ll / 2; k >= 0; k--) putchar(' ');
			for(int k = (ll + 1) / 2; k > 1; k--) putchar(cfl);
		} else {
			for(int k = ll; k > 0; k--) putchar(' ');
		}
		fputs(a, stdout);
		if(cfr) {
			for(int k = (lr + 1) / 2; k > 1; k--) putchar(cfr);
			for(int k = lr / 2; k >= 0; k--) putchar(' ');
		} else {
			for(int k = lr; k > 0; k--) putchar(' ');
		}
	} else {
		for(int k = sp; k > 0; k--) putchar(' ');
	}
}

void printTree(BTree btree) {
	char *a[1023] = {0};
	int ml = 0;
	int h = tta(btree, 0, a, 0, &ml);

	for(int i = 0; i < h; i++) {
		int sp = (ml + 1) * (1 << ((h - 1) - i)), s = (1 << i) - 1, e = (2 << i) - 1;
		if(i) {
			for(int j = s; j < e; j++) {
				prt(a[j] ? (j % 2 ? "/" : "\\") : " ", sp, 0, 0);
			}
			putchar('\n');
		}
		for(int j = s; j < e; j++) {
			if(i < h - 1)
				prt(a[j], sp, a[(2 * j) + 1] ? '_' : 0, a[(2 * j) + 2] ? '_' : 0);
			else
				prt(a[j], sp, 0, 0);
		}
		putchar('\n');
	}
}
