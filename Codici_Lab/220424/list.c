#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"
#define FALSE 0
#define TRUE 1


struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};


List newList(){
    List list=malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    return list;
}

int isEmpty(List list){
    return list->size==0;
}

void addHead(List list, Item item){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list){
    if (isEmpty (list)) return NULL;
    struct node *temp= list->head;
    list->head = temp->next;
    Item item = temp->value;
    free (temp);
    list->size--;
    return item;
}

int sizeList(List list) {
    return list->size;
}

void printItem(struct node *nodo) {
    if(nodo==NULL) return; //Se ho raggiunto il nodo finale, allora ritorno NULL
    else { //altrimenti stampo il nodo attualmente preso e chiamo la funzione di stampa passandogli il nodo successivo
        outputItem(nodo->value);
        return printItem(nodo->next);
    }
}

void printListRec(List list) {
    printItem(list->head); //Chiamo la prima stampa
}

Item searchItem(struct node *nodo, Item item, int *pos) {
    if(cmpItem(item,nodo->value)) return nodo->value; //Controllo se ho trovato l'elemento da cercare, se si lo ritorno 
    else if(nodo==NULL) { //Altrimenti se ho raggiunto la fine della lista, senza aver trovato l'elemento, allora inizializzo pos a -1 e restituisco NULL
        (*pos)=-1;
        return NULL;
    }
    else { //Altrimenti incremento pos, visto che sto andando avanti nella lista e faccio il return del richiamo della funzione, però passandogli il nodo successivo
        (*pos)++;
        return searchItem(nodo->next,item,pos);
    }
}

Item searchListRec(List list, Item item, int *pos) {
    return searchItem(list->head,item,pos); //Chiamo il primo controllo
}

void countItem(struct node *nodo, int *n, Item item) {
    if (nodo==NULL) return; //Se ho raggiunto la fine della lista, termino la ricorsione
    else if(cmpItem(nodo->value,item)) (*n)++; //Se ho trovato l'elemento che sto contando, incremento n
    return countItem(nodo->next,n,item); //Vado al prossimo elemento da verificare, chiamando la stessa funzione però passandogli il nodo successivo
}

int countItemListRec(List list, Item item) {
    int n=0;
    countItem(list->head,&n,item); //Chiamo il primo controllo inizializzando n
    return n;
}

void destroyNode(struct node *nodo) {
    if(nodo==NULL) { //Se il nodo è NULL, vuol dire che ho raggiunto l'ultimo nodo e posso termianre il ciclo di distruzione
        free(nodo);
        return;
    } 
    else {
        struct node *temp=nodo->next; //Altrimenti, mi salvo in temp il nodo successivo
        free(nodo); //Libero il nodo attualmente preso
        return destroyNode(temp); //E passo alla prossima chiamata di distruzione, passandogli il nodo temp
    }
}

void destroyListRec(List list) {
    destroyNode(list->head); //Faccio la prima chiamata
    free(list); //Libero la lista
}