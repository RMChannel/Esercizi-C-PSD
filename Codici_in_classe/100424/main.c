#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	Queue queue=newQueue();
	Item test;
	for (int i=0;i<2;i++) {
		test=inputItem();
		enqueue(queue,test);
	}
	printQueue(queue);
	dequeue(queue);
	printQueue(queue);
}