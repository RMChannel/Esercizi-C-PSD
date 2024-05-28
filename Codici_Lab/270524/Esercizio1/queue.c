#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_QUEUE 100

struct queue {
	int head;
	int tail;
	Item elements[MAX_QUEUE];
};

Queue newQueue(){
	Queue q;
	q = malloc(sizeof(struct queue));
	q->head = 0;
	q->tail = 0;

	return q;
}

int isEmptyQueue(Queue q){
	return q->head == q->tail;
}

int enqueue(Queue q, Item it){
	if((q->tail+1)%MAX_QUEUE == q->head)
		return 0;

	q->elements[q->tail] = it;
	q->tail = (q->tail+1)%MAX_QUEUE;

	return 1;
}

Item dequeue(Queue q){
	if(isEmptyQueue(q))
		return NULL;

	int pos = q->head;
	q->head = (q->head+1)%MAX_QUEUE;

	return q->elements[pos];
}

void printQueue(Queue q) {
	printf("Queue: ");
	int i = q->head;
	for(;i != q->tail;i = (i+1)%MAX_QUEUE)
		outputItem(q->elements[i]);
}
