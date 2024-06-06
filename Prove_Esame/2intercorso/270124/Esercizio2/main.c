#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "list.h"

void preOrderIterative(BTree t) {
    List list=newList(); //Mi creo 2 liste, una sarà quella che tiene conto di ogni mio passaggio
    List printed=newList(); //L'altra salva tutti gli elementi che sono stati già stampati
    BTree tw=t; //Nodo su cui lavoro
    if(isEmptyTree(t)) return;
    do {
       if(searchListItem(printed,tw)==NULL) { //Se il nodo non è stato stampato
            outputItem(getBTreeRoot(tw)); //Stampo
            addHead(printed,tw); //Aggiungo alla lista dei stampati
            if(!isEmptyTree(getLeft(tw)) && searchListItem(printed,getLeft(tw))==NULL) { //Se il nodo sinistro non è stato stampato e non è vuoto, allora
                addHead(list,tw); //Aggiungo il nodo attuale alla lista dei passaggi
                tw=getLeft(tw); //Lo sostituisco col nodo sinistro
            }
            else if(!isEmptyTree(getRight(tw)) && searchListItem(printed,getRight(tw))==NULL) { //Se il nodo destro non è stato stampato e non è vuoto, allora
                addHead(list,tw); //Aggiungo alla lista dei passaggi
                tw=getRight(tw); //Vado a destra
            }
       }
       else { //Nel caso in cui l'elemento sia stato già stampato
            tw=removeHead(list); //Torno indietro sulla lista dei passaggi
            if(!isEmptyTree(getRight(tw)) && searchListItem(printed,getRight(tw))==NULL) { //Se il nodo destro non è stato stampato e non è vuoto, allora
                addHead(list,tw); //Aggiungo alla lista dei passaggi
                tw=getRight(tw); //Vado a destra
            }
       }
    } while(!isEmpty(list)); //Ciclo finché la lista dei passaggi non è vuota
}

void inOrderIterative(BTree t) {
    List list=newList();
    List control=newList();
    addHead(control,t);
    BTree tw;
    do {
        tw=removeHead(control);
        addListTail(list,getBTreeRoot(tw));
        if(!isEmptyTree(getLeft(tw))) addListTail(control,getLeft(tw));
        if(!isEmptyTree(getRight(tw))) addListTail(control,getRight(tw));
    } while(!isEmpty(control));
    printList(list);
}


/*
Questa funzione si occupa dell'effettivo calcolo dell'altezza e del numero di nodi.
Prende in input l'array su cui salvare i risultati e il nodo sinistro e il nodo destro del nodo principale.
*/
void calcHeightAndNumNodes(int *a, BTree tL, BTree tR, int n) {
    if(!isEmptyTree(tL) || !isEmptyTree(tR)) { //Se o il nodo sinistro o quello destro non è vuoto
        if(!isEmptyTree(tL)) { //Se quello sinistro non è vuoto
            a[1]++; //Incremento il numero di nodi
            calcHeightAndNumNodes(a,getLeft(tL),getRight(tL),n+1); //Richiamo al nodo sinistro e destro del nodo sinistro
        }
        if(!isEmptyTree(tR)) {
            a[1]++; //Incremento il numero di nodi
            calcHeightAndNumNodes(a,getLeft(tR),getRight(tR),n+1); //Richiamo al nodo sinistro e destro del nodo destro
        }
    }
    else a[0]=n; //Quando arriviamo alla foglia, vuol dire che potenzialmente siamo al nodo che termina l'altezza dell'albero, quindi ci salviamo quella calcolata fin'ora (se ci sarà un altro caso e che quindi quest'altezza salvata non è quella effettiva, allora essa verrà automaticamente sostituita dalla prossima chiamata ricorsiva)
}

/*
Questa funzione si occupa di creare un array di 2 elementi, dove il 1°corrisponde all'altezza e il 2° al numero di nodi e richiamare la funzione che li calcola
Prende in input solo l'albero su cui lavorare e restituisce l'array che ho descritto prima.
*/
int *heightAndNumNodes(BTree t) {
    int *result=malloc(sizeof(int)*2); //Creo l'array
    result[0]=0;
    if(isEmptyTree(t)) result[1]=0;//Inizializzzo a 0 nel caso in cui l'albero sia vuoto
    else result[1]=1; //In caso contrario ad 1 (perché saltiamo il 1°nodo)
    calcHeightAndNumNodes(result, getLeft(t), getRight(t),0); //Richiamo la funzione di calcolo
    return result; //Restituisco il risultato
}
/*
Questa funzione si occupa della stampa dell'albero, dell'altezza e del numero di nodi.
Prende in input solo l'albero da esaminare.
*/
void printHeightAndNumNodes(BTree t) {
    printf("Albero:\n");
    printTree(t);
    preOrderIterative(t);
    int *a=heightAndNumNodes(t); //Mi prendo i valori dell'altezza e del numero dei nodi
    printf("\nAltezza albero: %d\nNumero dei nodi %d\n\n",a[0],a[1]); //E li stampo
}

int main() {
    BTree t5,t4,t3,t2,t1,tEmpty,tOnlyTwo,tRandom;
    int *n1=malloc(sizeof(int));
    int *n2=malloc(sizeof(int));
    int *n3=malloc(sizeof(int));
    int *n5=malloc(sizeof(int));
    int *n7=malloc(sizeof(int)); //Creo gli item di test
    int *n9=malloc(sizeof(int));
    (*n1)=1;
    (*n2)=2;
    (*n3)=3;
    (*n5)=5;
    (*n7)=7;
    (*n9)=9;
    t5=buildTree(NULL,NULL,n5);
    t4=buildTree(NULL,NULL,n1);
    t3=buildTree(t4,t5,n9);
    t2=buildTree(NULL,NULL,n3); //Creo l'albero di test
    t1=buildTree(t2,t3,n7);
    tEmpty=newTree(); //Creo l'albero vuoto
    tOnlyTwo=buildTree(NULL,NULL,n2); //Creo l'albero contenente solo l'elemento 2
    tRandom=newRandomTree(8); //Creo l'albero contenente 8 elementi randomici
    printHeightAndNumNodes(tEmpty);
    printHeightAndNumNodes(tOnlyTwo); //Richiamo alle funzioni con ogni tipo di albero richiesot
    printHeightAndNumNodes(t1);
    printHeightAndNumNodes(tRandom);
}