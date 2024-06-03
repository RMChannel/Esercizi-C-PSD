#include <stdlib.h>
#include "list.h"
#include "queue.h"

struct queue{
    List items;
};

Queue newQueue(){
	Queue queue=malloc(sizeof(struct queue));
	queue->items=newList();
	
	return queue;
}

int isEmptyQueue(Queue queue){
	return isEmpty(queue->items);
}

int enqueue(Queue queue, Item item){
	return addListTail(queue->items, item);
}

Item dequeue(Queue queue){
	return removeHead(queue->items);
}

void printQueue(Queue queue){
	printList(queue->items);
}

Queue cloneQueue(Queue queue) {
	Queue queue2=newQueue();
	Item item;
	for(int i=0;i<sizeList(queue->items);i++) {
		item=dequeue(queue);
		enqueue(queue,item);
		enqueue(queue2,item);
	}
	return queue2;
}