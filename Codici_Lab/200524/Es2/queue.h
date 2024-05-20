#include "item.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
void enQueue(Queue, Item);
Item deQueue(Queue);
void printQueue(Queue);