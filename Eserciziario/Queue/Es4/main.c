#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	Queue queue=newQueue();
	int *p1=malloc(sizeof(int));
	int *p2=malloc(sizeof(int));
	int *p3=malloc(sizeof(int));
	(*p1)=1;
	(*p2)=2;
	(*p3)=3;
	enqueue(queue,p1);
	enqueue(queue,p2);
	enqueue(queue,p3);
	printQueue(queue);
	return 0;
}