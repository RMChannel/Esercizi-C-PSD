#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "btree.h"


/*
Questa funzione è la funzione effettiva di controllo, prende in input l'albero da controllare e la variabile di controllo
*/
void realCheckTree(BTree t, int *control) {
    if((*control)==0) return; //Nel caso in cui la variabile di controllo sia stata già impostata a 0, è inutile fare altri controlli
    if(!isEmptyTree(t)) { //Se il nodo non è vuoto
        Item now=getBTreeRoot(t); //Prendo il valore del nodo attuale
        if(!isEmptyTree(getLeft(t))) { //Se il nodo sinistro non è vuoto
            Item left=getBTreeRoot(getLeft(t)); //Prendo il valore del nodo sinistro
            if(cmpItem(now,left)<0) (*control)=0; //Controllo che il valore del nodo attuale sia maggiore di quel nodo sinistro, in caso contrario control viene impostato a 0
            else realCheckTree(getLeft(t),control); //In caso contrario si continuano i controlli a destra
        }
        if(!isEmptyTree(getRight(t))) { //Se il nodo destro non è vuoto
            Item right=getBTreeRoot(getRight(t)); //Prendo il valore del nodo destro
            if(cmpItem(now,right)>0) (*control)=0; //Controllo che il valore del nodo attuale sia maggiore di quel nodo sinistro, in caso contrario control viene impostato a 0
            else realCheckTree(getRight(t),control); //In caso contrario si continuano i controlli a destra
        }
    }
}

/*
Questa funzione è funzione richiamante, essa infatti prende in input solo l'albero da controollare e richiama la funzione di controllo effettivo-
*/
int checkTree(BTree t) {
    int control=1; //Mi creo una variabile di controllo
    realCheckTree(t,&control); //Richiamo la funzione di controllo
    return control; //Ritorno il valore di controllo
}

/*
Questa funzione stampa l'albero da controllare e controlla e stampa se l'albero sia bilanciato o meno.
Essa prende in input solo l'albero da stampare e controllare.
*/
void printTreeControl(BTree t) {
    printf("Albero:\n");
    printTree(t); //Stampo l'albero
    printf("checkTree: "); //Stampo se l'albero è bilanciato o meno
    if (checkTree(t)) printf("true\n\n");
    else printf("false\n\n");
}

int main(){
    BTree t0=newTree(); //Creo e testo l'albero vuoto
    printTreeControl(t0);
    int *i1=malloc(sizeof(int));
    int *i2=malloc(sizeof(int));
    int *i3=malloc(sizeof(int));
    int *i5=malloc(sizeof(int));
    int *i7=malloc(sizeof(int));
    int *i9=malloc(sizeof(int));
    (*i1)=1;
    (*i2)=2;
    (*i3)=3;
    (*i5)=5; //Creo gli item di test
    (*i7)=7;
    (*i9)=9;
    BTree t01=buildTree(NULL,NULL,i2);
    printTreeControl(t01); //Creo e testo l'albero formato solo dal nodo 2
    BTree t15=buildTree(NULL,NULL,i5);
    BTree t14=buildTree(NULL,NULL,i1);
    BTree t13=buildTree(NULL,NULL,i9); //Creo l'albero di test
    BTree t12=buildTree(t14,t15,i3);
    BTree t11=buildTree(t12,t13,i7);
    printTreeControl(t11); //Lo controllo
    BTree t1r=newRandomTree(5); //Creo e controllo l'albero random di 5 nodi
    printTreeControl(t1r);
    BTree t2r=newRandomTree(7); //Creo e controllo l'albero random di 7 nodi
    printTreeControl(t2r);
}

