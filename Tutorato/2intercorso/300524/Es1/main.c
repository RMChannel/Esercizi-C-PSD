#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"

void somma(BTree tree, int *s) {
	if(!isEmptyTree(tree)) {
		int *item=(int *)getBTreeRoot(tree);
		(*s)+=*(item);
		somma(getLeft(tree),s);
		somma(getRight(tree),s);
	}
}

void aggiungiNodo(BTree tree, int n) {
	if(isEmptyTree(getLeft(tree))) {
		int *temp=malloc(sizeof(int));
		(*temp)=n;
		BTree bNew=buildTree(NULL,NULL,temp);
		setLeft(tree,bNew);
	}
	else if(isEmptyTree(getRight(tree))) {
		int *temp=malloc(sizeof(int));
		(*temp)=n;
		BTree bNew=buildTree(NULL,NULL,temp);
		setRight(tree,bNew);
	}
	else aggiungiNodo(getLeft(tree),n);
}

int sommaAlberi(BTree tree) {
	int *base=(int *)getBTreeRoot(tree);
	int sl=(*base), sr=(*base);
	somma(getLeft(tree),&sl);
	somma(getRight(tree),&sr);
	if(sl==sr) printf("I DUE ALBERI SONO BILANCIATI\n");
	else if(sl<sr) {
		aggiungiNodo(getLeft(tree),sr-sl);
	}
	else {
		aggiungiNodo(getRight(tree),sr-sl);
	}
}

int main(){
	int n1=1, n2=2, n3=3, n4=4, n5=5, n6=6, n7=7, n8=8, n9=9, n0=0;
	Item item1=&n1, item2=&n2, item3=&n3, item4=&n4, item5=&n5, item6=&n6, item7=&n7, item8=&n8, item9=&n9, item0=&n0;
	//1°ALBERO
	BTree b11=buildTree(NULL,NULL,item3), b12=buildTree(NULL,NULL,item1), b13=buildTree(NULL,NULL,item2), b14=buildTree(b12,b13,item3);
	BTree b15=buildTree(NULL, b11, item1), b16=buildTree(NULL,NULL,item2), b17=buildTree(NULL,NULL,item4), b18=buildTree(NULL,b14,item3);
	BTree b19=buildTree(b15,b16,item9) ,b20=buildTree(b17,b18,item4);
	BTree b111=buildTree(b19,b20,item8);
	sommaAlberi(b111);
	printTree(b111);
	//2°ALBERO
	BTree b21=buildTree(NULL,NULL,item3), b22=buildTree(NULL,b21,item1), b23=buildTree(NULL,NULL,item4), b24=buildTree(NULL,NULL,item1);
	BTree b25=buildTree(b22,NULL,item5), b26=buildTree(b23,b24,item4);
	BTree b27=buildTree(b25,b26,item8);
	sommaAlberi(b27);
	printTree(b27);
	//3°ALBERO
	BTree b31=buildTree(NULL,NULL,item3), b32=buildTree(NULL,NULL,item2);
	BTree b33=buildTree(NULL,b31,item1), b34=buildTree(NULL,NULL,item4), b35=buildTree(NULL,b32,item1);
	BTree b36=buildTree(b33,NULL,item5), b37=buildTree(b34,b35,item4);
	BTree b38=buildTree(b36,b37,item8);
	sommaAlberi(b38);
	printTree(b38);
}