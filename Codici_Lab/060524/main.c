#include <stdio.h>
#include "btree.h"

int main(int argc, char *argv[]) {
    BTree h, a, c, d, l, p, s, o, q;
	d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q"); //Creo l'albero di test
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");
    printf("Altezza: %d\nNumero di nodi: %d\nStampa a livelli: ",Height(h),numberOfNodi(h));
    printLevel(h);
    printf("\nStampa PreOrder iterativa: ");
    preOrderIterative(h);
    printf("\nStampa PostOrder iterativa: ");
	postOrderIterative(h);
	printf("\nStampa Simmetrica iterativa: ");
	SimmetricOrderIterative(h);
	printf("\n");
}