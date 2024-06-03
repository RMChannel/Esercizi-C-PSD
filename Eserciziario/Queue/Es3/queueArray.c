#include <stdlib.h>
#include "queue.h"
#define MAXQUEUE 10

struct queue{
    Item items[MAXQUEUE];
    int head;
	int tail;
};

Queue newQueue(){
    Queue q=malloc(sizeof(struct queue));
    q->head=0;
	q->tail=0;
	
    return q;
} 

int isEmptyQueue(Queue queue){
    if(queue->head==queue->tail)
        return 1;
    else
        return 0;
}

int enqueue(Queue queue, Item item){
    if((queue->tail+1)%MAXQUEUE==queue->head) //test se la coda è piena
        return 0;
    
    queue->items[queue->tail]=item;
    queue->tail=(queue->tail+1)%MAXQUEUE; //incremento
    
    return 1;
}

Item dequeue(Queue queue){
    if(isEmptyQueue(queue))
        return NULL;
	Item temp=queue->items[queue->head];
	
    queue->head=(queue->head+1)%MAXQUEUE;
	
    return temp;
}


void printQueue(Queue queue){
    for(int i=queue->head; i!=queue->tail; i=(i+1)%MAXQUEUE)
        outputItem(queue->items[i]);
    
}

Queue cloneQueue(Queue queue) {
    Queue queue2=newQueue();
    Item item;
    for(int i=queue->head;i<(queue->tail);i++) {
        item=queue->items[i];
        enqueue(queue2,item);
    }
    return queue2;
}