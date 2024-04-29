#include <stdio.h>
#include "item.h"
#include "queue.h"

/*
La complessità asintotica di questa funzione è di O(2n) perché la funzione prima toglie tutti gli elementi dalla coda,
e una volta tolti tutti, vengono rimessi in ordine inverso, quindi ci sono n operazioni quando vengono tolti ed n operazioni
quando vengono rimessi gli elementi.
*/

void reverseQueue(Queue queue) {
    if (isEmptyQueue(queue)) return;
    else {
        Item item=dequeue(queue);
        reverseQueue(queue);
        enqueue(queue,item);
    }
}

int main(int argc, char *argv[]) {
    Item item1=inputItem(4);
    Item item2=inputItem(5);
    Item item3=inputItem(3);
    Item item4=inputItem(1);
    Item item5=inputItem(2);
    Queue queue=newQueue();
    enqueue(queue,item1);
    enqueue(queue,item2);
    enqueue(queue,item3);
    enqueue(queue,item4);
    enqueue(queue,item5); 
    printQueue(queue);
    reverseQueue(queue);
    printf("\n");
    printQueue(queue);
}