#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void realSommaNodi(BTree t, int *n) {
    if(!isEmptyTree(t)) { //Se il nodo non è vuoto
        if(isEmptyTree(getLeft(t)) && isEmptyTree(getRight(t))) { //E se il nodo è una foglia
            int *temp=getBTreeRoot(t); //Prendo il valore
            (*n)+=(*temp); //E lo sommo al calcolo
        }
        realSommaNodi(getLeft(t),n); //Vado a sinistra
        realSommaNodi(getRight(t),n); //Vado a destra
    }
}

//Questa è una funzione richiamante per la funzione realSommaNodi
int sommaNodi(BTree t) {
    int n=0; //Inizializzo una variabile n a 0 che corrisponderà alla somma dei nodi foglia dell'albero
    realSommaNodi(t,&n); //1°Chiamata
    return n; //Ritorno il valore calcolato
}

//Questa funzione si occupa solo della stampa
void printAndSum(BTree t) {
    printf("Albero:\n");
    printTree(t); //Stampo l'albero
    printf("Somma nodi foglia: %d\n\n",sommaNodi(t)); //Stampo la somma dei nodi
}

int main(void) {
    BTree t1,t2,t3,t4,t5,tEmpty,tOnlyTwo,tRandom;
    int *n1=malloc(sizeof(int));
    int *n2=malloc(sizeof(int));
    int *n3=malloc(sizeof(int));
    int *n5=malloc(sizeof(int)); //Creo gli item di test
    int *n7=malloc(sizeof(int));
    int *n9=malloc(sizeof(int));
    (*n1)=1;
    (*n2)=2;
    (*n3)=3;
    (*n5)=5;
    (*n7)=7;
    (*n9)=9;
    tEmpty=newTree(); //Albero vuoto
    tOnlyTwo=buildTree(NULL,NULL,n2); //Albero che contiene solo il numero 2
    tRandom=newRandomTree(7); //Albero random di 7 nodi
    t5=buildTree(NULL,NULL,n5);
    t4=buildTree(NULL,NULL,n1);
    t3=buildTree(NULL,NULL,n9); //Creo l'albero di test
    t2=buildTree(t4,t5,n3);
    t1=buildTree(t2,t3,n7);
    printAndSum(tEmpty);
    printAndSum(tOnlyTwo); //Richiamo la funzione di sommaNodi con ogni albero richiesto
    printAndSum(t1);
    printAndSum(tRandom);
}