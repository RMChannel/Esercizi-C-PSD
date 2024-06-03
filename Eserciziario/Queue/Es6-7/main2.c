#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

void massimoCoda(Queue queue) {
	Queue queue2=newQueue();
	Item max=dequeue(queue), item;
	enqueue(queue2,max);
	while(!isEmptyQueue(queue)) {
		item=dequeue(queue);
		if(cmpItem(max,item)<0) max=item;
		enqueue(queue2,item);
	}
	while(!isEmptyQueue(queue2)) {
		item=dequeue(queue2);
		if(item!=max) enqueue(queue,item);
	}
	enqueue(queue,max);
}

void minimoCoda(Queue queue) {
	Queue queue2=newQueue();
	Item min=dequeue(queue), item;
	enqueue(queue2,min);
	while(!isEmptyQueue(queue)) {
		item=dequeue(queue);
		if(cmpItem(min,item)>0) min=item;
		enqueue(queue2,item);
	}
	enqueue(queue,min);
	while(!isEmptyQueue(queue2)) {
		item=dequeue(queue2);
		if(item!=min) enqueue(queue,item);
	}
}

int main(){
	Queue queue=newQueue();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	int *p4=malloc(sizeof(int));
	int *p5=malloc(sizeof(int));
	(*p1)=1;
	(*p2)=4;
	(*p3)=5;
	(*p4)=9;
	(*p5)=2;
	enqueue(queue,p1);
	enqueue(queue,p2);
	enqueue(queue,p3);
	enqueue(queue,p4);
	enqueue(queue,p5);
	Queue queue3=cloneQueue(queue);
	printQueue(queue);
	printf("\n");
	massimoCoda(queue);
	printQueue(queue);
	printf("\n");
	minimoCoda(queue3);
	printQueue(queue3);
	printf("\n");
	return 0;
}