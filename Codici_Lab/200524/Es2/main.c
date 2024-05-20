#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() { //Main di test
    Queue queue=newQueue(); //Mi creo la coda
    Item item=inputItem(5); //Mi creo 3 elementi
    Item item2=inputItem(6);
    Item item3=inputItem(7);
    enQueue(queue,item); //Aggiungo gli elementi della coda
    enQueue(queue,item2);
    enQueue(queue,item3);
    printQueue(queue); //Stampo
    printf("\n");
    deQueue(queue); //Rimuovo un elemento dalla coda
    printQueue(queue); //Ristampo
    printf("\n");
}