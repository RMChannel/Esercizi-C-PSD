#include <stdio.h>
#include "btree.h"

/*
Questa funzione ha lo scopo di vedere se l'item dato si trova all'interno dell'albero dato o meno.
Per farlo prende in input un albero e l'item da cercare e restituisce
1 se l'item è stato trovato o 0 se l'item non è presente nell'albero
*/
int searchItem(BTree tree, Item item) {
	int n=0; //Mi creo una variabile dove salverò i risultati delle funzioni
	if(!isEmptyTree(tree)){ //Se l'albero non è vuoto allora faccio i controlli
		if(cmpItem(getBTreeRoot(tree),item)==0) return 1; //Se ho trovato l'item, allora restituisco 1
		n=searchItem(getLeft(tree),item); //Altrimenti cerco a sinistra
		if (n==1) return n; //Se l'ho trovato lì, allora restituisco 1
		n=searchItem(getRight(tree),item); //Se non l'ho trovato ancora, allora cercato a destra
		if (n==1) return n; //Se l'ho trovato allora restituisco 1
	}
	return 0; //Se non l'ho trvato, allora restituisco 0
}

/*
Questa funzione si occupa di ricercare il massimo elemento di un albero.
Prende in input l'albero da cercare un item che corrisponde al massimo corrente e che ogni
volta viene sostituito con l'elemento sempre più grande, fino al massimo
*/
void getMax(BTree tree, Item *item) {
	if(!isEmptyTree(tree)){ //Se l'albero non è vuoto entro
		if(cmpItem(getBTreeRoot(tree),*item)>0) (*item)=getBTreeRoot(tree); //Verifico se l'elemento di quel ramo è più grande dell'attuale massimo, se si lo sostituisco col valore del ramo
		getMax(getLeft(tree),item); //Cerco a sinistra
		getMax(getRight(tree),item); //Cerco a destra
	}
}

/*
Funzione di richiamo per la ricerca del massimo
*/
Item callMax(BTree tree) {
	Item item=getBTreeRoot(tree); //Ci creiamo un item in cui salviamo la radice dell'albero
	getMax(tree,&item); //Richiamo la funzione passandogli l'albero e un item (che corrisponderà al massimo)
	return item; //Restituisco il massim
}

/*
Questa funzione ha lo scopo di controllare che i due alberi passati sono uguali.
Prende in input i due alberi e restituisce 1 se sono uguali e 0 in caso contrario.
*/
int equalTree(BTree tree1, BTree tree2) {
	int n=0; //Mi creo una variabile dove salverò i risultati delle funzioni
	if(!isEmptyTree(tree1) && !isEmptyTree(tree2)){ //Se nessuno dei due rami è vuoto
		if(cmpItem(getBTreeRoot(tree1),getBTreeRoot(tree2))!=0) return 0; //Allora controllo che non siano diversi, se lo sono, allora restituisco 0
		n=equalTree(getLeft(tree1),getLeft(tree2)); //Altrimenti, controllo a sinsistra
		if (n==0) return n; //Se sono diversi restituisco 0
		n=equalTree(getRight(tree1),getRight(tree2)); //Controllo a destra
		if (n==0) return n; //Se sono diversi restituisco 0
	}
	else if(!isEmptyTree(tree1) || !isEmptyTree(tree2)) return 0; //Se uno dei due alberi non è vuoto, ma l'altro si, allora restituisco 0
	else return 1; //In caso contrario, vuol dire che ho fatto tutti i controlli e posso restituire 1
}

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
	Item item=inputItem("l");
    if (searchItem(h,item)) printf("Item trovato\n");
	else printf("Item non trovato\n");
	printf("Massimo: ");
	outputItem(callMax(h));
	if (equalTree(h,h)) printf("\nI due alberi sono uguali\n");
	else printf("\nI due alberi non sono uguali\n");
}