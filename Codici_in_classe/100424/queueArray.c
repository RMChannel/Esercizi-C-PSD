#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "queue.h"
#define MAXQUEUE 10

struct queue{
    Item items[MAXQUEUE];
    int head;
    int tail;
};

Queue newQueue() {
    Queue queue=malloc(sizeof(struct queue));
    queue->head=0;
    queue->tail=0;
    return queue;
}

int isEmptyQueue(Queue queue) {
    return (queue->head==queue->tail);
}

int enqueue(Queue queue, Item item) {
    if (((queue->tail+1)%MAXQUEUE)==(queue->head)) return 0;
    queue->items[queue->tail]=item;
    queue->tail=(queue->tail+1)%MAXQUEUE;
    return 1;
}

Item dequeue(Queue queue) {
    if (((queue->tail+1)%MAXQUEUE)==(queue->head) || (isEmptyQueue(queue))) return 0;
    queue->head=(queue->head+1)%MAXQUEUE;
}

void printQueue(Queue queue) {
   for (int i=queue->head;i!=(queue->tail);i=(i+1)%MAXQUEUE) {
    outputItem(queue->items[i]);
   }
}
