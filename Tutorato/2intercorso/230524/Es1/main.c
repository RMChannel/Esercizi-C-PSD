#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"


int calcolaHeight(BTree tree, int n) {
	if (!isEmptyTree(tree)) {
		int left=calcolaHeight(getLeft(tree),n+1);
		int right=calcolaHeight(getRight(tree),n+1);
		if(left>right) return left;
		else return right;
	}
	else return n;
}

int height(BTree tree) {
	int n=-1;
	return calcolaHeight(tree,n);
}

void sommaPerLivelli(BTree treeL,BTree treeR,int *somma) {
	if (!isEmptyTree(treeL) || !isEmptyTree(treeR)) {
		if (!isEmptyTree(treeL)) {
			int *n=getBTreeRoot(treeL);
			(*somma)+=(*n);
			sommaPerLivelli(getLeft(treeL),getRight(treeL),somma+1);
		}
		if (!isEmptyTree(treeR)) {
			int *n=getBTreeRoot(treeR);
			(*somma)+=(*n);
			sommaPerLivelli(getLeft(treeR),getRight(treeR),somma+1);
		}
	}
}

int *sumByLevel(BTree tree) {
	int *somma=calloc(height(tree)+1,sizeof(int));
	int *radice=getBTreeRoot(tree);
	(*somma)=(*radice);
	sommaPerLivelli(getLeft(tree),getRight(tree),somma+1);
	return somma;
}

void maxCammino(BTree tree) {
	if(!isEmptyTree(tree)) {
		outputItem(getBTreeRoot(tree));
		int left=height(getLeft(tree));
		int right=height(getRight(tree));
		if (left>right) maxCammino(getLeft(tree));
		else maxCammino(getRight(tree));
	}
}

void minCammino(BTree tree) {
	if(!isEmptyTree(tree)) {
		outputItem(getBTreeRoot(tree));
		int left=height(getLeft(tree));
		int right=height(getRight(tree));
		if (left<right && !isEmptyTree(getLeft(tree))) minCammino(getLeft(tree));
		else if (!isEmptyTree(getRight(tree))) minCammino(getRight(tree));
		else  minCammino(getLeft(tree));
	}
}

void printHeightAndSumByLevel(BTree tree) {
	printTree(tree);
	int altezza=height(tree);
	printf("Altezza albero: %d\n",altezza);
	printf("Somma di ogni livello:\n");
	int *sum=sumByLevel(tree);
	for(int i=0;i<altezza+1;i++) printf("[%d]: %d\n",i+1,sum[i]);
	printf("Cammino max: ");
	maxCammino(tree);
	printf("\nCammino min: ");
	minCammino(tree);
	printf("\n");
}

int main(){
	BTree tree1=newTree();
	int *nT2=malloc(sizeof(int));
	*(nT2)=2;
	BTree tree2=buildTree(NULL,NULL,nT2);
	BTree T1,T2,T3,T4,T5,TRandom;
	int *n1=malloc(sizeof(int));
	int *n2=malloc(sizeof(int));
	int *n3=malloc(sizeof(int));
	int *n4=malloc(sizeof(int));
	int *n5=malloc(sizeof(int));
	*(n1)=7;
	*(n2)=3;
	*(n3)=9;
	*(n4)=1;
	*(n5)=5;
	T5=buildTree(NULL,NULL,n5);
	T4=buildTree(NULL,NULL,n4);
	T3=buildTree(NULL,NULL,n3);
	T2=buildTree(T4,T5,n2);
	T1=buildTree(T2,T3,n1);
	TRandom=newRandomTree(7);
	printHeightAndSumByLevel(TRandom);
}

