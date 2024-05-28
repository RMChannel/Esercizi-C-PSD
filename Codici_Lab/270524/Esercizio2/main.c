#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

BTree newRandomTree(int maxh);

/*
Questa funzione si occupa di unire due espressioni, essa prende in input due stringhe che sono due espressioni, un carattere che corrisponde all'operatore e un intero che ci indica
se è il 1°richiamo, se lo è allora non mettiamo le parentesi, altrimenti inseriamo le parentesi all'inizio e alla fine
*/
char *combine(char *s1, char *s2, char *operation, int first) {
	char *s=malloc(sizeof(char)*50); //Mi creo la nuova stringa
	char *sTemp=s; //Creo un puntatore che mi salva il punto di inizio della stringa
	if(first!=0)  { //Controllo se è il 1°richiamo e nel caso non lo è, inserisco la parentesi
		(*s)='(';
		s++;
	}
	while(*s1) { //Mi copio la 1°espressione
		(*s)=(*s1);
		s++;
		s1++;
	}
	(*s)=(*operation); //Metto il simbolo dell'operazione
	s++;
	while(*s2) { //Mi copio la 2°espressione
		(*s)=(*s2);
		s++;
		s2++;
	}
	if(first!=0)  { //Controllo se è il 1°richiamo e nel caso non lo è, inserisco la parentesi
		(*s)=')';
	}
	s++;
	(*s)='\0'; //Aggiungo il carattere di fine stringa
	return sTemp; //Restituisco sTemp e non s perché se no restituirei il puntatore al carattere nullo, invece così restituisco il punto iniziale della stringa
}

char *findExpression(BTree tree, char *s, int n) {
	char *c=getBTreeRoot(tree); //Mi prendo il valore dell'albero
	if(!isEmptyTree(tree)) { //Controllo che l'albero non sia vuoto
		if((*c)=='/' || (*c)=='*' || (*c)=='-' || (*c)=='+') { //Se il nodo contiene un operatore
			char *s1=findExpression(getLeft(tree),s,n+1); //Richiamo la funzione a sinistra con n+1
			char *s2=findExpression(getRight(tree),s,n+1); //Richiamo la funzione a destra con n+1
			s=combine(s1,s2,c,n); //Combino le 2 stringhe create dai richiami ricorsivi
			return s; //Resituisco la stringa risultante
		}
	}
	return c; //Nel caso l'albero sia vuoto o sia una foglia con un numero, restituisco il valore di esso
}

char *callExpression(BTree tree) { //Questa funzione si occupa della creazione della stringa da restituire e di una variabile intera (di cui lo scopo verrà spiegato dopo) e chiama la funzione per calcolare l'espressione per restituirla
	char *s=malloc(sizeof(char)*50);
	int n=0;
	return findExpression(tree,s,n);
}

void printExpression(BTree tree) { //Questa funzione si occupa della stampa, essa prende in input solo l'albero dato
	printf("Albero:\n");
	printTree(tree); //Stampo l'albero
	printf("Espressione: %s\n",callExpression(tree)); //Stampo l'espressione richiamando la funzione
}

int main(){
	srand(time(NULL)); // lasciare questa riga
	BTree bEmpty=newTree(); //Creo l'albero vuoto
	char s2[]="2";
	BTree bTwo=buildTree(NULL,NULL,s2); //Creo l'albero con solo l'elemento 2
	char s31[]="/";
	char s32[]="-"; //Creo il 3°albero con tutti i suoi elementi
	char s33[]="*";
	char s34[]="+";
	char s35[]="1";
	char s36[]="6";
	char s37[]="2";
	char s38[]="11";
	char s39[]="14";
	BTree b39=buildTree(NULL,NULL,s39);
	BTree b38=buildTree(NULL,NULL,s38);
	BTree b37=buildTree(NULL,NULL,s37);
	BTree b36=buildTree(NULL,NULL,s36);
	BTree b35=buildTree(NULL,NULL,s35);
	BTree b34=buildTree(b38,b39,s34);
	BTree b33=buildTree(b36,b37,s33);
	BTree b32=buildTree(b34,b35,s32);
	BTree b31=buildTree(b32,b33,s31);
	BTree RT=newRandomTree(5); //Creo l'albero randomico
	printExpression(bEmpty); //Richiamo la funzione di stampa con ogni albero di test creato
	printExpression(bTwo);
	printExpression(b31);
	printExpression(RT);
}

BTree newRandomTree(int maxh) {
	if(maxh <= 0)
		return NULL;
	BTree left = NULL, right = NULL;
	if(rand() % 3) {
		left = newRandomTree(maxh - 1);
		right = newRandomTree(maxh - 1);
	}
	char *a = calloc(2, sizeof(char));
	char ops[] = {'+', '-', '*', '/'};
	a[0] = left ? ops[rand() % 4] : '0' + rand() % 10;
	return buildTree(left, right, a);
}
