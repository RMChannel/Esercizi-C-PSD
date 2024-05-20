#include <stdlib.h>
#include "queue.h"
#include "stack.h"

struct queue { //Nella struttura della coda ho solo lo stack
    Stack stack;
};

Queue newQueue() { //Questa funzione mi crea la coda
    Queue queue=malloc(sizeof(queue)); //Alloco la memoria
    queue->stack=newStack(); //Inizializzo lo stack all'interno della coda
    return queue; //Ritorno la coda appena creata
}

int isEmptyQueue(Queue queue) { //Funziona che controlla se la coda è vuota, restituisce 1 se lo è, altrimenti restituisce 0
    return isEmptyStack(queue->stack); //Ritorna il risultato della funzione isEmptyStack dove passiamo lo stack della nostra coda
}

void enQueue(Queue queue, Item item) { //Funzione che aggiunge un elemento alla coda
    push(queue->stack,item); //Faccio la push sullo stack della coda passandogli anche l'item da aggiungere
}

Item deQueue(Queue queue) {//Funzione che elimina un elemento dalla coda
    Stack stack=newStack(); //Mi creo uno stack temporaneo
    Item temp; //Mi creo un elemento temporaneo, che sarà quello da restituire
    while(!isEmptyStack(queue->stack)) { //Finché lo stack della coda non è vuoto
        temp=top(queue->stack); //Mi prendo ogni elemento dello stack
        push(stack,temp); //Lo porto allo stack temporaneo
        pop(queue->stack); //E lo elimino dallo stack originale
    }
    pop(stack); //Elimino l'ultimo elemento aggiunto allo stack temporaneo, che corrisponde all'ultimo dell'elemento dello stack originale e che corrisponde al 1°elemento della coda da eliminare
    while(!isEmptyStack(stack)) { //Ora, finché non svuoto lo stack temporaneo
        Item temp2=top(stack); //Mi recupero ogni elemento dello stack
        push(queue->stack,temp2); //Lo riporto nello stack originale
        pop(stack); //Elimino quell'elemento dallo stack temporaneo
    }
    free(stack); //Elimino dalla memoria lo stack temporaneo
    return temp; //Restituisco l'elemento eliminato
}

void printQueue(Queue queue) { //Funzione che stampa la coda passata
    printStack(queue->stack); //Richiamo la printStack, passandogli lo stack della coda
}