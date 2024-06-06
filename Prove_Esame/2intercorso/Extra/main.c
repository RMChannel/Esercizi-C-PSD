#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "item.h"

/*
Questa funzione si occupa di trovare il massimo nello Stack dato.
Prende in input solo lo stack e restituisce l'item massimo.
*/
Item maxStack(Stack stack) {
    if(isEmptyStack(stack)) return NULL; //Se lo stack è vuoto, restituisco NULL
    Stack stackT=newStack(); //Mi creo uno stack temporaneo
    Item max=top(stack); //Dichiaro la variabile max al 1°elemento dello stack
    while(!isEmptyStack(stack)) { //Finché lo stack non è vuoto
        Item temp=top(stack); //Mi prendo l'elemento dallo stack
        pop(stack); //Lo rimuovo
        if(cmpItem(temp,max)>0) max=temp; //Se esso è maggiore del massimo, allora assegno a max il valore di temp
        push(stackT,temp); //Inserisco temp nello stack Temporaneo
    }
    //Rimetto tutti i valori nello stack originale
    while(!isEmptyStack(stackT)) { //Finché lo stack temporaneo non è vuoto
        Item temp=top(stackT); //Mi prendo l'elemento dallo stack
        pop(stackT); //Lo rimuovo
        push(stack,temp); //E lo rimetto nello stack originale
    }
    return max; //Ritorno l'item massimo
}

/*
Questa funzione si occupa di trovare il minimo nella coda data.
Prende in input solo la coda e restituisce l'item minimo.
*/
Item minQueue(Queue queue) {
    if(isEmptyQueue(queue)) return NULL; //Se la coda è vuota, restituisco NULL
    Queue queueT=newQueue(); //Mi creo una coda temporanea
    Item min=dequeue(queue); //Dichiaro la variabile min al 1°elemento della coda
    enqueue(queueT,min); //Lo aggiungo alla coda temporanea
    while(!isEmptyQueue(queue)) { //Finché la coda queue non è vuota
        Item temp=dequeue(queue); //Rimuovo l'elemento
        if(cmpItem(temp,min)<0) min=temp; //Controllo che non sia minore del minimo e nel caso lo sostituisco a min
        enqueue(queueT,temp); //Aggiungo alla coda temporanea l'item temp
    }
    //Ripristino la coda originale
    while(!isEmptyQueue(queueT)) { //Finché la coda temporanea non è vuota
        Item temp=dequeue(queueT); //Rimuovo l'elemento
        enqueue(queue,temp); //Lo rimetto nella coda originale
    }
    return min; //Restituisco l'item minimo
}

/*
Questa funzione controlla che il massimo dello stack e il minimo della coda siano uguali.
Prende in input lo stack e la coda da controllare e restituisce 1 se sono uguali o 0 se sono diversi.
*/
int testMaxMin(Stack stack, Queue queue) {
    return minQueue(queue)==maxStack(stack);
}

//Questa funzione si occupa solo della stampa, prende in input lo stack e la coda su cui lavorare
void printEquals(Stack stack, Queue queue) {
    printf("Contenuto originale:\nStack: "); //Stampo il contenuto dello stack e della coda prima di ogni modifica
    printStack(stack);
    printf("Queue: ");
    printQueue(queue);
    if(testMaxMin(stack,queue)) printf("\n*** I valori sono uguali ***\n\n"); //Richiamo la funzione di controllo e stampo a seconda del risultato
    else printf("\n*** I valori NON sono uguali ***\n\n");
}

int main() {
    int*n6=malloc(sizeof(int));
    int*n7=malloc(sizeof(int)); //Creo gli item di test
    int*n8=malloc(sizeof(int));
    int*n9=malloc(sizeof(int));
    int*n10=malloc(sizeof(int));
    (*n6)=6;
    (*n7)=7;
    (*n8)=8;
    (*n9)=9;
    (*n10)=10;
    Stack stack=newStack(); //Creo lo stack di test
    Queue queue=newQueue(); //Creo la coda di test
    Stack stackEmpty=newStack(); //Creo lo stack vuoto
    Queue queueEmpty=newQueue(); //Creo la coda vuota
    push(stack,n10);
    push(stack,n10);
    push(stack,n9);
    push(stack,n9); //Inserisco tutti gli elementi come richiesto dalla traccia
    push(stack,n8);
    enqueue(queue,n10);
    enqueue(queue,n9);
    enqueue(queue,n8);
    enqueue(queue,n7);
    enqueue(queue,n6);  
    printEquals(stackEmpty,queueEmpty); //Richiamo alla funzione printEquals per ogni test richiesto dalla traccia
    printEquals(stack,queueEmpty);
    printEquals(stack,queue);
}