#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	Queue queue=newQueue();
	if(isEmptyQueue(queue)) printf("La lista e' vuota\n");
}