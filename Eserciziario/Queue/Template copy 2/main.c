#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	Queue queue=newQueue();

	for (int i=0; i<5; i++){
		Item item = inputItem();
		enqueue(queue, item);

		printf("\nqueue: ");
		printQueue(queue);
	}

	for (int i=0; i<6; i++){
		printf("stiamo eliminando: ");

		Item item=dequeue(queue);
		if(item != NULL)
			outputItem(item);


		printf("\nqueue: ");
		printQueue(queue);
	}

	return 0;
}